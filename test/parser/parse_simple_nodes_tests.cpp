#include <gtest/gtest.h>
#include "Parser.h"

TEST(parser_test, parseStringLexeme)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "AlexeyGenaEugeneAlexey";
	lexer->new_file_string = "AlexeyGenaEugeneAlexey";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseStringLexeme(token);

	StringLexemeAST *text = static_cast<StringLexemeAST*>(result); 

    EXPECT_EQ("AlexeyGenaEugeneAlexey", text->definition);
}

TEST(parser_test, parseSymbolLexeme)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = 'q';
	lexer->new_file_string = 'q';

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseSymbolLexeme(token);

	SymbolLexemeAST *text = static_cast<SymbolLexemeAST*>(result); 

    EXPECT_EQ("q", text->definition);
}

TEST(parser_test, parseDigitId)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "1";
	lexer->new_file_string = "1";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseDigitId(token);

	DigitIdAST *val = static_cast<DigitIdAST*>(result); 

    EXPECT_EQ("1", val->definition);
}

TEST(parser_test, parseSymbolId)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "token";
	lexer->new_file_string = "token";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseSymbolId(token);

	SymbolIdAST *var = static_cast<SymbolIdAST*>(result); 

    EXPECT_EQ("token", var->definition);
}

TEST(parser_test, parseBreak)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "break;";
	lexer->new_file_string = "break;";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseBreak(token, lexer);

	BreakAST *key_word_break = static_cast<BreakAST*>(result); 

    EXPECT_EQ("break", key_word_break->definition);
}
