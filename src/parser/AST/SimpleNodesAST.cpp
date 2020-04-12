#include "Parser.h"

StringLexemeAST::StringLexemeAST(Token token)
{
	this->definition = token.getLexeme();
}

void StringLexemeAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;
}

DigitIdAST::DigitIdAST(Token token)
{
	this->definition = stoi(token.getLexeme());
}

void DigitIdAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;
}

SymbolIdAST::SymbolIdAST(Token token)
{
	this->definition = token.getLexeme();
}

void SymbolIdAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;
}

BreakAST::BreakAST(Token token)
{
	this->definition = token.getLexeme();
}

void BreakAST::print(int lvl)
{
	level(lvl);
	
	cout<<definition<<endl;
}