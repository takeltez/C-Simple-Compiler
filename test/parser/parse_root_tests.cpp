#include <gtest/gtest.h>
#include "Parser.h"

TEST(parser_test, parseRoot)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "int main(int argc, const char **argv) {int a = 2;}";
	lexer->new_file_string = "int main(int argc, const char **argv) {int a = 2;}";

	lexer->makeSpaces();

	result = parser->parseRoot(lexer);

	RootAST *root = static_cast<RootAST*>(result); 

    EXPECT_EQ("START", root->definition);
}