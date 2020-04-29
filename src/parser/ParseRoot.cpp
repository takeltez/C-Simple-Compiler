#include "Parser.h"

extern vector <AST*> blocks;

AST *Parser::parseRoot(Lexer *lexer)
{
	Token tok;
	RootAST *root;
	int old_size = blocks.size();

	while (!checkRootTok(tok))
		tok = getNextTok(lexer);

	while (checkRootTok(tok)) {
		blocks.push_back(handler(tok, lexer));
		tok = getNextTok(lexer);

		if (tok.getLexeme() == ";" || tok.getLexeme() == ",")
			tok = getNextTok(lexer);
	}

	if (!blocks.empty())
		root = new RootAST(blocks);
	
	blocks.clear();

	return root;
}
