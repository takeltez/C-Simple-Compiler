#include <gtest/gtest.h>
#include "Parser.h"

TEST(parser_test, parseDataType)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "char c = a";
	lexer->new_file_string = "char c = a";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseDataType(token, lexer);

	DataTypeAST *data_type = static_cast<DataTypeAST*>(result); 

    EXPECT_EQ("char", data_type->definition);
}

TEST(parser_test, parseConst)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "const char c = a";
	lexer->new_file_string = "const char c = a";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseConst(token, lexer);

	ConstAST *key_word_const = static_cast<ConstAST*>(result); 

    EXPECT_EQ("const", key_word_const->definition);
}

TEST(parser_test, parsePrintf)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "printf(\"nod: %d\n\", nod);";
	lexer->new_file_string = "printf(\"nod: %d\n\", nod);";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parsePrintf(token, lexer);

	PrintfAST *func_printf = static_cast<PrintfAST*>(result); 

    EXPECT_EQ("printf", func_printf->definition);
}

TEST(parser_test, parseReturn)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "return 0";
	lexer->new_file_string = "return 0";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseReturn(token, lexer);

	ReturnAST *key_word_return = static_cast<ReturnAST*>(result); 

    EXPECT_EQ("return", key_word_return->definition);
}