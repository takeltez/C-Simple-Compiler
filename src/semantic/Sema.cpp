#include "Parser.h"

string data_type;

void ArrayDataAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void ArrayNameAST::semantic()
{		
	if (identificator != NULL)
		identificator->semantic();
}

void ForAST::semantic()
{
	condition->semantic();
	body->semantic();
}

void ForBodyAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void ForConditionAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void WhileAST::semantic()
{
	condition->semantic();
	body->semantic();
}

void WhileBodyAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void WhileConditionAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void IfAST::semantic()
{
	condition->semantic();
	body->semantic();
}

void IfBodyAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void IfConditionAST::semantic()
{	
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void MainFunctionAST::semantic()
{
	args->semantic();
	body->semantic();
}

void MainFunctionBodyAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void MainFunctionArgsAST::semantic()
{
	for (int i = 0; i < args.size() - 1; ++i)
		args[i]->semantic();	
}

void AssignmentAST::semantic()
{
	l_operand->semantic();
	r_operand->semantic();
}

void LogicOperationAST::semantic()
{
	l_operand->semantic();
	r_operand->semantic();
}

void TernarOperationAST::semantic()
{
	l_operand->semantic();
	r_operand->semantic();
}

void BinOperationAST::semantic()
{
	l_operand->semantic();
	r_operand->semantic();
}

void UnaryOperationAST::semantic()
{
	operand->semantic();
}

void PointerAST::semantic()
{
	identificator->semantic();
}

void DataTypeAST::semantic()
{
	data_type = definition;
	identificator->semantic();
}

void ConstAST::semantic()
{
	identificator->semantic();
}

void PrintfAST::semantic()
{
	data_type.clear();

	for (int i = 0; i < params.size(); ++i)
		params[i]->semantic();
}

void ReturnAST::semantic()
{
	identificator->semantic();
}

void StringLexemeAST::semantic()
{
	if (data_type != "char" && !data_type.empty())
		cout<<"Incorrect operators for operation '=': '"<<data_type<<"' and 'string'"<<endl;
}

void DigitIdAST::semantic()
{
	if (data_type != "int" && data_type != "double" && data_type != "float" && !data_type.empty())
		cout<<"Incorrect operators for operation '=': '"<<data_type<<"' and 'int'"<<endl;
}

void SymbolIdAST::semantic()
{
	
}

void BreakAST::semantic()
{
}

Sema::Sema() {}

void Sema::checkSemantic(AST *tree)
{
	DataTypeAST *data_type = static_cast<DataTypeAST*>(tree);
	
	data_type->semantic();
}