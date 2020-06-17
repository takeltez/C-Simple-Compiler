#include "Parser.h"

extern vector <AST*> blocks;

AST *Parser::parseIf(Token token, Lexer *lexer) 
{
	IfAST *key_word_if; 
	AST *if_body, *if_cond;
	Token tok;
	
	Parser::prev_token = token;

	while (tok.getLexeme() != "(") 
	{
		tok = getNextTok(lexer);
		CheckRightParenError(tok, token);
	}

	if_cond = handler(tok, lexer);

	while (tok.getLexeme() != "{") 
	{
		tok = getNextTok(lexer);
		checkRightBraceError(tok);
	}

	if_body = handler(tok, lexer);

	if (if_body && if_cond)
		key_word_if = new IfAST(if_cond, if_body, token);

	Parser::prev_token.setLexeme("");

  	return key_word_if;
}

AST *Parser::parseIfCondition(Lexer *lexer)
{
	Token tok;
	IfConditionAST *if_cond;
	vector <AST*> if_blocks;
	int old_size = blocks.size();

	while (tok.getLexeme() != ")" && Parser::curr_token.getLexeme() != ")") 
	{
		tok = getNextTok(lexer);

		CheckLeftParenError(tok);

		if (checkIfConditionTok(tok)) 
			blocks.push_back(handler(tok, lexer));
	}

	for (int i = old_size; i < blocks.size(); ++i)
		if_blocks.push_back(blocks[i]);
	
	blocks.erase(blocks.begin() + old_size, blocks.begin() + blocks.size());
	
	if (!if_blocks.empty()) 
		if_cond = new IfConditionAST(if_blocks);

	Parser::curr_token.setLexeme("");

	return if_cond;
}

AST *Parser::parseIfBody(Lexer *lexer)
{
	Token tok, prev, buff;
	IfBodyAST *if_body;
	vector <AST*> if_blocks;
	int old_size = blocks.size();

	buff = Parser::prev_token;

	while (tok.getLexeme() != "}") 
	{
		prev = tok;
		tok = getNextTok(lexer);

		checkSemicolonAndCommaError(tok, prev);

		if (checkBodyTok(tok)) {
			blocks.push_back(handler(tok, lexer));
			Parser::prev_token = tok;
		}

		Parser::curr_token = tok;
	}

	for (int i = old_size; i < blocks.size(); ++i)
		if_blocks.push_back(blocks[i]);

	blocks.erase(blocks.begin() + old_size, blocks.begin() + blocks.size());
	
	if (!if_blocks.empty()) 
		if_body = new IfBodyAST(if_blocks);

	Parser::prev_token = buff;
	
	return if_body;
}

AST *Parser::parseElse(Token token, Lexer *lexer)
{
	Token tok, prev, buff;
	ElseAST *key_word_else;
	vector <AST*> else_blocks;
	int old_size = blocks.size();

	buff = Parser::prev_token;

	Parser::curr_token.setLexeme("");
	
	while (tok.getLexeme() != "}" && Parser::curr_token.getLexeme() != "}") 
	{	
		prev = tok;
		tok = getNextTok(lexer);

		checkSemicolonAndCommaError(tok, prev);

		if (checkBodyTok(tok)) {
			blocks.push_back(handler(tok, lexer));
			Parser::prev_token = tok;
		}
	}

	for (int i = old_size; i < blocks.size(); ++i)
		else_blocks.push_back(blocks[i]);

	blocks.erase(blocks.begin() + old_size, blocks.begin() + blocks.size());
	
	if (!else_blocks.empty()) 
		key_word_else = new ElseAST(else_blocks, token);

	Parser::prev_token = buff;
	Parser::curr_token.setLexeme("");
	
	return key_word_else;
}