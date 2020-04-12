#include "Parser.h"

ArrayDataAST::ArrayDataAST(vector <AST*> blocks) 
{
	this->definition = "ArrayData";
	this->blocks = blocks;
}

void ArrayDataAST::print(int lvl)
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->print(lvl);
}

ArrayNameAST::ArrayNameAST(AST *identificator, Token token)
{
	this->definition = token.getLexeme();
	this->identificator = identificator;
}

void ArrayNameAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;
		
	if (identificator != NULL)
		identificator->print(lvl + 1);
}