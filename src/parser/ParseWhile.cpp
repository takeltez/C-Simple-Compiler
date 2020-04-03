#include "Parser.h"

extern vector <AST*> blocks;

AST *Parser::parseWhile(Token token, Lexer *lexer) 
{
	WhileAST *key_word_while; 
	AST *while_body, *while_cond;
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
		while_cond = handler(tok, lexer);

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
		while_body = handler(tok, lexer);

	else {
		while (tok.getLexeme() != "}")
			tok = getNextTok(lexer);
	}
	
	if (while_body && while_cond)
		key_word_while = new WhileAST(while_cond, while_body, token);

	Parser::prev_token.setLexeme("");

  	return key_word_while;
}

AST *Parser::parseWhileCondition(Lexer *lexer)
{
	Token tok;
	WhileConditionAST *while_cond;
	vector <AST*> while_blocks;
	int old_size = blocks.size();
	bool error;

	while (tok.getLexeme() != ")" && Parser::curr_token.getLexeme() != ")") 
	{
		tok = getNextTok(lexer);

		error = CheckLeftParenError(tok);

		if(error)
			break;

		if (checkWhileConditionTok(tok))
			blocks.push_back(handler(tok, lexer));
	}

	for (int i = old_size; i < blocks.size(); ++i)
		while_blocks.push_back(blocks[i]);

	blocks.erase(blocks.begin() + old_size, blocks.begin() + blocks.size());
	
	if (!while_blocks.empty())
		while_cond = new WhileConditionAST(while_blocks);

	Parser::curr_token.setLexeme("");

	return while_cond;
}

AST *Parser::parseWhileBody(Lexer *lexer)
{
	Token tok, prev, buff;
	WhileBodyAST *while_body;
	vector <AST*> while_blocks;
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
		while_blocks.push_back(blocks[i]);
	
	blocks.erase(blocks.begin() + old_size, blocks.begin() + blocks.size());
	
	if (!while_blocks.empty())
		while_body = new WhileBodyAST(while_blocks);
	
	Parser::prev_token = buff;

	return while_body;
}