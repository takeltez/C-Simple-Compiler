#include "Parser.h"

DataTypeAST::DataTypeAST(AST *identificator, Token token)
{
	this->definition = token.getLexeme();
	this->identificator = identificator;
}

void DataTypeAST::print(int lvl)
{
	level(lvl);

	cout<<definition<<endl;

	identificator->print(lvl + 1);
}

ConstAST::ConstAST(AST *identificator, Token token)
{
	this->definition = token.getLexeme();
	this->identificator = identificator;
}

void ConstAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	identificator->print(lvl + 1);
}

PrintfAST::PrintfAST(vector <AST*> params, Token token)
{
	this->definition = token.getLexeme();
	this->params = params;
}

void PrintfAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < params.size(); ++i)
		params[i]->print(lvl + 1);
}

ReturnAST::ReturnAST(AST *identificator, Token token)
{
	this->definition = token.getLexeme();
	this->identificator = identificator;
}

void ReturnAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	identificator->print(lvl + 1);
}