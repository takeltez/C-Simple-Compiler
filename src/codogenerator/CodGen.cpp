#include "Parser.h"

extern map <string, string> type_id;
extern string data_type;

string val;
string command;

string src_file_name;
string asm_file_name;
string exc_file_name;

int offset = 0;

CodGen *cod_gen = new CodGen();

CodGen::CodGen(void) {}

void RootAST::codogenerator()
{	
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->codogenerator();
}

void ArrayDataAST::codogenerator()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->codogenerator();
}

void ArrayNameAST::codogenerator()
{	
	if (identificator != NULL)
		identificator->codogenerator();
}

void ForAST::codogenerator()
{
	condition->codogenerator();
	body->codogenerator();
}

void ForBodyAST::codogenerator()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->codogenerator();
}

void ForConditionAST::codogenerator()
{	
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->codogenerator();
}

void WhileAST::codogenerator()
{   	
	condition->codogenerator();
	body->codogenerator();
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
	condition->codogenerator();
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

void FunctionAST::codogenerator()
{
	args->codogenerator();
	body->codogenerator();
}

void FunctionBodyAST::codogenerator()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->codogenerator();
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
	r_operand->codogenerator();

	cod_gen->handleAsmMov();

	data_type.clear();
	val.clear();
	command.clear();
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
	l_operand->codogenerator();
	r_operand->codogenerator();
}

void UnaryOperationAST::codogenerator()
{
	operand->codogenerator();
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
	for (int i = 0; i < params.size(); ++i)
		params[i]->codogenerator();
}

void ReturnAST::codogenerator()
{
	command = definition;

	identificator->codogenerator();

	cod_gen->handleAsmMov();

	val.clear();
	command.clear();
}

void StringLexemeAST::codogenerator()
{
}

void SymbolLexemeAST::codogenerator()
{
}

void DigitIdAST::codogenerator()
{
	val = definition;
}

void SymbolIdAST::codogenerator()
{
	auto it = type_id.find(definition);

	data_type = it->second; 
	val =definition;
}

void BreakAST::codogenerator() {}


void CodGen::startCodGen(AST *tree, string file_path)
{
	setFileName(file_path);

	system("mkdir asm");
	
	handleProlog();

	RootAST *root = static_cast<RootAST*>(tree);
	
	root->codogenerator();

	handleEpilog();
}

void CodGen::setFileName(string file_path)
{
	int start_pos = file_path.rfind("/");
	int end_pos = file_path.rfind(".");	

	asm_file_name = file_path.substr(start_pos + 1, end_pos - start_pos - 1);
	
	src_file_name = asm_file_name + ".c";
	exc_file_name = asm_file_name + ".out";
	asm_file_name += ".s";	
}

void CodGen::handleAsmMov()
{
	++offset;

	ofstream file ("asm/" + asm_file_name, ios::app);

	if (command == "=") {

		if (data_type == "int")
			file << "\t\tmov\t\tDWORD PTR [rbp-" + to_string(offset * 4) + "], " + val<<endl;
	}

	else if (command == "return")
		file << "\t\tmov\t\teax, " + val<<endl;

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

void CodGen::printAsm()
{
	string asm_info;

	ifstream file ("asm/" + asm_file_name);

	getline (file, asm_info, '\0');

	cout<<asm_info<<endl;

	file.close();
}

void CodGen::compileAsmFile()
{
	string comp = "gcc asm/" + asm_file_name + " -no-pie -o asm/" + exc_file_name;

	if (!system(comp.c_str()))
		cout <<"Done: "<<src_file_name<<" -> "<< asm_file_name<<" -> "<<exc_file_name<<endl;
}