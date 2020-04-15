#include "Parser.h"

extern vector <AST*> blocks;

AST *Parser::parseStringLexeme(Token token)
{
	StringLexemeAST *text = new StringLexemeAST(token);

	return text;
}

AST *Parser::parseSymbolLexeme(Token token)
{
	SymbolLexemeAST *text = new SymbolLexemeAST(token);

	return text;
}

AST *Parser::parseDigitId(Token token)
{		
	DigitIdAST *val = new DigitIdAST(token);

	return val;
}

AST *Parser::parseSymbolId(Token token)
{		
	SymbolIdAST *var = new SymbolIdAST(token);

	return var;
}

AST *Parser::parseBreak(Token token, Lexer *lexer)
{		
	BreakAST *key_word_break = new BreakAST(token);

	Token next_tok = getNextTok(lexer);

	checkEndOfOperatorError(token, next_tok);

	return key_word_break;
}