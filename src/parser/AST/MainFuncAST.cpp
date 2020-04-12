#include "Parser.h"

MainFunctionAST::MainFunctionAST(AST *args, AST *body, Token token)
{
	this->definition = token.getLexeme();
	this->body = body;
	this->args = args;
}

void MainFunctionAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	args->print(lvl + 1);
	body->print(lvl + 1);
}

MainFunctionBodyAST::MainFunctionBodyAST(vector <AST*> blocks) 
{
	this->definition = "BODY";
	this->blocks = blocks;
}

void MainFunctionBodyAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->print(lvl + 1);
}

MainFunctionArgsAST::MainFunctionArgsAST(vector <AST*> args) 
{
	this->definition = "ARGUMENTS";
	this->args = args;
}

void MainFunctionArgsAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < args.size() - 1; ++i)
		args[i]->print(lvl + 1);	
}