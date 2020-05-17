#include "Parser.h"

extern string value;
extern string command;
extern string d_type;

extern string src_file_name;
extern string asm_file_name;
extern string exc_file_name;

extern int offset;

void CodGen::compileAsmFile()
{
	string comp = "gcc asm/" + asm_file_name + " -no-pie -o asm/" + exc_file_name;

	if (!system(comp.c_str()))
		cout <<"Done: "<<src_file_name<<" -> "<< asm_file_name<<" -> "<<exc_file_name<<endl;
}

void CodGen::printAsm()
{
	string asm_info;

	ifstream file ("asm/" + asm_file_name);

	getline (file, asm_info, '\0');

	cout<<asm_info<<endl;

	file.close();
}

void CodGen::handleProlog()
{
	ofstream file ("asm/" + asm_file_name);

	file << ".intel_syntax noprefix\n\n.global main\n\nmain:\n\t\tpush\trbp\n\t\tmov\t\trbp, rsp\n";

	file.close();
}

void CodGen::handleEpilog()
{
	ofstream file ("asm/" + asm_file_name, ios::app);

	file << "\t\tpop\t\trbp\n\t\tret\n";

	file.close();
}

void CodGen::handleAsmMov()
{
	ofstream file ("asm/" + asm_file_name, ios::app);

	if (command == "=") {

		if (d_type == "int") {
			
			file << "\t\tmov\t\tDWORD PTR [rbp-" + to_string(offset + 4) + "], " + value<<endl;
			offset += 4;
		}

		else if (d_type == "char") {
			
			char symbol = value.c_str()[1];
			int askii_cod = (int)symbol;

			file << "\t\tmov\t\tBYTE PTR [rbp-" + to_string(offset + 1) + "], " + to_string(askii_cod)<<endl;
			offset += 1;
		}
	}

	else if (command == "return")
		file << "\t\tmov\t\teax, " + value<<endl;

	file.close();
}