#include "Parser.h"

AssignmentAST::AssignmentAST(AST *r_operand, AST *l_operand, Token token)
{
	this->definition = token.getLexeme();
	this->r_operand = r_operand;
	this->l_operand = l_operand;
}

void AssignmentAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	l_operand->print(lvl + 1);
	r_operand->print(lvl + 1);
}

LogicOperationAST::LogicOperationAST(AST *r_operand, AST *l_operand, Token token)
{
	this->definition = token.getLexeme();
	this->r_operand = r_operand;
	this->l_operand = l_operand;
}

void LogicOperationAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	l_operand->print(lvl + 1);
	r_operand->print(lvl + 1);
}

TernarOperationAST::TernarOperationAST(AST *r_operand, AST *l_operand, Token token)
{
	this->definition = token.getLexeme();
	this->r_operand = r_operand;
	this->l_operand = l_operand;
}

void TernarOperationAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	l_operand->print(lvl + 1);
	r_operand->print(lvl + 1);
}

BinOperationAST::BinOperationAST(AST *r_operand, AST *l_operand, Token token)
{
	this->definition = token.getLexeme();
	this->r_operand = r_operand;
	this->l_operand = l_operand;
}

void BinOperationAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	l_operand->print(lvl + 1);
	r_operand->print(lvl + 1);
}

UnaryOperationAST::UnaryOperationAST(AST *operand, Token token)
{
	this->definition = token.getLexeme();
	this->operand = operand;
}

void UnaryOperationAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	operand->print(lvl + 1);
}

PointerAST::PointerAST(AST *identificator, Token token)
{
	this->definition = token.getLexeme();
	this->identificator = identificator;
}

void PointerAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;

	identificator->print(lvl + 1);
}