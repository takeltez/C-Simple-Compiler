#include "Parser.h"

IfAST::IfAST(AST *condition, AST *body, Token token)
{
	this->definition = token.getLexeme();
	this->body = body;
	this->condition = condition;
}

IfBodyAST::IfBodyAST(vector <AST*> blocks) 
{
	this->definition = "BODY";
	this->blocks = blocks;
}

IfConditionAST::IfConditionAST(vector <AST*> blocks) 
{
	this->definition = "CONDITION";
	this->blocks = blocks;
}