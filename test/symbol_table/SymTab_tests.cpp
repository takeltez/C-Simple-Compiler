#include <gtest/gtest.h>
#include "Parser.h"

TEST(SymTab_test, checkMultiDeclaration)
{
	vector <string> vec = {"argc", "argv", "a"};
	vector <string> expected = {"argc", "argv", "a"};

	vector <string> result = checkMultiDeclaration(vec);

    EXPECT_EQ(expected, result);
}