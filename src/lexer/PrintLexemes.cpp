#include "Lexer.h"

void Lexer::print(Token token)
{
	cout<<"Loc=<"<<token.getLine()<<":"<<token.getPos()<<">	";
	cout<<token.getTokenClass()<<"		"<<token.getLexeme()<<endl;
}
