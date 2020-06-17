#include <gtest/gtest.h>
#include "Parser.h"

TEST(parser_test, parseFunction)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "main(int argc, const char **argv) {int a = 2;}";
	lexer->new_file_string = "main(int argc, const char **argv) {int a = 2;}";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseFunction(token, lexer);

	FunctionAST *func = static_cast<FunctionAST*>(result); 

    EXPECT_EQ("main", func->definition);
}

TEST(parser_test, parseFunctionArgs)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "(int argc, const char **argv)";
	lexer->new_file_string = "(int argc, const char **argv)";

	lexer->makeSpaces();

	result = parser->parseFunctionArgs(lexer);

	FunctionArgsAST *func_args = static_cast<FunctionArgsAST*>(result); 

    EXPECT_EQ("ARGUMENTS", func_args->definition);
}

TEST(parser_test, parseFunctionBody)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "{int a = 2;}";
	lexer->new_file_string = "{int a = 2;}";

	lexer->makeSpaces();

	result = parser->parseFunctionBody(lexer);

	FunctionBodyAST *func_body = static_cast<FunctionBodyAST*>(result); 

    EXPECT_EQ("BODY", func_body->definition);
}