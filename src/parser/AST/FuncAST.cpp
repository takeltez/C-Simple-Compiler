#include "Parser.h"

FunctionAST::FunctionAST(AST *args, AST *body, Token token)
{
	this->definition = token.getLexeme();
	this->body = body;
	this->args = args;
}

FunctionBodyAST::FunctionBodyAST(vector <AST*> blocks) 
{
	this->definition = "BODY";
	this->blocks = blocks;
}

FunctionArgsAST::FunctionArgsAST(vector <AST*> args) 
{
	this->definition = "ARGUMENTS";
	this->args = args;
}