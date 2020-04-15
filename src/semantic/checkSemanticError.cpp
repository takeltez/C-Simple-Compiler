#include "Parser.h"

vector <string> Sema::checkOperatorsDataType(vector <string> operands, map <string, string> type_id, string op)
{
	vector <string> data_types;

	for (int i = 0; i < operands.size(); ++i)
	{
		auto it = type_id.find(operands[i]);

		data_types.push_back(it->second);
	}

	for (int i = 0; i < data_types.size(); ++i)
	{
		if (data_types[i] == "char") {

			for (int i = 0; i < data_types.size(); ++i)
			{
				if (data_types[i] != "char")  {

					cout<<"Incorrect operators for operation '"<<op<<"': 'char' and '"<<data_types[i]<<"'"<<endl;
					break;
				}	
			}
		}
	}

	operands.clear();

	return operands;	
}