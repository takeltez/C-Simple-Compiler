#include "Parser.h"

extern vector <AST*> blocks;

AST *Parser::parseFunction(Token token, Lexer *lexer) 
{
	FunctionAST *func; 
	AST *func_Body, *func_args;
	Token tok;

	Parser::prev_token = token;

	while (tok.getLexeme() != "(") 
	{
		tok = getNextTok(lexer);
		CheckRightParenError(tok, token);
	}

	func_args = handler(tok, lexer);

	while (tok.getLexeme() != "{") 
	{
		tok = getNextTok(lexer);
		checkRightBraceError(tok);
	}

	func_Body = handler(tok, lexer);

	if (func_Body && func_args)
		func = new FunctionAST(func_args, func_Body, token);

	Parser::prev_token.setLexeme("");

  	return func;
}

AST *Parser::parseFunctionArgs(Lexer *lexer)
{
	Token tok, prev;
	FunctionArgsAST *func_args;
	vector <AST*> func_blocks;
	int old_size = blocks.size();

	while (tok.getLexeme() != ")") 
	{
		prev = tok;
		tok = getNextTok(lexer);

		checkSemicolonAndCommaError(tok, prev);
		CheckLeftParenError(tok);

		if (checkFuncArgsTok(tok)) 
			blocks.push_back(handler(tok, lexer));
	}
	
	for (int i = old_size; i < blocks.size(); ++i)
		func_blocks.push_back(blocks[i]);

	blocks.erase(blocks.begin() + old_size, blocks.begin() + blocks.size());

	func_args = new FunctionArgsAST(func_blocks);

	return func_args;
}

AST *Parser::parseFunctionBody(Lexer *lexer)
{
	Token tok, prev;
	FunctionBodyAST *func_Body;
	vector <AST*> func_blocks;
	int old_size = blocks.size();

	while (tok.getLexeme() != "}") 
	{	
		prev = tok;
		tok = getNextTok(lexer);
	
		checkSemicolonAndCommaError(tok, prev);

		if (checkBodyTok(tok))
			blocks.push_back(handler(tok, lexer));
	}

	for (int i = old_size; i < blocks.size(); ++i)
		func_blocks.push_back(blocks[i]);

	blocks.erase(blocks.begin() + old_size, blocks.begin() + blocks.size());

	func_Body = new FunctionBodyAST(func_blocks);

	return func_Body;
}