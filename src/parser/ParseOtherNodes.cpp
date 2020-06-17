#include "Parser.h"

extern vector <AST*> blocks;

AST *Parser::parseDataType(Token token, Lexer *lexer) 
{
	DataTypeAST *data_type; 
	AST *identificator;
	Token tok, buff;

	buff = Parser::prev_token;

	Parser::prev_token = token;

	while (!checkDataTypeTok(tok)) 
	{
		tok = getNextTok(lexer);
		checkDataTypeNextTokError(tok, token);
	}

	identificator = handler(tok, lexer);

	if (identificator)
		data_type = new DataTypeAST(identificator, token);

	Parser::prev_token = buff;

  	return data_type;
}

AST *Parser::parseConst(Token token, Lexer *lexer) 
{
	ConstAST *key_word_const; 
	AST *data_type;
	Token tok, buff;

	buff = Parser::prev_token;

	Parser::prev_token = token;

	while (!checkConstTok(tok)) 
	{
		tok = getNextTok(lexer);
		checkConstNextTokError(tok, token);
	}

	data_type = handler(tok, lexer);

	if (data_type)
		key_word_const = new ConstAST(data_type, token);

	Parser::prev_token = buff;

  	return key_word_const;
}

AST *Parser::parsePrintf(Token token, Lexer *lexer)
{
	Token tok, next_tok;
	PrintfAST *func_printf;
	vector <AST*> printf_blocks;
	int old_size = blocks.size();

	while (tok.getLexeme() != "(")
		tok = getNextTok(lexer);

	while (tok.getLexeme() != ")") 
	{
		tok = getNextTok(lexer);

		if (checkPrintfTok(tok))
			blocks.push_back(handler(tok, lexer));	
	}

	next_tok = getNextTok(lexer);
	
	checkEndOfOperatorError(tok, next_tok);

	for (int i = old_size; i < blocks.size(); ++i)
		printf_blocks.push_back(blocks[i]);

	blocks.erase(blocks.begin() + old_size, blocks.begin() + blocks.size());

	if (!printf_blocks.empty())
		func_printf = new PrintfAST(printf_blocks, token);

	return func_printf;
}

AST *Parser::parseReturn(Token token, Lexer *lexer)
{
	Token tok;
	ReturnAST *key_word_return;
	AST *identificator;

	while (!checkReturnTok(tok)) 
	{
		tok = getNextTok(lexer);
		checkReturnNextTokError(tok, token);
	}
 
	identificator = handler(tok, lexer);

	if (identificator)
		key_word_return = new ReturnAST(identificator, token);

	return key_word_return;
}

