#include "Parser.h"

ForAST::ForAST(AST *condition, AST *body, Token token)
{
	this->definition = token.getLexeme();
	this->body = body;
	this->condition = condition;
}

void ForAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	condition->print(lvl + 1);
	body->print(lvl + 1);
}

ForBodyAST::ForBodyAST(vector <AST*> blocks) 
{
	this->definition = "BODY";
	this->blocks = blocks;
}

void ForBodyAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->print(lvl + 1);
}

ForConditionAST::ForConditionAST(vector <AST*> blocks) 
{
	this->definition = "CONDITION";
	this->blocks = blocks;
}

void ForConditionAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->print(lvl + 1);
}