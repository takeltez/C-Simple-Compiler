#include "Parser.h"

AssignmentAST::AssignmentAST(AST *r_operand, AST *l_operand, Token token)
{
	this->definition = token.getLexeme();
	this->r_operand = r_operand;
	this->l_operand = l_operand;
}

LogicOperationAST::LogicOperationAST(AST *r_operand, AST *l_operand, Token token)
{
	this->definition = token.getLexeme();
	this->r_operand = r_operand;
	this->l_operand = l_operand;
}

TernarOperationAST::TernarOperationAST(AST *r_operand, AST *l_operand, Token token)
{
	this->definition = token.getLexeme();
	this->r_operand = r_operand;
	this->l_operand = l_operand;
}

BinOperationAST::BinOperationAST(AST *r_operand, AST *l_operand, Token token)
{
	this->definition = token.getLexeme();
	this->r_operand = r_operand;
	this->l_operand = l_operand;
}

UnaryOperationAST::UnaryOperationAST(AST *operand, Token token)
{
	this->definition = token.getLexeme();
	this->operand = operand;
}



PointerAST::PointerAST(AST *identificator, Token token)
{
	this->definition = token.getLexeme();
	this->identificator = identificator;
}