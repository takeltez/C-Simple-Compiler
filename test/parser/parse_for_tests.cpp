#include <gtest/gtest.h>
#include "Parser.h"

TEST(parser_test, parseFor)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "for (int i = b + 1; i < 10; ++i){int a = 2;}";
	lexer->new_file_string = "for (int i = b + 1; i < 10; ++i){int a = 2;}";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseFor(token, lexer);

	ForAST *key_word_for = static_cast<ForAST*>(result); 

    EXPECT_EQ("for", key_word_for->definition);
}

TEST(parser_test, parseForCondition)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "(int i = b + 1; i < 10; ++i)";
	lexer->new_file_string = "(int i = b + 1; i < 10; ++i)";

	lexer->makeSpaces();

	result = parser->parseForCondition(lexer);

	ForConditionAST *for_cond = static_cast<ForConditionAST*>(result); 

    EXPECT_EQ("CONDITION", for_cond->definition);
}

TEST(parser_test, parseForBody)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "{int a = 2;}";
	lexer->new_file_string = "{int a = 2;}";

	lexer->makeSpaces();

	result = parser->parseForBody(lexer);

	ForBodyAST *for_body = static_cast<ForBodyAST*>(result); 

    EXPECT_EQ("BODY", for_body->definition);
}