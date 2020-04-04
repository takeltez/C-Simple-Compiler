#include "Parser.h"

SymbolTable::SymbolTable(void) {}

void SymbolTable::printSymTab(void)
{
	cout<<"Identificator name | "<<"Declaration level"<<endl;
	cout<<"--------------------------------------"<<endl;

	for (auto it = symTab.begin(); it != symTab.end(); ++it) 
	{
		for (int i = 0; i < (it->second).size(); ++i)
		{
			if (i % 2 == 0)
				cout<<endl;

			if (i == (it->second).size() - 1)
				cout<<(it->second)[i]<<" ";
			
			else
				cout<<(it->second)[i]<<", ";
		}

		cout<<endl<<"\t\t\t"<<it->first<<endl;
		cout<<"--------------------------------------"<<endl;
	}
}

void SymbolTable::setSymTab(AST *tree) //hello.c
{
	string id_dec;

	DataTypeAST *data_type = static_cast<DataTypeAST*>(tree); //int
	
	MainFunctionAST *main_func = static_cast<MainFunctionAST*>(data_type->identificator); //main

	MainFunctionArgsAST *main_func_args = static_cast<MainFunctionArgsAST*>(main_func->args); //main args

	//level 1

	if (checkFuncDeclaration(main_func_args->definition))
		level = "1";

	data_type = static_cast<DataTypeAST*>(main_func_args->args[0]); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	SymbolIdAST *var = static_cast<SymbolIdAST*>(data_type->identificator); //argc

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	ConstAST *key_word_const = static_cast<ConstAST*>(main_func_args->args[1]); //const

	data_type = static_cast<DataTypeAST*>(key_word_const->identificator); //char

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	PointerAST *ptr = static_cast<PointerAST*>(data_type->identificator); //*

	ptr = static_cast<PointerAST*>(ptr->identificator); //*

	var = static_cast<SymbolIdAST*>(ptr->identificator); //argv

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	MainFunctionBodyAST *main_func_body = static_cast<MainFunctionBodyAST*>(main_func->body); //main body

	AssignmentAST *assignment = static_cast<AssignmentAST*>(main_func_body->blocks[1]); //=

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //a

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	symTab.emplace(level, identificators);

	identificators.clear();

	//level 2

	IfAST *key_word_if = static_cast<IfAST*>(main_func_body->blocks[2]); //if

	IfConditionAST *if_cond = static_cast<IfConditionAST*>(key_word_if->condition); //if condition

	if (checkFuncDeclaration(main_func_args->definition))
		level = "2a";

	IfBodyAST *if_body = static_cast<IfBodyAST*>(key_word_if->body); //if body

	assignment = static_cast<AssignmentAST*>(if_body->blocks[1]); //=

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //double

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //b

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	symTab.emplace(level, identificators);

	identificators.clear();

	//lever 2c

	ForAST *key_word_for = static_cast<ForAST*>(main_func_body->blocks[4]); //for

	ForConditionAST *for_cond = static_cast<ForConditionAST*>(key_word_for->condition); //for condition

	if (checkFuncDeclaration(main_func_args->definition))
		level = "2c";

	assignment = static_cast<AssignmentAST*>(for_cond->blocks[0]); //=

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //i

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	symTab.emplace(level, identificators);

	identificators.clear();
}

void SymbolTable::setSymTab1(AST *tree) //array_min.c
{
	string id_dec;

	DataTypeAST *data_type = static_cast<DataTypeAST*>(tree); //int
	
	MainFunctionAST *main_func = static_cast<MainFunctionAST*>(data_type->identificator); //main

	MainFunctionArgsAST *main_func_args = static_cast<MainFunctionArgsAST*>(main_func->args); //main args

	//level 1

	if (checkFuncDeclaration(main_func_args->definition))
		level = "1";

	data_type = static_cast<DataTypeAST*>(main_func_args->args[0]); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	SymbolIdAST *var = static_cast<SymbolIdAST*>(data_type->identificator); //argc

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	ConstAST *key_word_const = static_cast<ConstAST*>(main_func_args->args[1]); //const

	data_type = static_cast<DataTypeAST*>(key_word_const->identificator); //char

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	PointerAST *ptr = static_cast<PointerAST*>(data_type->identificator); //*

	ptr = static_cast<PointerAST*>(ptr->identificator); //*

	var = static_cast<SymbolIdAST*>(ptr->identificator); //argv

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	MainFunctionBodyAST *main_func_body = static_cast<MainFunctionBodyAST*>(main_func->body); //main body

	AssignmentAST *assignment = static_cast<AssignmentAST*>(main_func_body->blocks[0]); //=

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //N

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[1]); //=

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	ArrayNameAST *arr_name = static_cast<ArrayNameAST*>(data_type->identificator); //arr[]

	if (!id_dec.empty())
		identificators.push_back(arr_name->definition);

	id_dec.clear();

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[2]); //=

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //min

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	symTab.emplace(level, identificators);

	identificators.clear();

	//level 2a

	ForAST *key_word_for = static_cast<ForAST*>(main_func_body->blocks[3]); //for

	ForConditionAST *for_cond = static_cast<ForConditionAST*>(key_word_for->condition); //for condition

	if (checkFuncDeclaration(main_func_args->definition))
		level = "2a";

	assignment = static_cast<AssignmentAST*>(for_cond->blocks[0]); //=

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //i

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	symTab.emplace(level, identificators);

	identificators.clear();
}

void SymbolTable::setSymTab2(AST *tree) //substr.c
{
	string id_dec;

	DataTypeAST *data_type = static_cast<DataTypeAST*>(tree); //int
	
	MainFunctionAST *main_func = static_cast<MainFunctionAST*>(data_type->identificator); //main

	MainFunctionArgsAST *main_func_args = static_cast<MainFunctionArgsAST*>(main_func->args); //main args

	//level 1

	if (checkFuncDeclaration(main_func_args->definition))
		level = "1";

	data_type = static_cast<DataTypeAST*>(main_func_args->args[0]); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	SymbolIdAST *var = static_cast<SymbolIdAST*>(data_type->identificator); //argc

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	ConstAST *key_word_const = static_cast<ConstAST*>(main_func_args->args[1]); //const

	data_type = static_cast<DataTypeAST*>(key_word_const->identificator); //char

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	PointerAST *ptr = static_cast<PointerAST*>(data_type->identificator); //*

	ptr = static_cast<PointerAST*>(ptr->identificator); //*

	var = static_cast<SymbolIdAST*>(ptr->identificator); //argv

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	MainFunctionBodyAST *main_func_body = static_cast<MainFunctionBodyAST*>(main_func->body); //main body

	AssignmentAST *assignment = static_cast<AssignmentAST*>(main_func_body->blocks[0]); //=

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //N

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[1]); //=

	var = static_cast<SymbolIdAST*>(assignment->l_operand); //token_size

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[2]); //=

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //char

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	ArrayNameAST *arr_name = static_cast<ArrayNameAST*>(data_type->identificator); //s_str[]

	if (!id_dec.empty())
		identificators.push_back(arr_name->definition);

	id_dec.clear();

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[3]); //=

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //char

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	arr_name = static_cast<ArrayNameAST*>(data_type->identificator); //token[]

	if (!id_dec.empty())
		identificators.push_back(arr_name->definition);

	id_dec.clear();

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[4]); //=

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //j

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	var = static_cast<SymbolIdAST*>(main_func_body->blocks[5]); //pos

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	symTab.emplace(level, identificators);

	identificators.clear();

	//level 2a

	ForAST *key_word_for = static_cast<ForAST*>(main_func_body->blocks[6]); //for

	ForConditionAST *for_cond = static_cast<ForConditionAST*>(key_word_for->condition); //for condition

	if (checkFuncDeclaration(main_func_args->definition))
		level = "2a";

	assignment = static_cast<AssignmentAST*>(for_cond->blocks[0]); //=

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //i

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	symTab.emplace(level, identificators);

	identificators.clear();
}

void SymbolTable::setSymTab3(AST *tree) //nod.c
{
	string id_dec;

	DataTypeAST *data_type = static_cast<DataTypeAST*>(tree); //int
	
	MainFunctionAST *main_func = static_cast<MainFunctionAST*>(data_type->identificator); //main

	MainFunctionArgsAST *main_func_args = static_cast<MainFunctionArgsAST*>(main_func->args); //main args

	//level 1

	if (checkFuncDeclaration(main_func_args->definition))
		level = "1";

	data_type = static_cast<DataTypeAST*>(main_func_args->args[0]); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	SymbolIdAST *var = static_cast<SymbolIdAST*>(data_type->identificator); //argc

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	ConstAST *key_word_const = static_cast<ConstAST*>(main_func_args->args[1]); //const

	data_type = static_cast<DataTypeAST*>(key_word_const->identificator); //char

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	PointerAST *ptr = static_cast<PointerAST*>(data_type->identificator); //*

	ptr = static_cast<PointerAST*>(ptr->identificator); //*

	var = static_cast<SymbolIdAST*>(ptr->identificator); //argv

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	MainFunctionBodyAST *main_func_body = static_cast<MainFunctionBodyAST*>(main_func->body); //main body

	AssignmentAST *assignment = static_cast<AssignmentAST*>(main_func_body->blocks[0]); //=

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //a

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[1]); //=

	var = static_cast<SymbolIdAST*>(assignment->l_operand); //b

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	assignment = static_cast<AssignmentAST*>(main_func_body->blocks[2]); //=

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //min

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	data_type = static_cast<DataTypeAST*>(main_func_body->blocks[3]); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //nod

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	symTab.emplace(level, identificators);

	identificators.clear();

	//level 2a

	ForAST *key_word_for = static_cast<ForAST*>(main_func_body->blocks[4]); //for

	ForConditionAST *for_cond = static_cast<ForConditionAST*>(key_word_for->condition); //for condition

	if (checkFuncDeclaration(main_func_args->definition))
		level = "2a";

	assignment = static_cast<AssignmentAST*>(for_cond->blocks[0]); //=

	data_type = static_cast<DataTypeAST*>(assignment->l_operand); //int

	if (checkIdDeclaration(data_type->definition))
		id_dec = data_type->definition;

	var = static_cast<SymbolIdAST*>(data_type->identificator); //i

	if (!id_dec.empty())
		identificators.push_back(var->definition);

	id_dec.clear();

	symTab.emplace(level, identificators);

	identificators.clear();
}

