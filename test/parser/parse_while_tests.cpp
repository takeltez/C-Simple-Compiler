#include <gtest/gtest.h>
#include "Parser.h"

TEST(parser_test, parseWhile)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "while (a == 5){int a = 2;}";
	lexer->new_file_string = "while (a == 5){int a = 2;}";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseWhile(token, lexer);

	WhileAST *key_word_while = static_cast<WhileAST*>(result); 

    EXPECT_EQ("while", key_word_while->definition);
}

TEST(parser_test, parseWhileCondition)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "(i < b)";
	lexer->new_file_string = "(i < b)";

	lexer->makeSpaces();

	result = parser->parseWhileCondition(lexer);

	WhileConditionAST *while_cond = static_cast<WhileConditionAST*>(result); 

    EXPECT_EQ("CONDITION", while_cond->definition);
}

TEST(parser_test, parseWhileBody)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "{int a = 2;}";
	lexer->new_file_string = "{int a = 2;}";

	lexer->makeSpaces();

	result = parser->parseForBody(lexer);

	WhileBodyAST *while_body = static_cast<WhileBodyAST*>(result); 

    EXPECT_EQ("BODY", while_body->definition);
}