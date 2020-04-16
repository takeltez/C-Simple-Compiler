#include <gtest/gtest.h>
#include "Parser.h"

TEST(SymTab_test, checkMultiDeclaration)
{
	SymbolTable *symbol_table = new SymbolTable();

	vector <string> vec = {"argc", "argv", "a"};
	vector <string> expected = {"argc", "argv", "a"};

	vector <string> result = symbol_table->checkMultiDeclaration(vec);

    EXPECT_EQ(expected, result);
}

TEST(semantic_test, checkIdDeclaration)
{
	SymbolTable *symbol_table = new SymbolTable();

	bool result = symbol_table->checkIdDeclaration("char");

    EXPECT_EQ(true, result);
}

TEST(semantic_test, checkFuncDeclaration)
{
	SymbolTable *symbol_table = new SymbolTable();

	bool result = symbol_table->checkFuncDeclaration("ARGUMENTS");

    EXPECT_EQ(true, result);
}