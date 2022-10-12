#include "Assembler.h"

Map* Map::instance=0;
OPERATIONS::OPERATIONS()
{
	// Many R type operations i.e. add sub or and
	// sll slt sltu xor srl sra have the same opcodes
	opcode={
		// R- Type
		{"add", 0b0110011},
		{"sub", 0b0110011},
		{"or", 0b0110011},
		{"and", 0b0110011},
		
		// I - Type
		{"lw", 0b0000011},

		// S - Type
		{"sw", 0b0100011}
	};

	funct3={
		// R - Type
		{"add", 0b000},
		{"sub", 0b000},
		{"or", 0b110},
		{"and", 0b111},

		// I - Type
		{"lw", 0b010},

		// S -Type
		{"sw", 0b010}
	};

	funct7={
		// R - Type
		{"add", 0b0000000},
		{"sub", 0b0100000},
		{"or", 0b0000000},
		{"and", 0b0000000},
	};
	
	uid={

	};

	type={
		// R - Type
		{"add", 'R'},
		{"or", 'R'},
		{"and", 'R'},

		// I - Type
		{"lw", 'I'},

		// S -Type
		{"sw", 'S'}
	};
}
REGISTERS::REGISTERS()
{
	regcode={
		{"pc", -1},
	};
	regex_reg="[x]\\d{1,2}";
	regex_reg_imm="(\\d)+\\([x]\\d{1,2}\\)";
}
Map::Map()
{
	registers=new REGISTERS();
	operations=new OPERATIONS();
}
Map* Map::getInstance()
{
	if(instance==NULL)
		instance=new Map();
	return instance;
}
REGISTERS* Map::getRegisters()
{
	return registers;
}
OPERATIONS* Map::getOperations()
{
	return operations;
}

vector<int> REGISTERS::extractRegisters(string reg, unsigned char type)
{
	try
	{
		char reg_code;
		regex regexp(regex_reg);
		sregex_iterator next(reg.begin(), reg.end(), regexp);
		sregex_iterator end;
		vector<int> regs(3, -1);
		int i=0;

		while(next!=end)
		{
			smatch match = *next;
			reg=match.str();
			
			if(regcode.find(reg) != regcode.end())
			{
				perror("Invalid Register Type");
				regs.resize(i);
				return regs;
			}

			reg_code=stoi(reg.substr(1, 2));
			if(!(reg_code>=0 && reg_code<32))
			{
				perror("Invalid Register Number");
				reg.resize(i);
				return regs;
			}
			regs[i++]=reg_code;
			next++;
		}
		regs.resize(i);
		return regs;
	}
	catch (const regex_error& e)
	{
    	perror("Invalid Syntax");
		return vector<int> (1, -1);
	}
}
int REGISTERS::extractImmediate(vector<int> &regs, string reg, unsigned char type)
{
	try
	{
		regex regexp(regex_reg_imm);
		sregex_iterator next(reg.begin(), reg.end(), regexp);
		sregex_iterator end;
		
		smatch match = *next;
		string imm_reg=match.str();
		
		int immediate=stoi(imm_reg.substr(0, imm_reg.find('(')));

		regs.resize(regs.size()+1, immediate);
		next++;
		
		if(next != end)
		{
			perror("Invalid Syntax");
			reg.resize(regs.size()-1);
			return 1;
		}
	}
	catch (const regex_error& e)
	{
    	perror("Invalid Syntax");
		return 2;
	}
	return 0;
}

vector<int> REGISTERS::matchReg(string reg, unsigned char type)
{
	vector<int> regs=extractRegisters(reg, type);
	if(type == 'I' || type=='S')
		extractImmediate(regs, reg, type);
	return regs;	
}
int REGISTERS::setRegCode(int &ins, string reg, unsigned char type)
{
	// pc is -1 and x0 to x31 is 0 to 31
	char reg_code;
	vector<int> regs=matchReg(reg, type);
	
	if(type=='R')
	{
		if(regs.size() != 3)
		{
			perror("Invalid Syntax");
			return 1;
		}
		// reg[0] is destination reg[1] and reg[2] are source
		// reg[0] should not be x0 
		if(regs[0]==0)
		{
			perror("Invalid Destination Register");
			return 2;
		}
		
		// rd
		ins=ins|(regs[0]<<7);
		// rs1
		ins=ins|(regs[1]<<15);
		// rs2
		ins=ins|(regs[2]<<20);
	}
	else if(type=='I')
	{
		if(regs.size() != 3)
		{
			perror("Invalid Syntax");
			return 1;
		}
		// reg[0] is destination reg[1] is source
		// reg[0] should not be x0 
		// reg[2] has the immediate value
		if(regs[0]==0)
		{
			perror("Invalid Destination Register");
			return 2;
		}
		
		// rd
		ins=ins|(regs[0]<<7);
		// rs1
		ins=ins|(regs[1]<<15);
		// imm
		ins=ins|(regs[2]<<20);
	}
	else if(type=='S')
	{
		if(regs.size() != 3)
		{
			perror("Invalid Syntax");
			return 1;
		}
		// reg[0] is source(rs2) reg[1] is source(rs1)
		// reg[2] has the immediate value
		
		// rs1
		ins=ins|(regs[1]<<15);
		// rs2
		ins=ins|(regs[0]<<20);
		// imm
		// imm is split into 2 segments
		// first 5 bits from LSB - starting at index 7 of ins 
		// remaining 7 bits - starting at index 25 of ins
		ins=ins|((regs[2]&31)<<7);
		ins=ins|((regs[2]&4064)>>5<<25);
	}
	return 0;
}
unsigned char OPERATIONS::setIns(int &ins, string op)
{
	if(opcode.find(op) == opcode.end())
	{
		perror("Invalid Operation");
		return '\0';
	}
	if(uid.find(op) != uid.end())
		ins=ins|uid[op];
	else
	{
		ins=ins|opcode[op];
		if(funct3.find(op) != opcode.end())
			ins=ins|(funct3[op]<<12);
		if(funct7.find(op) != opcode.end())
			ins=ins|(funct7[op]<<25);
		uid[op]=ins;
	}
	return type[op];
}
ST_Entry::ST_Entry()
{}
ST_Entry::ST_Entry(int type, int value)
{
	ST_Entry::type=type;
	ST_Entry::value=value;
}
void ST_Entry::ST_Print()
{
	cout<<"Type : ";
	if(type==0)
		cout<<"label"<<endl;
	else if(type==1)
		cout<<"variable"<<endl;
	cout<<"Value : "<<value<<endl;
}
Assembler::Assembler()
{
	// base address where all variables are stored - set by processor team
	baseAddress=1024;
	runningAddress=baseAddress;
	symbol_table={
		/*
			Can be used to map labels to line numbers
			Variables to memory addresses starting from a base address
		*/
	};
	regex_labels="^[a-zA-Z_][a-zA-Z_0-9]*";
	regex_comment="";
}
int Assembler::terminate(int code)
{
	runningAddress=baseAddress;
	symbol_table.clear();
	return code;
}
string Assembler::extractLabel(string vm_line, bool sectionType=true)
{
	int l;
	if((l=vm_line.find(':'))==string::npos)
	{
		// .data is type true    .text is type false
		if(sectionType)
			perror("Invalid Syntax for Labels");
		return "";
	}
	vm_line=vm_line.substr(0, l);
	
	string label="";
	try
	{
		regex regexp(regex_labels);
		sregex_iterator next(vm_line.begin(), vm_line.end(), regexp);
		sregex_iterator end;
		
		smatch match = *next;
		label=match.str();
		next++;
		
		if(next != end)
		{
			perror("Invalid Syntax for Labels");
			return "";
		}
	}
	catch (const regex_error& e)
	{
    	perror("Invalid Syntax for Labels");
		return "";
	}
	return label;
}
int Assembler::extractTypeAndValue(string label, string vm_line)
{
	string type, value;
	istringstream iss(vm_line);
	if(!(iss>>type>>value))
	{
		perror("Invalid Syntax for Variables");
		return 1;
	}

	if(type==".asciz" || type==".string")
	{
		int l=value.length();
		if(value[0]!='\"' || value.find("\\n\"")!=l-3)
		{
			perror("Invalid Syntax for Strings");
			return 2;
		}
		// Just need the length of the string
		// value=value.substr(1, l-4)+"\n";
		
		l-=3;
		ST_Entry S(1, runningAddress);

		// Each character is 1 byte
		runningAddress+=l*1;
		symbol_table[label]=S;
	}
	else if(type==".word")
	{
		// TODO : Validity Check

		ST_Entry S(1, runningAddress);

		// Requires size of one word
		runningAddress+=4;
		symbol_table[label]=S;
	}
	return 0;
}
void Assembler::printST()
{
	for(pair<string, ST_Entry> entry : symbol_table)
	{
		cout<<"\n______________________________________\n\n";
		cout<<"Key : "<<entry.first<<endl;
		entry.second.ST_Print();
		cout<<"______________________________________\n";
	}
}
int Assembler::firstPass(string vmout)
{
	ifstream fin(vmout, ios::in);
	if(!fin)
	{
		perror("VM output file does not exist");
		return terminate(1);
	}
	
	string vm_line="";
	int countText=0, countData=0;
	
	while(vm_line==".section" || getline(fin, vm_line))
	{
		if(vm_line==".section")
		{
			getline(fin, vm_line);
			if(vm_line==".data")
			{
				countData++;
				if(countData>1)
				{
					perror("Invalid. More than one data section encountered.");
					return terminate(2);
				}

				while(getline(fin, vm_line))
				{
					if(vm_line==".section")
						break;
					string label=extractLabel(vm_line);
					if(label=="")
						return terminate(3);
					getline(fin, vm_line);
					int code=extractTypeAndValue(label, vm_line);
					if(code!=0)
						return terminate(4);
				}
			}
			else if(vm_line==".text")
			{
				countText++;
				if(countText>1)
				{
					perror("Invalid. More than one text section encountered.");
					return terminate(5);
				}

				int linenumber=0;
				while(getline(fin, vm_line))
				{
					if(vm_line.length()==0)
						continue;
					
					string label=extractLabel(vm_line, false);
					if(label=="")
					{
						linenumber++;
						continue;
					}

					// TODO : Just line number or line number * 4 as each instruction corresponds to 4 bytes
					ST_Entry S(0, linenumber);
					symbol_table[label]=S;
				}
			}
			else
			{
				perror("Unknown Syntax");
				return terminate(6);
			}
		}
	}
	if(countText!=1)
	{
		perror("Text section not found");
		return terminate(7);
	}
	return 0;
}
int Assembler::secondPass(string vmout, string asmout)
{
	ifstream fin(vmout, ios::in);
	if(!fin)
	{
		perror("VM output file does not exist");
		return terminate(1);
	}
	ofstream fout(asmout, ios::out);
    
	string ins_tac;
	string op, reg_list;
	int ins=0;
	unsigned char type='\0';
	while(getline(fin, ins_tac))
	{
		istringstream iss(ins_tac);
		if(!(iss>>op>>reg_list))
		{
			perror("Invalid Syntax");
			return terminate(2);
		}
		
		// OP
		try
		{
			type=Map::getInstance()->getOperations()->setIns(ins, op);
		}
		catch(const exception& e)
		{
			perror("Invalid Operation");
			return terminate(3);
		}
		if(type=='\0')
		{
			perror("Invalid Operation");
			return terminate(4);
		}
		

		// REG_LIST
		try
		{
			if(Map::getInstance()->getRegisters()->setRegCode(ins, reg_list, type)!=0)
			{
				perror("Invalid Syntax");
				return 5;
			}
			bitset<32> binary(ins);
			fout<<binary<<endl;
			ins=0;
		}
		catch(const exception& e)
		{
			perror("Invalid Syntax");
			return 6;
		}
		op.clear();
		reg_list.clear();
	}
    fin.close();
	fout.close();
    return 0;
}

int main()
{
	string vmout="sample.asm";
	string asmout="asmout.o";

	cout<<"------STARTED\n";
	Assembler A;
	cout<<A.firstPass(vmout)<<endl;
	A.printST();
	//A.secondPass(vmout, asmout);
	cout<<"ENDED------\n";
}