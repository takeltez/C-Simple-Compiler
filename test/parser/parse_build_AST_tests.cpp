#include <gtest/gtest.h>
#include "Parser.h"

TEST(parser_test, buildAST)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "int main(int argc, const char **argv) {int a = 2;}";
	lexer->new_file_string = "int main(int argc, const char **argv) {int a = 2;}";

	lexer->makeSpaces();

	result = parser->buildAST(lexer);

	RootAST *root = static_cast<RootAST*>(result); 

    EXPECT_EQ("START", root->definition);
}

TEST(parser_test, handler)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->setStartFileString("./examples/nod.c");

	Token token = parser->getNextTok(lexer);

	result = parser->handler(token, lexer);

	DataTypeAST *data_type = static_cast<DataTypeAST*>(result); 

    EXPECT_EQ("int", data_type->definition);
}