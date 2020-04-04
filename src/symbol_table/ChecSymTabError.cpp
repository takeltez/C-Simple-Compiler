#include "Parser.h"

bool checkIdDeclaration(string def)
{
	return (def == "int" || def == "char" || def == "float" || def == "double" || def == "const");
}

bool checkFuncDeclaration(string def)
{
	return (def == "ARGUMENTS" || def == "CONDITION");
}