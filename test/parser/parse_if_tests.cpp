#include <gtest/gtest.h>
#include "Parser.h"

TEST(parser_test, parseIf)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "if (int i = b + 1; i < 10; ++i) {int a = 2;}";
	lexer->new_file_string = "if (int i = b + 1; i < 10; ++i) {int a = 2;}";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseIf(token, lexer);

	IfAST *key_word_if = static_cast<IfAST*>(result); 

    EXPECT_EQ("if", key_word_if->definition);
}

TEST(parser_test, parseIfCondition)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "(i < b)";
	lexer->new_file_string = "(i < b)";

	lexer->makeSpaces();

	result = parser->parseIfCondition(lexer);

	IfConditionAST *if_cond = static_cast<IfConditionAST*>(result); 

    EXPECT_EQ("CONDITION", if_cond->definition);
}

TEST(parser_test, parseIfBody)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "{int a = 2;}";
	lexer->new_file_string = "{int a = 2;}";

	lexer->makeSpaces();

	result = parser->parseIfBody(lexer);

	IfBodyAST *if_body = static_cast<IfBodyAST*>(result); 

    EXPECT_EQ("BODY", if_body->definition);
}