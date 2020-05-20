#include "Parser.h"

extern map <string, string> vars_mem_pos;
extern vector <int> marks;

extern string var;
extern string value;
extern string operand1;
extern string operand2;
extern string command;
extern string comp_command;
extern string d_type;

extern string src_file_name;
extern string asm_file_name;
extern string exc_file_name;

extern int offset;
extern int mark_num;

extern bool use_reg_eax;
extern bool use_reg_edx;
extern bool use_reg_bl;

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

		auto it1 = vars_mem_pos.find(operand1);
		auto it2 = vars_mem_pos.find(operand2);

		if (it1 != vars_mem_pos.end() && it2 != vars_mem_pos.end() && !value.empty())
			file << "\t\tmov\t\t" + it1->second + ", " + value<<endl;
	
		else if (it1 != vars_mem_pos.end() && it2 != vars_mem_pos.end() && value.empty()) {

			if (d_type == "int")
				file << "\t\tmov\t\teax, " + it2->second<<endl<<"\t\tmov\t\t" + it1->second + ", eax"<<endl;
		
			else if (d_type == "char")
				file << "\t\tmov\t\tal, " + it2->second<<endl<<"\t\tmov\t\t" + it1->second + ", al"<<endl;
		}
	}

	else if (command == "+" || command == "-" || command == "*" || command == "/" 
			|| command == "==" || command == "!=") {

		if (use_reg_eax) {

			if (!value.empty())
				file << "\t\tmov\t\teax, " + value<<endl;
			
			else {

				auto it = vars_mem_pos.find(var);
				file << "\t\tmov\t\teax, " + it->second<<endl;
			}

			use_reg_eax = false;
		}

		else if (command == "/") {

			file << "\t\tcdq"<<endl;
			
			use_reg_bl = false;
		}
		
		else if (use_reg_edx) {

			if (!value.empty())
				file << "\t\tmov\t\tedx, " + value<<endl;
			
			else {

				auto it = vars_mem_pos.find(var);
				file << "\t\tmov\t\tedx, " + it->second<<endl;
			}

			use_reg_edx = false;
		}
	}

	else if (command == "return")
		file << "\t\tmov\t\teax, " + value<<endl;

	file.close();
}

void CodGen::handleAsmAdd()
{
	ofstream file ("asm/" + asm_file_name, ios::app);

	file << "\t\tadd\t\teax, edx"<<endl;
	value = "eax";

	file.close();
}

void CodGen::handleAsmSub()
{
	ofstream file ("asm/" + asm_file_name, ios::app);

	file << "\t\tsub\t\teax, edx"<<endl;
	value = "eax";

	file.close();
}

void CodGen::handleAsmMul()
{
	ofstream file ("asm/" + asm_file_name, ios::app);

	file << "\t\timul\teax, edx"<<endl;
	value = "eax";

	file.close();
}

void CodGen::handleAsmDiv()
{
	ofstream file ("asm/" + asm_file_name, ios::app);

	auto it = vars_mem_pos.find(var);

	file << "\t\tidiv\t" + it->second<<endl;
	value = "eax";

	file.close();
}

void CodGen::handleAsmCmp()
{
	ofstream file ("asm/" + asm_file_name, ios::app);

	file << "\t\tcmp\t\teax, edx"<<endl;

	file.close();
}

void CodGen::handleAsmPass()
{
	ofstream file ("asm/" + asm_file_name, ios::app);

	if (comp_command == "==") {

		++mark_num;
		marks.push_back(mark_num);

		file << "\t\tjne\t\t.L" + to_string(mark_num)<<endl;
		
	}

	else if (comp_command == "!=") {

		++mark_num;
		marks.push_back(mark_num);

		file << "\t\tje\t\t.L" + to_string(mark_num)<<endl;
		
	}

	else if (comp_command == ">") {

		++mark_num;
		marks.push_back(mark_num);

		file << "\t\tjle\t\t.L" + to_string(mark_num)<<endl;
		
	}

	else if (comp_command == "<") {

		++mark_num;
		marks.push_back(mark_num);

		file << "\t\tjge\t\t.L" + to_string(mark_num)<<endl;
		
	}

	else if (comp_command == ">=") {

		++mark_num;
		marks.push_back(mark_num);

		file << "\t\tjl\t\t.L" + to_string(mark_num)<<endl;
		
	}

	else if (comp_command == "<=") {

		++mark_num;
		marks.push_back(mark_num);

		file << "\t\tjg\t\t.L" + to_string(mark_num)<<endl;
		
	}

	file.close();
}