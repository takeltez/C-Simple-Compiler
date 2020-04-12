#include "Parser.h"

extern vector <AST*> blocks;

AST *Parser::parseArrayData(Lexer *lexer)
{
	Token tok;
	ArrayDataAST *arr_data;
	vector <AST*> arr_blocks;
	int old_size = blocks.size();

	while (!checkArrayDataTok(tok))
		tok = getNextTok(lexer);
	
	while (checkArrayDataTok(tok)) 
	{	
		blocks.push_back(handler(tok, lexer));
		tok = getNextTok(lexer);

		if (tok.getLexeme() == ",") {
			while (!checkArrayDataTok(tok))
				tok = getNextTok(lexer);
		}
	}

	for (int i = old_size; i < blocks.size(); ++i) 
		arr_blocks.push_back(blocks[i]);
	
	blocks.erase(blocks.begin() + old_size, blocks.begin() + blocks.size());

	arr_data = new ArrayDataAST(arr_blocks);

	return arr_data;
}

AST *Parser::parseArrayName(Token token, Lexer *lexer) 
{
	ArrayNameAST *arr_name; 
	AST *identificator;
	Token tok;

	while (!checkArrayNameTok(tok))
		tok = getNextTok(lexer);
	
	if (checkArrayNameTok(tok)) {

		identificator = handler(tok, lexer);

		if (identificator) {
			if (tok.getLexeme() == "]")
				arr_name = new ArrayNameAST(NULL, token);
			else
				arr_name = new ArrayNameAST(identificator, token);
		}
	}

	return arr_name;
}