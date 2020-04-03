#include <gtest/gtest.h>
#include "Parser.h"

TEST(parser_test, parseArrayData)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "{1, 2, 3, 4, 5, 32, 65, 78, 5, 0}";
	lexer->new_file_string = "{1, 2, 3, 4, 5, 32, 65, 78, 5, 0}";

	lexer->makeSpaces();

	result = parser->parseArrayData(lexer);

	ArrayDataAST *arr_data = static_cast<ArrayDataAST*>(result); 

    EXPECT_EQ("ArrayData", arr_data->definition);
}

TEST(parser_test, parseArrayName)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "arr[]";
	lexer->new_file_string = "arr[]";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseArrayName(token, lexer);

	ArrayNameAST *arr_name = static_cast<ArrayNameAST*>(result); 

    EXPECT_EQ("arr", arr_name->definition);
}