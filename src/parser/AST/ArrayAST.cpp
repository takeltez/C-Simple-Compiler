#include "Parser.h"

ArrayDataAST::ArrayDataAST(vector <AST*> blocks) 
{
	this->definition = "ArrayData";
	this->blocks = blocks;
}

ArrayNameAST::ArrayNameAST(AST *identificator, Token token)
{
	this->definition = token.getLexeme();
	this->identificator = identificator;
}