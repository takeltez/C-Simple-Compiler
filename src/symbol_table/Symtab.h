#pragma once
#include <map>

using namespace std;

class SymbolTable
{
	private:
		string level;
		vector <string> identificators;
		map <string, vector <string>> symTab;

	public:
		SymbolTable();
		void setSymTab(AST *tree);
		void setSymTab1(AST *tree);
		void setSymTab2(AST *tree);
		void setSymTab3(AST *tree);
		void printSymTab(void);
};

bool checkIdDeclaration(string definition);
bool checkFuncDeclaration(string definition);
vector <string> checkMultiDeclaration(vector <string> identificators);