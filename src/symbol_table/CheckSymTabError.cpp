#include "Parser.h"

bool checkIdDeclaration(string def)
{
	return (def == "int" || def == "char" || def == "float" || def == "double" || def == "const");
}

bool checkFuncDeclaration(string def)
{
	return (def == "ARGUMENTS" || def == "CONDITION");
}

vector <string> checkMultiDeclaration(vector <string> identificators)
{
	bool flag = false;

	for (int i = 0; i < identificators.size(); ++i)
	{
		for (auto j = 0; j < identificators.size(); ++j)
		{
			if (i != j && !identificators[i].empty()) {
				if (identificators[i] == identificators[j]) {
					cout<<endl<<"identificator '"<<identificators[i]<<"' was already declarated in this scope"<<endl;
					identificators[j].clear();
					flag = true;
				}
			}		
		}
	}

	if (!flag)
		return identificators;

	vector <string> new_vec;

	for (int i = 0; i < identificators.size(); ++i)
	{
		if (!identificators[i].empty())
			new_vec.push_back(identificators[i]);
	}

	return new_vec;
}