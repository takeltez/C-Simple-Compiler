#include "Parser.h"

RootAST::RootAST(vector <AST*> blocks) 
{
	this->definition = "START";
	this->blocks = blocks;
}
