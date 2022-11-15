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
		unordered_map<string, int> regcode;
		unordered_map<string, ST_Entry> symbol_table;
		string regex_reg;
		vector<string> regex_reg_imm;
		string regex_labels;

	public:
		REGISTERS();
		int setRegCode(int &ins, string reg, unsigned char type, int linenumber);
		vector<int> extractRegisters(string reg, unsigned char type);
		int extractImmediate(vector<int> &regs, string reg, unsigned char type, int imm_type);
		int extractLabel(vector<int> &regs, string reg);
		vector<int> matchReg(string reg, unsigned char type);
		void setSymbolTable(unordered_map<string, ST_Entry> &symbol_table);
		int getSymbolTableValue(string symbol);
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
class Assembler
{
	private:
		int baseAddress;
		int runningAddress;
		unordered_map<string, ST_Entry> symbol_table;
		unordered_map<char, char> escapeChars;
		string regex_labels;
		string regex_comment;
		string regex_asciz;

	public:
		Assembler();
		int terminate(int code);
		string extractLabel(string vm_line, bool sectionType);
		string extractComment(string vm_line);
		string extractAsciz(string vm_line);
		int extractTypeAndValue(string label, string vm_line);
		void printST();
		// To create the symbol table
		int firstPass(string vmout);
		int secondPass(string vmout, string asmout);
};
#endif