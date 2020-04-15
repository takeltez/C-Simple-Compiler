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