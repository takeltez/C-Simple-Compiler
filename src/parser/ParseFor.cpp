#include "Parser.h"

extern vector <AST*> blocks;

AST *Parser::parseFor(Token token, Lexer *lexer) 
{
	ForAST *key_word_for; 
	AST *for_body, *for_cond;
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
		for_cond = handler(tok, lexer);

	else {
		while (tok.getLexeme() != ")")
			tok = getNextTok(lexer);
	}
	
	error = false;

	if (Parser::curr_token.getLexeme() != "{") {
		while (tok.getLexeme() != "{") 
		{
			tok = getNextTok(lexer);
			error = checkRightBraceError(tok);
		
			if (error)
				break;
		}
	}

	if (!error)
		for_body = handler(tok, lexer);

	else {
		while (tok.getLexeme() != "}")
			tok = getNextTok(lexer);
	}

	if (for_body && for_cond)
		key_word_for = new ForAST(for_cond, for_body, token);

	Parser::prev_token.setLexeme("");

  	return key_word_for;
}

AST *Parser::parseForCondition(Lexer *lexer)
{
	Token tok, buff, prev;
	ForConditionAST *for_cond;
	vector <AST*> for_blocks;
	int old_size = blocks.size();
	bool error;
	
	buff = Parser::prev_token;

	while (tok.getLexeme() != ")") 
	{
		prev = tok;
		tok = getNextTok(lexer);

		checkSemicolonAndCommaError(tok, prev);

		error = CheckLeftParenError(tok);

		if(error)
			break;

		if (checkForConditionTok(tok)) {
			blocks.push_back(handler(tok, lexer));
			Parser::prev_token = tok;
		}
	}

	for (int i = old_size; i < blocks.size(); ++i)
		for_blocks.push_back(blocks[i]);

	blocks.erase(blocks.begin() + old_size, blocks.begin() + blocks.size());
	
	if (!for_blocks.empty())
		for_cond = new ForConditionAST(for_blocks);

	Parser::prev_token = buff;
	Parser::curr_token.setLexeme("");

	return for_cond;
}

AST *Parser::parseForBody(Lexer *lexer)
{
	Token tok, buff, prev;
	ForBodyAST *for_body;
	vector <AST*> for_blocks;
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
	}

	for (int i = old_size; i < blocks.size(); ++i) 
		for_blocks.push_back(blocks[i]);
	

	blocks.erase(blocks.begin() + old_size, blocks.begin() + blocks.size());
	
	if (!for_blocks.empty())
		for_body = new ForBodyAST(for_blocks);
	
	Parser::prev_token = buff;

	return for_body;
}