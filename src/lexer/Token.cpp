#include "Token.h"

Token::Token() 	{}

Token::Token(string tokenClass, string lexeme, int line, int pos)
{
	this->tokenClass = tokenClass;
	this->lexeme = lexeme;
	this->line = line;
	this->pos = pos;
}

string Token::getTokenClass()
{
	return this->tokenClass;
}

string Token::getLexeme()
{
	return this->lexeme;
}

int Token::getLine()
{
	return this->line;
}

int Token::getPos()
{
	return this->pos;
}

void Token::setTokenClass (string tokenClass)
{
	this->tokenClass = tokenClass;
}

void Token::setLexeme (string lexeme)
{
	this->lexeme = lexeme;
}