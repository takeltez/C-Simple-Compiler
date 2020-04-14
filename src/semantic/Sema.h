#pragma once

using namespace std;

class Sema
{
	public:
		Sema();
		vector <string> checkOperatorsDataType(vector <string> operands, map <string, string> type_id, string op);
		void checkSemantic(AST *tree);	
};