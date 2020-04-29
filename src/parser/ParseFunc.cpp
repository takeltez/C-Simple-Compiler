#include "Parser.h"

extern vector <AST*> blocks;

AST *Parser::parseFunction(Token token, Lexer *lexer) 
{
	FunctionAST *func; 
	AST *func_Body, *func_args;
	Token tok;
	bool error;

	Parser::prev_token = token;

	while (tok.getLexeme() != "(") 
	{
		tok = getNextTok(lexer);
		error = CheckRightParenError(tok, token);

		if (error)
			break;
	}

	if (!error)
		func_args = handler(tok, lexer);

	else {
		while (tok.getLexeme() != ")")
			tok = getNextTok(lexer);
	}
	
	error = false;

	while (tok.getLexeme() != "{") {

		tok = getNextTok(lexer);
		error = checkRightBraceError(tok);
	
		if (error)
			break;
	}

	if (!error)  
		func_Body = handler(tok, lexer);

	else {
		while (tok.getLexeme() != "}")
			tok = getNextTok(lexer);
	}

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
	bool error;

	while (tok.getLexeme() != ")") 
	{
		prev = tok;
		tok = getNextTok(lexer);

		checkSemicolonAndCommaError(tok, prev);

		error = CheckLeftParenError(tok);

		if(error)
			break;

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