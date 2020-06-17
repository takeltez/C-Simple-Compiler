#include "Lexer.h"

void Lexer::print(Token token)
{
	cout<<"Loc=<"<<token.getLine()<<":"<<token.getPos()<<">	";
	cout<<token.getTokenClass()<<"		"<<token.getLexeme()<<endl;

	if (token.getTokenClass() == "unknown" || token.getTokenClass() == "unacceptable_symbol"
		 || token.getTokenClass() == "not_symbol_length")

		exit(1);
}
