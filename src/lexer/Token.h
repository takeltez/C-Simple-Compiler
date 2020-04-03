#pragma once
#include <iostream>
#include <string>

using namespace std;

class Token
{
	private:
		string tokenClass;
		string lexeme;
		int line;
		int pos;
	
	public:
		Token();
		Token(string tokenClass, string lexeme, int line, int pos);	
		string getTokenClass();
		string getLexeme();
		int getLine();
		int getPos();
		void setTokenClass (string tokenClass);
		void setLexeme (string lexeme);
};
