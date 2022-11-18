// https://itnext.io/risc-v-instruction-set-cheatsheet-70961b4bbe8
// https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf
// https://en.wikichip.org/wiki/risc-v/registers
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
		{"xor", 0b0110011},
		{"sll", 0b0110011},
		{"srl", 0b0110011},
		
		// I - Type
		{"lw", 0b0000011},
		{"lb", 0b0000011},
		{"addi", 0b0010011},
		{"jalr", 0b1100111},

		// S - Type
		{"sw", 0b0100011},
		{"sb", 0b0100011},

		// B - Type
		{"beq", 0b1100011},
		{"bne", 0b1100011},
		{"blt", 0b1100011},
		{"bge", 0b1100011},
		{"bltu", 0b1100011},
		{"bgeu", 0b1100011},

		// U - Type
		{"lui", 0b0110111},

		// J - Type
		{"jal", 0b1101111},
	};

	funct3={
		// R - Type
		{"add", 0b000},
		{"sub", 0b000},
		{"or", 0b110},
		{"and", 0b111},
		{"xor", 0b100},
		{"sll", 0b001},
		{"srl", 0b101},

		// I - Type
		{"lw", 0b010},
		{"lb", 0b000},
		{"addi", 0b000},
		{"jalr", 0b000},

		// S -Type
		{"sw", 0b010},
		{"sb", 0b000},

		// B - Type
		{"beq", 0b000},
		{"bne", 0b001},
		{"blt", 0b100},
		{"bge", 0b101},
		{"bltu", 0b110},
		{"bgeu", 0b111},
	};

	funct7={
		// R - Type
		{"add", 0b0000000},
		{"sub", 0b0100000},
		{"or", 0b0000000},
		{"and", 0b0000000},
		{"xor", 0b0000000},
		{"sll", 0b0000000},
		{"srl", 0b0000000},
	};
	
	uid={
		{"ecall", 0b1110011},
	};

	type={
		// R - Type
		{"add", 'R'},
		{"sub", 'R'},
		{"or", 'R'},
		{"and", 'R'},
		{"xor", 'R'},
		{"sll", 'R'},
		{"srl", 'R'},

		// I - Type
		{"lw", 'I'},
		{"lb", 'I'},
		{"addi", 'I'},
		{"jalr", 'I'},

		// S -Type
		{"sw", 'S'},
		{"sb", 'S'},

		// B - Type
		{"beq", 'B'},
		{"bne", 'B'},
		{"blt", 'B'},
		{"bge", 'B'},
		{"bltu", 'B'},
		{"bgeu", 'B'},

		// U - Type
		{"lui", 'U'},

		// J - Type
		{"jal", 'J'},

		{"ecall", 'N'},
	};
}
// TODO : Instructions
/*
fmv.w.x
fsw
flw
fadd.s
add support for hex values
*/
REGISTERS::REGISTERS()
{
	regcode={
		{"a", 10},
		{"t", 5},
		{"T", 25},
		{"s", 8},
		{"S", 16},
	};
	regex_reg="(^|\\(|,)[xast](\\d)+";
	regex_reg_imm={"(\\+|-)?(\\d)+\\([xast](\\d)+\\)", "(,0x[0-9a-f]+)|(,(\\+|-)?(\\d)+)"};
	regex_labels="[a-zA-Z_][a-zA-Z_0-9]*";
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
			string temp_reg=match.str();
			if(temp_reg[0]==',' || temp_reg[0]=='(')
				temp_reg.erase(temp_reg.begin());
			
			reg_code=stoi(temp_reg.substr(1, 2));
			if((temp_reg[0]=='x' && !(reg_code>=0 && reg_code<32)) || (temp_reg[0]=='a' &&!(reg_code>=0 && reg_code<8)) || (temp_reg[0]=='s' &&!(reg_code>=0 && reg_code<12)) || (temp_reg[0]=='t' &&!(reg_code>=0 && reg_code<7)))
			{
				perror("Invalid Register Number");
				regs.resize(i);
				return regs;
			}
			switch(temp_reg[0])
			{
				case 'a':reg_code+=regcode["a"];break;
				case 's':if(reg_code<2)
							reg_code+=regcode["s"];
						else
							reg_code+=regcode["S"];
						break;
				case 't':if(reg_code<3)
							reg_code+=regcode["t"];
						else
							reg_code+=regcode["T"];
						break;
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
int REGISTERS::extractImmediate(vector<int> &regs, string reg, unsigned char type, int imm_type)
{
	try
	{
		regex regexp(regex_reg_imm[imm_type]);
		sregex_iterator next(reg.begin(), reg.end(), regexp);
		sregex_iterator end;

		if(next==end)
		{
			if(imm_type==regex_reg_imm.size())
			{
				perror("Invalid Syntax");
				return 1;
			}
			return extractImmediate(regs, reg, type, imm_type+1);
		}
		
		smatch match = *next;
		string imm_reg=match.str();
		
		int immediate=0;
		if(imm_type==0)
			immediate=stoi(imm_reg.substr(0, imm_reg.find('(')));
		else if(imm_type==1)
		{
			imm_reg.erase(imm_reg.begin());
			if(imm_reg[0]=='0' && imm_reg[1]=='x')
			{
				imm_reg.erase(imm_reg.begin(), imm_reg.begin()+2);
				immediate=stoi(imm_reg, 0, 16);					
			}
			else
				immediate=stoi(imm_reg);
		}
		regs.resize(regs.size()+1, immediate);
		next++;
		
		if(next != end)
		{
			perror("Invalid Syntax");
			regs.resize(regs.size()-1);
			return 2;
		}
	}
	catch (const regex_error& e)
	{
		perror("Invalid Syntax");
		return 3;
	}
	return 0;
}
int REGISTERS::extractLabel(vector<int> &regs, string reg)
{
	string label="";
	try
	{
		regex regexp(","+regex_labels+"$");
		sregex_iterator next(reg.begin(), reg.end(), regexp);
		sregex_iterator end;
		
		smatch match = *next;
		label=match.str();
		label.erase(label.begin());
		
		int val;
		if((val=getSymbolTableValue(label))==-1)
		{
			perror("Invalid Label not found");
			return 3;
		}
		
		regs.resize(regs.size()+1, val);
		next++;
		
		if(next != end)
		{
			perror("Invalid Syntax");
			regs.resize(regs.size()-1);
			return 1;
		}
	}
	catch (const regex_error& e)
	{
    	perror("Invalid Syntax for Labels");
		return 2;
	}
	return 0;
}

vector<int> REGISTERS::matchReg(string reg, unsigned char type)
{
	vector<int> regs=extractRegisters(reg, type);
	if(type == 'I' || type=='S' || type=='U')
		extractImmediate(regs, reg, type, 0);
	if(type == 'B' || type=='J')
		extractLabel(regs, reg);
	return regs;	
}
int REGISTERS::setRegCode(int &ins, string reg, unsigned char type, int linenumber)
{
	char reg_code;
	vector<int> regs=matchReg(reg, type);
	
	if(type=='R')
	{
		if(regs.size() != 3)
		{
			perror("Invalid Syntax");
			return 1;
		}
		// regs[0] is destination regs[1] and regs[2] are source
		// regs[0] should not be x0 
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
		// regs[0] is destination regs[1] is source
		// regs[0] should not be x0 
		// regs[2] has the immediate value
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
		// regs[0] is source(rs2) regs[1] is source(rs1)
		// regs[2] has the immediate value
		
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
	else if(type=='B')
	{
		if(regs.size() != 3)
		{
			perror("Invalid Syntax");
			return 1;
		}
		// regs[0] is source(rs1) regs[1] is source(rs2)
		// regs[2] has the immediate value i.e. the line number to which jump has to be made

		// rs1
		ins=ins|(regs[0]<<15);
		// rs2
		ins=ins|(regs[1]<<20);

		// imm should be modified to find offset value which is (imm - linenumber) * 4 i.e. (ST_Entry of label - current linenumber) * 4
		int offset=(regs[2]-linenumber-1)<<2;
		// offset
		// offset is split into 4 segments
		// bit 11 from LSB at index 7 of ins
		// bits 1 to 4 from LSB - starting from index 8 of ins
		// bits 5 to 10 from LSB - starting from index 25 of ins
		// bit 12 from LSB at index 31 of ins
		ins=ins|(((offset>>10)&1)<<7);
		ins=ins|((offset&15)<<8);
		ins=ins|((offset&1008)>>4<<25);
		ins=ins|(((offset>>11)&1)<<31);
	}
	else if(type=='U')
	{
		if(regs.size() != 2)
		{
			perror("Invalid Syntax");
			return 1;
		}
		// regs[0] is destination
		// regs[1] has the immediate value
		if(regs[0]==0)
		{
			perror("Invalid Destination Register");
			return 2;
		}

		// rd
		ins=ins|(regs[0]<<7);
		// imm
		ins=ins|(regs[1]<<12);
	}
	else if(type=='J')
	{
		if(regs.size() != 2)
		{
			perror("Invalid Syntax");
			return 1;
		}
		// regs[0] is destination
		// regs[1] has the immediate value
		if(regs[0]==0)
		{
			perror("Invalid Destination Register");
			return 2;
		}

		// rd
		ins=ins|(regs[0]<<7);
		
		// imm should be modified to find offset value which is (imm - linenumber) * 4 i.e. (ST_Entry of label - current linenumber) * 4
		int offset=(regs[1]-linenumber-1)<<2;
		// offset
		// offset is split into 4 segments
		// bit 20 from LSB at index 31 of ins
		// bits 1 to 10 from LSB - starting from index 21 of ins
		// bit 11 from LSB at index 20 of ins
		// bit 12 to 19 from LSB - starting from index 12 of ins
		ins=ins|(((offset>>19)&1)<<31);
		ins=ins|((offset&1023)<<21);
		ins=ins|(((offset>>10)&1)<<20);
		ins=ins|((offset&522240)>>11<<12);
	}
	return 0;
}
void REGISTERS::setSymbolTable(unordered_map<string, ST_Entry> &symbol_table)
{
	this->symbol_table=symbol_table;
}
int REGISTERS::getSymbolTableValue(string symbol)
{
	unordered_map<string, ST_Entry>::iterator pos;
	if(symbol_table.find(symbol) == symbol_table.end())
		return -1;
	return symbol_table[symbol].value;
}
unsigned char OPERATIONS::setIns(int &ins, string op)
{
	if(uid.find(op) != uid.end())
	{
		ins=ins|uid[op];
		return type[op];
	}
	if(opcode.find(op) == opcode.end())
	{
		perror("Invalid Operation");
		return '\0';
	}
	ins=ins|opcode[op];
	if(funct3.find(op) != opcode.end())
		ins=ins|(funct3[op]<<12);
	if(funct7.find(op) != opcode.end())
		ins=ins|(funct7[op]<<25);
	uid[op]=ins;
	return type[op];
}
ST_Entry::ST_Entry(){}
ST_Entry::ST_Entry(int type, int value)
{
	this->type=type;
	this->value=value;
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
	escapeChars={
		{'n','\n'},
		{'t', '\t'}
	};
	regex_labels="^[a-zA-Z_][a-zA-Z_0-9]*";
	regex_comment="^# (.)*";
	regex_asciz="\"(.)*\"";
}
int Assembler::terminate(int code)
{
	runningAddress=baseAddress;
	symbol_table.clear();
	return code;
}
string Assembler::extractLabel(string vm_line, bool sectionType=true)
{
	if(vm_line.find(':')==string::npos)
	{
		// .data is type true    .text is type false
		if(sectionType)
			perror("Invalid Syntax for Labels");
		return "";
	}
	vm_line.pop_back();
	
	string label="";
	try
	{
		regex regexp(regex_labels);
		sregex_iterator next(vm_line.begin(), vm_line.end(), regexp);
		sregex_iterator end;

		if(next==end)
			return "";
		
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
string Assembler::extractComment(string vm_line)
{
	string comment="";
	try
	{
		regex regexp(regex_comment);
		sregex_iterator next(vm_line.begin(), vm_line.end(), regexp);
		sregex_iterator end;
		
		if(next==end)
			return "";

		smatch match = *next;
		comment=match.str();
		next++;
	}
	catch (const regex_error& e)
	{
    	perror("Invalid Syntax for Labels");
		return "";
	}
	return comment;
}
string Assembler::extractAsciz(string vm_line)
{
	string asciz="";
	try
	{
		regex regexp(regex_asciz);
		sregex_iterator next(vm_line.begin(), vm_line.end(), regexp);
		sregex_iterator end;
		
		if(next==end)
			return "";

		smatch match = *next;
		asciz=match.str();
		next++;
	}
	catch (const regex_error& e)
	{
    	perror("Invalid Syntax for Labels");
		return "";
	}
	return asciz;
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
		value=extractAsciz(vm_line);
		int l=value.length();
		if(value[0]!='\"' || value[l-1]!='\"')
		{
			perror("Invalid Syntax for Strings");
			return 2;
		}
		
		value=value.substr(1, l-2);
		// Need to extract escape characters from the string
		int i=value.find("\\");
		while(i!=string::npos)
		{
			char c=escapeChars[value[i+1]];
			if(c!='\0')
			{
				value=value.substr(0, i)+c+value.substr(i+2);
				i=value.find("\\", i+1);
			}
			else
			{
				perror("Invalid Syntax for Strings");
				return 3;
			}
		}

		// Including terminating '\0' character
		value.shrink_to_fit();
		l=value.length()+1;
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
	cout<<"\nSYMBOL TABLE\n";
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
					if(vm_line.length()==0)
						continue;
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
						string comment=extractComment(vm_line);
						if(comment=="")
							linenumber++;
						continue;
					}

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

	Map::getInstance()->getRegisters()->setSymbolTable(symbol_table);
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
	int linenumber=0;

	// Run through till .section .text
	while(getline(fin, ins_tac))
	{
		if(ins_tac==".section")
		{
			getline(fin, ins_tac);
			if(ins_tac==".data")
				continue;
			else if(ins_tac==".text")
				break;
			else
			{
				perror("Invalid Syntax");
				return terminate(2);
			}
		}
	}

	while(getline(fin, ins_tac))
	{
		if(ins_tac.length()==0)
			continue;
		
		if(extractLabel(ins_tac, false)!="")
			continue;

		if(extractComment(ins_tac)!="")
			continue;

		// Some ins have info hardcoded in uid (independent of registers, immediate etc)
		// If more such ins should be added (We can add in a set and check)
		ins=0;
		if(ins_tac=="ecall")
		{
			// OP
			try
			{
				type=Map::getInstance()->getOperations()->setIns(ins, ins_tac);
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
			bitset<32> binary(ins);
			fout<<binary<<endl;
			linenumber++;
			continue;
		}
		if(ins_tac=="nop")
		{
			bitset<32> binary(ins);
			fout<<binary<<endl;
			linenumber++;
			continue;
		}

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
			cout<<op<<endl;
			return terminate(4);
		}
		
		// REG_LIST
		try
		{
			if(Map::getInstance()->getRegisters()->setRegCode(ins, reg_list, type, linenumber)!=0)
			{
				perror("Invalid Syntax");
				return terminate(5);
			}
			bitset<32> binary(ins);
			fout<<binary<<endl;
			linenumber++;
		}
		catch(const exception& e)
		{
			perror("Invalid Syntax");
			return terminate(6);
		}
		op.clear();
		reg_list.clear();
		type='\0';
	}
    fin.close();
	fout.close();
    return 0;
}

int main()
{
	string vmout="vmout.asm";
	string asmout="asmout.o";

	cout<<"------STARTED\n";

	Assembler A;
	int flag=A.firstPass(vmout);
	if(flag==0)
	{
		A.printST();
		cout<<"\nFIRST PASS COMPLETE\n\nSECOND PASS STARTED...\n";
		flag=A.secondPass(vmout, asmout);
	}

	if(flag==0)
		cout<<"\nSECOND PASS COMPLETE\n";
	else
	{
		cout<<flag<<endl;
		perror("Invalid Code");
		return 1;
	}

	cout<<"\nENDED------\n";
}