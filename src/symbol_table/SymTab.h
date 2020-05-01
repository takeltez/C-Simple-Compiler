#pragma once
#include <map>

using namespace std;

class SymbolTable
{
	public:
		SymbolTable();
		void setSymTab(AST *tree);
		void printSymTab(void);
		bool compareLevels(string prev_lvl, string new_lvl);
		vector <string> checkMultiDeclaration(vector <string> identificators);
};