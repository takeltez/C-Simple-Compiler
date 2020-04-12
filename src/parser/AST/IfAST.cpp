#include "Parser.h"

IfAST::IfAST(AST *condition, AST *body, Token token)
{
	this->definition = token.getLexeme();
	this->body = body;
	this->condition = condition;
}

void IfAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	condition->print(lvl + 1);
	body->print(lvl + 1);
}

IfBodyAST::IfBodyAST(vector <AST*> blocks) 
{
	this->definition = "BODY";
	this->blocks = blocks;
}

void IfBodyAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->print(lvl + 1);
}

IfConditionAST::IfConditionAST(vector <AST*> blocks) 
{
	this->definition = "CONDITION";
	this->blocks = blocks;
}

void IfConditionAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->print(lvl + 1);
}