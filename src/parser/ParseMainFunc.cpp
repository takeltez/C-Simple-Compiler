#include "Parser.h"

extern vector <AST*> blocks;

AST *Parser::parseMainFunction(Token token, Lexer *lexer) 
{
	MainFunctionAST *main_func; 
	AST *main_func_Body, *main_func_args;
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
		main_func_args = handler(tok, lexer);

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
		main_func_Body = handler(tok, lexer);

	else {
		while (tok.getLexeme() != "}")
			tok = getNextTok(lexer);
	}

	if (main_func_Body && main_func_args)
		main_func = new MainFunctionAST(main_func_args, main_func_Body, token);

	Parser::prev_token.setLexeme("");

  	return main_func;
}

AST *Parser::parseMainFunctionArgs(Lexer *lexer)
{
	Token tok, prev;
	MainFunctionArgsAST *main_func_args;
	bool error;

	while (tok.getLexeme() != ")") 
	{
		prev = tok;
		tok = getNextTok(lexer);

		checkSemicolonAndCommaError(tok, prev);

		error = CheckLeftParenError(tok);

		if(error)
			break;

		if (checkMainFuncArgsTok(tok)) 
			blocks.push_back(handler(tok, lexer));
	}
	
	if (!blocks.empty())
		main_func_args = new MainFunctionArgsAST(blocks);

	blocks.clear();

	return main_func_args;
}

AST *Parser::parseMainFunctionBody(Lexer *lexer)
{
	Token tok, prev;
	MainFunctionBodyAST *main_func_Body;

	while (tok.getLexeme() != "}") 
	{	
		prev = tok;
		tok = getNextTok(lexer);
	
		checkSemicolonAndCommaError(tok, prev);

		if (checkBodyTok(tok))
			blocks.push_back(handler(tok, lexer));
	}

	if (!blocks.empty())
		main_func_Body = new MainFunctionBodyAST(blocks);

	blocks.clear();

	return main_func_Body;
}