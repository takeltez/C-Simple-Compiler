#include "Parser.h"

void AST::level(int lvl) 
{
	for (int i = 0; i < lvl; ++i)
		cout<<"----";
	
	cout<<"|";
}

void AssignmentAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	l_operand->print(lvl + 1);
	r_operand->print(lvl + 1);
}

void LogicOperationAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	l_operand->print(lvl + 1);
	r_operand->print(lvl + 1);
}

void TernarOperationAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	l_operand->print(lvl + 1);
	r_operand->print(lvl + 1);
}

void BinOperationAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	l_operand->print(lvl + 1);
	r_operand->print(lvl + 1);
}

void UnaryOperationAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	operand->print(lvl + 1);
}

void PointerAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	identificator->print(lvl + 1);
}

void ArrayDataAST::print(int lvl)
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->print(lvl);
}

void ArrayNameAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;
		
	if (identificator != NULL)
		identificator->print(lvl + 1);
}

void ForAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	condition->print(lvl + 1);
	body->print(lvl + 1);
}

void ForBodyAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->print(lvl + 1);
}

void ForConditionAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->print(lvl + 1);
}

void WhileAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	condition->print(lvl + 1);
	body->print(lvl + 1);
}

void WhileBodyAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->print(lvl + 1);
}

void WhileConditionAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->print(lvl + 1);
}

void IfAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	condition->print(lvl + 1);
	body->print(lvl + 1);
}

void IfBodyAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;
	
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->print(lvl + 1);
}

void IfConditionAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;
	
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->print(lvl + 1);
}

void MainFunctionAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	args->print(lvl + 1);
	body->print(lvl + 1);
}

void MainFunctionBodyAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->print(lvl + 1);
}

void MainFunctionArgsAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < args.size() - 1; ++i)
		args[i]->print(lvl + 1);	
}

void DataTypeAST::print(int lvl)
{
	level(lvl);

	cout<<definition<<endl;

	identificator->print(lvl + 1);
}

void ConstAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	identificator->print(lvl + 1);
}

void PrintfAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < params.size(); ++i)
		params[i]->print(lvl + 1);
}

void ReturnAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	identificator->print(lvl + 1);
}


void StringLexemeAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;
}

void SymbolLexemeAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;
}

void DigitIdAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;
}

void SymbolIdAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;
}

void BreakAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;
}

void printAST(AST *tree)
{
	DataTypeAST *data_type = static_cast<DataTypeAST*>(tree);
	
	data_type->print(1);

	cout<<endl;
}
