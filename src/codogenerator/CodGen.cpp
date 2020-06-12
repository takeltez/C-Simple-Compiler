#include "Parser.h"

extern map <string, string> type_id;
map <string, string> mem_pos;
vector <string> LC_marks;
vector <int> L_marks;

string var;
string value;
string operand1;
string operand2;
string command;
string comp_command;
string d_type;

string src_file_name;
string asm_file_name;
string exc_file_name;

string array_name;
string array_member;

bool use_reg_eax = true;
bool use_reg_edx = true;
bool use_reg_bl = true;

bool is_if = false;
bool is_array_pos = false;

int offset = 0;
int L_mark_num = 1;
int LC_mark_num = 0;
int for_cond_elem;

CodGen *cod_gen = new CodGen();

CodGen::CodGen(void) {}

void RootAST::codogenerator()
{	
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->codogenerator();
}

void ArrayDataAST::codogenerator()
{
	int arr_offset;

	if (d_type == "int") {

		arr_offset = offset + blocks.size() * sizeof(int);
		offset = arr_offset;
	}

	else if (d_type == "char") {

		arr_offset = offset + blocks.size() * sizeof(char);
		offset = arr_offset;
	}

	for (int i = 0; i < blocks.size(); ++i)
	{
		blocks[i]->codogenerator();

		array_member = array_name + "[" + to_string(i) + "]";

		if (mem_pos.find(array_member) == mem_pos.end()) {

			if (d_type == "int") {
				
				mem_pos.emplace(array_member, "DWORD PTR [rbp-" + to_string(arr_offset));
				arr_offset -= 4;
			}

			else if (d_type == "char") {

				mem_pos.emplace(array_member, "BYTE PTR [rbp-" + to_string(arr_offset));
				arr_offset -= 1;
			}
		}

		operand1 = array_member;

		cod_gen->handleAsmMov();
	}

	 operand1.clear();
}

void ArrayNameAST::codogenerator()
{	
	array_name = definition;

	auto it = type_id.find(definition);

	d_type = it->second; 

	if (identificator != NULL) {

		identificator->codogenerator();
		
		if (!value.empty()) {

			array_member = array_name + "[" + value + "]";
			var = array_member;
		}

		else {

			string buff = command;
			command = "ArrayIndex";

			is_array_pos = true;

			cod_gen->handleAsmMov();
			
			array_member = array_name + "[0]";
			var = array_member;
		
			command = buff;
		}
	}

	value.clear();
}

void ForAST::codogenerator()
{
	for_cond_elem = 0;

	condition->codogenerator();
	cod_gen->handleAsmJmp();
	
	body->codogenerator();

	for_cond_elem = 2;

	condition->codogenerator();

	ofstream file ("asm/" + asm_file_name, ios::app);
	
	file << ".L" + to_string(L_mark_num) + ":"<<endl;
	
	for_cond_elem = 1;

	condition->codogenerator();
	cod_gen->handleAsmCondPassLoop();

	file.close();
}

void ForBodyAST::codogenerator()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->codogenerator();
}

void ForConditionAST::codogenerator()
{	
	blocks[for_cond_elem]->codogenerator();
}

void WhileAST::codogenerator()
{   
	cod_gen->handleAsmJmp();
	body->codogenerator();

	ofstream file ("asm/" + asm_file_name, ios::app);
	
	file << ".L" + to_string(L_mark_num) + ":"<<endl;
	
	condition->codogenerator();
	cod_gen->handleAsmCondPassLoop();

	file.close();
}

void WhileBodyAST::codogenerator()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->codogenerator();
}

void WhileConditionAST::codogenerator()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->codogenerator();
}

void IfAST::codogenerator()
{
	is_if = true;

	condition->codogenerator();
	cod_gen->handleAsmCondPassIf();

	body->codogenerator();
}

void IfBodyAST::codogenerator()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->codogenerator();
}

void IfConditionAST::codogenerator()
{	
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->codogenerator();
}

void ElseAST::codogenerator()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->codogenerator();

	if (!is_if) {

		ofstream file ("asm/" + asm_file_name, ios::app);

		file << ".L" + to_string(++L_mark_num) + ":"<<endl;
	
		file.close();
	}
}

void FunctionAST::codogenerator()
{
	args->codogenerator();
	body->codogenerator();
}

void FunctionBodyAST::codogenerator()
{
	for (int i = 0; i < blocks.size(); ++i) 
	{	
		blocks[i]->codogenerator();

		if (is_if) {

			ofstream file ("asm/" + asm_file_name, ios::app);
			
			string node_type = typeid(*(blocks[i + 1])).name();

			if (node_type.find("ElseAST") != string::npos) {

				int jmp_num = 0;

				for (int j = 2; node_type.find("ElseAST") != string::npos; ++j)
				{
					node_type = typeid(*(blocks[i + j])).name();
					++jmp_num;
				}

				file << "\t\tjmp\t\t.L" + to_string(L_mark_num + jmp_num)<<endl;
			}

			for (int i = 0; i < L_marks.size(); ++i)
				file << ".L" + to_string(L_marks[i]) + ":"<<endl;
		
			is_if = false;

			L_marks.clear();
			file.close();
		}
	}
}

void FunctionArgsAST::codogenerator()
{
	for (int i = 0; i < args.size() - 1; ++i)
		args[i]->codogenerator();	
}

void AssignmentAST::codogenerator()
{	
	command = definition;

	l_operand->codogenerator();
	operand1 = var;

	r_operand->codogenerator();
	operand2 = var;

	cod_gen->handleAsmMov();

	is_array_pos = false;

	d_type.clear();
	value.clear();
	var.clear();
	operand1.clear();
	operand2.clear();
	command.clear();
	array_name.clear();
	array_member.clear();
}

void LogicOperationAST::codogenerator()
{
	l_operand->codogenerator();
	r_operand->codogenerator();
}

void TernarOperationAST::codogenerator()
{
	l_operand->codogenerator();
	r_operand->codogenerator();
}

void BinOperationAST::codogenerator()
{
	string buff = command;
	command = definition;

	if (command == "+") {

		l_operand->codogenerator();
		cod_gen->handleAsmMov();

		r_operand->codogenerator();
		cod_gen->handleAsmMov();

		cod_gen->handleAsmAdd();
	}

	else if (command == "-") {

		l_operand->codogenerator();
		cod_gen->handleAsmMov();

		r_operand->codogenerator();
		cod_gen->handleAsmMov();

		cod_gen->handleAsmSub();
	}

	else if (command == "*") {

		l_operand->codogenerator();
		cod_gen->handleAsmMov();

		r_operand->codogenerator();
		cod_gen->handleAsmMov();

		cod_gen->handleAsmMul();
	}

	else if (command == "/") {

		l_operand->codogenerator();
		cod_gen->handleAsmMov();

		r_operand->codogenerator();
		cod_gen->handleAsmMov();

		cod_gen->handleAsmDiv();
	}

	else if (command == "==" || command == "!=" || command == ">" || command == "<" 
			|| command == ">=" || command == "<=") {

		l_operand->codogenerator();
		cod_gen->handleAsmMov();

		r_operand->codogenerator();
		cod_gen->handleAsmMov();

		cod_gen->handleAsmCmp();

		comp_command = command;
	}

	command = buff;

	use_reg_edx = true;
	use_reg_eax = true;
	use_reg_bl = true;

	is_array_pos = false;
}

void UnaryOperationAST::codogenerator()
{
	operand->codogenerator();

	if (definition == "++")
		cod_gen->handleAsmInc();

	else if (definition == "--")
		cod_gen->handleAsmDec();
}

void PointerAST::codogenerator()
{
	identificator->codogenerator();
}

void DataTypeAST::codogenerator()
{
	identificator->codogenerator();
}

void ConstAST::codogenerator()
{
	identificator->codogenerator();
}

void PrintfAST::codogenerator()
{
	command = definition;

	for (int i = 0; i < params.size(); ++i)
		params[i]->codogenerator();

	if (params.size() == 1)
		command = "puts";

	cod_gen->handleAsmMov();
	cod_gen->handleAsmCall();

	command.clear();
}

void ReturnAST::codogenerator()
{
	command = definition;

	identificator->codogenerator();

	cod_gen->handleAsmMov();

	value.clear();
	command.clear();
}

void StringLexemeAST::codogenerator()
{
	if (command == "printf") 
		LC_marks.push_back(".LC" + to_string(LC_mark_num) + ":\n\t\t.string\t" + definition);
}

void SymbolLexemeAST::codogenerator()
{
	char symbol = definition.c_str()[1];
	int askii_cod = (int)symbol;

	value = to_string(askii_cod);
}

void DigitIdAST::codogenerator()
{
	value = definition;
}

void SymbolIdAST::codogenerator()
{
	auto it = type_id.find(definition);

	d_type = it->second; 

	if (mem_pos.find(definition) == mem_pos.end()) {

		if (d_type == "int") {
			
			mem_pos.emplace(definition, "DWORD PTR [rbp-" + to_string(offset + 4));
			offset += 4;
		}

		else if (d_type == "char") {

			mem_pos.emplace(definition, "BYTE PTR [rbp-" + to_string(offset + 1));
			offset += 1;
		}
	}

	var = definition;

	value.clear();
}

void BreakAST::codogenerator() {}


void CodGen::setFileName(string file_path)
{
	int start_pos = file_path.rfind("/");
	int end_pos = file_path.rfind(".");	

	asm_file_name = file_path.substr(start_pos + 1, end_pos - start_pos - 1);
	
	src_file_name = asm_file_name + ".c";
	exc_file_name = asm_file_name + ".out";
	asm_file_name += ".s";	
}

void CodGen::startCodGen(AST *tree, string file_path)
{
	setFileName(file_path);

	system("mkdir asm");
	
	handleProlog();

	RootAST *root = static_cast<RootAST*>(tree);
	
	root->codogenerator();

	handleEpilog();

	handleLCMarks();
}