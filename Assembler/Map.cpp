#include "Map.h"

Map* Map::instance=0;
OPERATIONS::OPERATIONS()
{
	// Many R type operations i.e. ADD SUB OR AND
	// SLL SLT SLTU XOR SRL SRA have the same opcodes
	opcode={
		// R- Type
		{"ADD", 0b0110011},
		{"OR", 0b0110011},
		{"AND", 0b0110011},
		
		// I - Type
		{"LW", 0b0000011},

		// S - Type
		{"SW", 0b0100011}
	};

	funct3={
		// R - Type
		{"ADD", 0b000},
		{"OR", 0b110},
		{"AND", 0b111},

		// I - Type
		{"LW", 0b010},

		// S -Type
		{"SW", 0b010}
	};

	funct7={
		// R - Type
		{"ADD", 0b0000000},
		{"OR", 0b0000000},
		{"AND", 0b0000000},
	};
	
	uid={

	};

	type={
		// R - Type
		{"ADD", 'R'},
		{"OR", 'R'},
		{"AND", 'R'},

		// I - Type
		{"LW", 'I'},

		// S -Type
		{"SW", 'S'}
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
		int i=regs.size();
		sregex_iterator next(reg.begin(), reg.end(), regexp);
		sregex_iterator end;
		
		smatch match = *next;
		string imm_reg=match.str();
		
		int immediate=stoi(imm_reg.substr(0, imm_reg.find('(')));

		regs.push_back(immediate);
		next++;
		i++;

		if(next != end)
		{
			perror("Invalid Syntax");
			reg.resize(i);
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
	if(type == 'I')
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
	return 1;
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

int main()
{
	string vmout="vmout.tac";
	string asmout="asmout.asm";

    ifstream fin(vmout, ios::in);
	if(!fin)
	{
		perror("VM output file does not exist");
		return 1;
	}
	ofstream fout(asmout, ios::out);
    
	string ins_tac;
	string op, reg_list;
	int ins=0;
	unsigned char type;
	while(getline(fin, ins_tac))
	{
		istringstream iss(ins_tac);
		if(!(iss>>op>>reg_list))
		{
			perror("Invalid Syntax");
			return 2;
		}
		
		// OP
		try
		{
			type=Map::getInstance()->getOperations()->setIns(ins, op);
		}
		catch(const exception& e)
		{
			perror("Invalid Operation");
			return 3;
		}

		// REG_LIST
		try
		{
			Map::getInstance()->getRegisters()->setRegCode(ins, reg_list, type);
			bitset<32> binary(ins);
			fout<<binary<<endl;
			ins=0;
		}
		catch(const exception& e)
		{
			perror("Invalid Register Syntax");
			return 4;
		}
		op.clear();
		reg_list.clear();
	}
    fin.close();
	fout.close();
    return 0;
}