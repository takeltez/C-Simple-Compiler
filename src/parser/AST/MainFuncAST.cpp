#include "Parser.h"

MainFunctionAST::MainFunctionAST(AST *args, AST *body, Token token)
{
	this->definition = token.getLexeme();
	this->body = body;
	this->args = args;
}

MainFunctionBodyAST::MainFunctionBodyAST(vector <AST*> blocks) 
{
	this->definition = "BODY";
	this->blocks = blocks;
}

MainFunctionArgsAST::MainFunctionArgsAST(vector <AST*> args) 
{
	this->definition = "ARGUMENTS";
	this->args = args;
}