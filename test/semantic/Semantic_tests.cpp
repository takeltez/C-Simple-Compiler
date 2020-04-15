#include <gtest/gtest.h>
#include "Parser.h"

TEST(semantic_test, checkOperatorsDataType)
{
	Sema *sema = new Sema();
	
	map <string, string> type_id;

	type_id.emplace("pos", "int");
	type_id.emplace("i", "int");
	type_id.emplace("token_size", "int");

	vector <string> operans = {"pos", "i", "token_size"};
	vector <string> expected;

	vector <string> result = sema->checkOperatorsDataType(operans, type_id, "=");

    EXPECT_EQ(expected, result);
}