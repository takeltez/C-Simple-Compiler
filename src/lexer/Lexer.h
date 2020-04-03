#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include "Token.h"

using namespace std;

#define CountOfFiles 9
#define NOLEXEME "Error"

const regex DICT_ID = regex("^[A-Za-z_][A-Za-z0-9_]*$");
const regex DICT_NUM_DEC = regex("^[1-9][0-9]*$");
const regex DICT_NUM_HEX = regex("^0[xX][A-Fa-f0-9]+$");
const regex DICT_NUM_BIN = regex("^0[bB][01]+$");
const regex DICT_NUM_OCT = regex("^0[0-7]+$");

class Lexer
{
	private:
		int newLineCount = 1;
		int file_pos = 0;
		bool e_o_f = false;
		int start_pos = 0;

		vector <string> DICT_SPACE =  {".", ", ", ";", "(", ")", "{", "}", "[", "]","+=", "-=", "*=", "/=", 
												"%=", "!=", "++", "+", "--", "-", "*", "/", "%", "==", ">=", "<=", ">", "<", "=", "#", "&&", "&", "||" "!"};
		vector <string> stdFuncs;
		vector <string> parens;
		vector <string> dataTypes;
		vector <string> keyWords;
		vector <string> specSymbols;
		vector <string> stdHeaders;
		vector <string> arithOps;
		vector <string> logicOps;
		vector <string> compOps;
		vector <vector<string>> stdLexemesVec = {keyWords, stdHeaders, stdFuncs, parens, specSymbols, dataTypes, compOps, logicOps, arithOps};

	public:
		string file_string;
		string new_file_string;
		Lexer();
		void makeSpaces();
		void setStartFileString(string file_path);
		void delSimpleComment();
		string checkStdLexemes(string lexeme);
		string shrinkLexemeFromString (int *start_pos);
		string findStringLexeme(int newLineCounter, string *lexeme, int *lexeme_pos);
		string findSymbolLexeme(int newLineCounter, string *lexeme, int *lexeme_pos);
		string findStandartLexeme(int newLineCounter, string lexeme, int *lexeme_pos);
		string findDigitLexeme(int newLineCounter, string lexeme, int *lexeme_pos);
		string findVariables(int newLineCounter, string lexeme, int *lexeme_pos, int start_pos);
		string findUnacceptSymbols(int newLineCounter, string lexeme, int *lexeme_pos);
		Token getNextToken();
};
