#include <gtest/gtest.h>
#include "Parser.h"

TEST(parser_test, parseMainFunction)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "main(int argc, const char **argv) {int a = 2;}";
	lexer->new_file_string = "main(int argc, const char **argv) {int a = 2;}";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseMainFunction(token, lexer);

	MainFunctionAST *main_func = static_cast<MainFunctionAST*>(result); 

    EXPECT_EQ("main", main_func->definition);
}

TEST(parser_test, parseMainFunctionArgs)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "(int argc, const char **argv)";
	lexer->new_file_string = "(int argc, const char **argv)";

	lexer->makeSpaces();

	result = parser->parseMainFunctionArgs(lexer);

	MainFunctionArgsAST *main_func_args = static_cast<MainFunctionArgsAST*>(result); 

    EXPECT_EQ("ARGUMENTS", main_func_args->definition);
}

TEST(parser_test, parseMainFunctionBody)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "{int a = 2;}";
	lexer->new_file_string = "{int a = 2;}";

	lexer->makeSpaces();

	result = parser->parseMainFunctionBody(lexer);

	MainFunctionBodyAST *main_func_body = static_cast<MainFunctionBodyAST*>(result); 

    EXPECT_EQ("BODY", main_func_body->definition);
}