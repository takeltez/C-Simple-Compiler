#include "Parser.h"

bool SymbolTable::compareLevels(string prev_lvl, string new_lvl)
{
	return (stoi(prev_lvl) < stoi(new_lvl));
}


vector <string> SymbolTable::checkMultiDeclaration(vector <string> identificators)
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
					exit(1);
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