#include "Parser.h"

DataTypeAST::DataTypeAST(AST * identificator, Token token)
{
	this->definition = token.getLexeme();
	this->identificator = identificator;
}

ConstAST::ConstAST(AST * identificator, Token token)
{
	this->definition = token.getLexeme();
	this->identificator = identificator;
}

PrintfAST::PrintfAST(vector <AST*> params, Token token)
{
	this->definition = token.getLexeme();
	this->params = params;
}

ReturnAST::ReturnAST(AST *identificator, Token token)
{
	this->definition = token.getLexeme();
	this->identificator = identificator;
}