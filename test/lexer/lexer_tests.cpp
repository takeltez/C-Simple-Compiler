#include <gtest/gtest.h>
#include "Lexer.h"

int lexeme_pos;

TEST(lexer_test, findStringLexeme)
{
	Lexer lexer;

	string str;
	string expected = "string_literal";
	lexer.file_string = "\"Hello\"";
	lexer.new_file_string = "\"Hello\"";

	string result = lexer.findStringLexeme(1, &str, &lexeme_pos);

    EXPECT_EQ(expected, result);
} 

TEST(lexer_test, findSymbolLexeme)
{
	Lexer lexer;

	string str;
	string expected = "symbol_literal";
	lexer.file_string = "'H'";
	lexer.new_file_string = "'H'";

	string result = lexer.findSymbolLexeme(1, &str, &lexeme_pos);

    EXPECT_EQ(expected, result);
} 

TEST(lexer_test, findStandartLexeme)
{
	Lexer lexer;
	
	string expected = "std_function_printf";
	lexer.file_string = "printf";
	lexer.new_file_string = "printf";

	string result = lexer.findStandartLexeme(1, "printf", &lexeme_pos);

    EXPECT_EQ(expected, result);
}

TEST(lexer_test, findDigitLexeme)
{
	Lexer lexer;
	
	string expected = "digit_literal_hex";
	lexer.file_string = "0x12";
	lexer.new_file_string = "0x12";

	string result = lexer.findDigitLexeme(1, "0x12", &lexeme_pos);

    EXPECT_EQ(expected, result);
}  

TEST(lexer_test, findVariables)
{
	Lexer lexer;
	
	string expected = "variable";
	lexer.file_string = "abc";
	lexer.new_file_string = "abc";

	string result = lexer.findVariables(1, "abc", &lexeme_pos, 0);

    EXPECT_EQ(expected, result);
}  

TEST(lexer_test, findUnacceptSymbols)
{
	Lexer lexer;
	
	string expected = "unacceptable_symbol";
	lexer.file_string = "$@";
	lexer.new_file_string = "$@";

	string result = lexer.findUnacceptSymbols(1, "$@", &lexeme_pos);

    EXPECT_EQ(expected, result);
} 

TEST(lexer_test, checkStdLexemes)
{
	Lexer lexer;
	string expected = "arithmetic_operator_++";

	string result = lexer.checkStdLexemes("++");

    EXPECT_EQ(expected, result);
} 

TEST(lexer_test, shrinkLexemeFromString)
{
	Lexer lexer;
	
	int start_pos = 0;
	string expected = "int";
	lexer.file_string = " int main ";
	lexer.new_file_string = " int main ";

	string result = lexer.shrinkLexemeFromString(&start_pos);

    EXPECT_EQ(expected, result);
}

TEST(lexer_test, getNextToken)
{
	Lexer lexer;
	
	string expected = "int";
	lexer.file_string = " int main";
	lexer.new_file_string = " int main";

	Token token = lexer.getNextToken();
	
    EXPECT_EQ(expected, token.getLexeme());
}