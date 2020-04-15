#include "Parser.h"

StringLexemeAST::StringLexemeAST(Token token)
{
	this->definition = token.getLexeme();
}

SymbolLexemeAST::SymbolLexemeAST(Token token)
{
	this->definition = token.getLexeme();
}

DigitIdAST::DigitIdAST(Token token)
{
	this->definition = stoi(token.getLexeme());
}

SymbolIdAST::SymbolIdAST(Token token)
{
	this->definition = token.getLexeme();
}

BreakAST::BreakAST(Token token)
{
	this->definition = token.getLexeme();
}