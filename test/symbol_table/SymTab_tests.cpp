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

TEST(semantic_test, compareLevels)
{
	SymbolTable *symbol_table = new SymbolTable();

	bool result = symbol_table->compareLevels("2a", "3a");

    EXPECT_EQ(true, result);
}