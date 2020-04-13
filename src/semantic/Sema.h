#pragma once

using namespace std;

class Sema
{
	public:
		Sema();
		void checkSemantic(AST *tree);	
};