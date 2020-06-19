#include <gtest/gtest.h>
#include "Parser.h"

TEST(parser_test, parsePointer)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "*argv[]";
	lexer->new_file_string = "*argv[]";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parsePointer(token, lexer);

	PointerAST *ptr = static_cast<PointerAST*>(result); 

    EXPECT_EQ("*", ptr->definition);
}

TEST(parser_test, parseUnaryOperation)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "++i";
	lexer->new_file_string = "++i";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseUnaryOperation(token, lexer);

	UnaryOperationAST *uanry_op = static_cast<UnaryOperationAST*>(result); 

    EXPECT_EQ("++", uanry_op->definition);
}

/*TEST(parser_test, parseLogicOperation)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "&& b % i == 0";
	lexer->new_file_string = "&& b % i == 0";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseLogicOperation(token, lexer);

	LogicOperationAST *logic_op = static_cast<LogicOperationAST*>(result); 

    EXPECT_EQ("&&", logic_op->definition);
}

TEST(parser_test, parseTernarOperation)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "? a : b";
	lexer->new_file_string = "? a : b";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseTernarOperation(token, lexer);

	TernarOperationAST *ternar_op = static_cast<TernarOperationAST*>(result); 

    EXPECT_EQ("?", ternar_op->definition);
}

TEST(parser_test, parseBinOperation)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "/ 2";
	lexer->new_file_string = "/ 2";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseBinOperation(token, lexer);

	BinOperationAST *bin_op = static_cast<BinOperationAST*>(result); 

    EXPECT_EQ("/", bin_op->definition);
}

TEST(parser_test, parseAssignment)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *result = new AST();

	lexer->file_string = "= 24;";
	lexer->new_file_string = "= 24;";

	lexer->makeSpaces();

	Token token = parser->getNextTok(lexer);

	result = parser->parseAssignment(token, lexer);

	AssignmentAST *assignment = static_cast<AssignmentAST*>(result); 

    EXPECT_EQ("=", assignment->definition);
}*/