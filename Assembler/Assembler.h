#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include<unordered_map>
#include<cstring>
#include<regex>
#include<iostream>
#include<fstream>
#include<bitset>
#include<fcntl.h>
using namespace std;
class OPERATIONS
{
	private:
		unordered_map<string, unsigned char> opcode;
		unordered_map<string, unsigned char> funct3;
		unordered_map<string, unsigned char> funct7;
		unordered_map<string, int> uid;
		unordered_map<string, unsigned char> type;
		
	public:
		OPERATIONS();
		unsigned char setIns(int &ins, string op);
};

class REGISTERS
{
	private:
		unordered_map<string, unsigned char> regcode;
		string regex_reg;
		string regex_reg_imm;

	public:
		REGISTERS();
		int setRegCode(int &ins, string reg, unsigned char type);
		vector<int> extractRegisters(string reg, unsigned char type);
		int extractImmediate(vector<int> &regs, string reg, unsigned char type);
		vector<int> matchReg(string reg, unsigned char type);
};
class Map
{
	private:
		static Map* instance;
		REGISTERS* registers;
		OPERATIONS* operations;
		
	public:
		Map();
		static Map* getInstance();
		REGISTERS* getRegisters();
		OPERATIONS* getOperations();
};
struct ST_Entry
{
	int value;
	/*
		type can be used to denote
		0 - labels
		1 - variables
	*/
	int type;
	ST_Entry();
	ST_Entry(int type, int value);
	void ST_Print();
};
class Assembler
{
	private:
		int baseAddress;
		int runningAddress;
		unordered_map<string, ST_Entry> symbol_table;
		string regex_labels;
		string regex_comment;

	public:
		Assembler();
		int terminate(int code);
		string extractLabel(string vm_line, bool sectionType);
		int extractTypeAndValue(string label, string vm_line);
		void printST();
		// To create the symbol table
		int firstPass(string vmout);
		int secondPass(string vmout, string asmout);
};
#endif