#include "Parser.h"

WhileAST::WhileAST(AST *condition, AST *body, Token token)
{
	this->definition = token.getLexeme();
	this->body = body;
	this->condition = condition;
}

void WhileAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	condition->print(lvl + 1);
	body->print(lvl + 1);
}

WhileBodyAST::WhileBodyAST(vector <AST*> blocks) 
{
	this->definition = "BODY";
	this->blocks = blocks;
}

void WhileBodyAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < blocks.size(); ++i)
	blocks[i]->print(lvl + 1);
}

WhileConditionAST::WhileConditionAST(vector <AST*> blocks) 
{
	this->definition = "CONDITION";
	this->blocks = blocks;
}

void WhileConditionAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < blocks.size(); ++i)
	blocks[i]->print(lvl + 1);
}