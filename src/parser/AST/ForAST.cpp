#include "Parser.h"

ForAST::ForAST(AST *condition, AST *body, Token token)
{
	this->definition = token.getLexeme();
	this->body = body;
	this->condition = condition;
}

ForBodyAST::ForBodyAST(vector <AST*> blocks) 
{
	this->definition = "BODY";
	this->blocks = blocks;
}

ForConditionAST::ForConditionAST(vector <AST*> blocks) 
{
	this->definition = "CONDITION";
	this->blocks = blocks;
}