#include "Parser.h"

void printAST(AST *tree)
{
	DataTypeAST *data_type = static_cast<DataTypeAST*>(tree);
	
	data_type->print(1);
}
