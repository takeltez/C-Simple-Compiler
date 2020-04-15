#include "Parser.h"

int num = 0;
bool declr = false;

string data_type;
string op;
string left_operand;
string prev_node;

map <string, string> type_id;
vector <string> operands;

Sema *sema = new Sema();

void ArrayDataAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void ArrayNameAST::semantic()
{		
	if (!data_type.empty()) {

		if ((type_id.find(definition)) == type_id.end())
			type_id.emplace(definition, data_type);
	}

	prev_node = "array_name";

	if (identificator != NULL)
		identificator->semantic();
}

void ForAST::semantic()
{
	data_type.clear();
	condition->semantic();
	body->semantic();
}

void ForBodyAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void ForConditionAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void WhileAST::semantic()
{
	data_type.clear();
	condition->semantic();
	body->semantic();
}

void WhileBodyAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void WhileConditionAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void IfAST::semantic()
{
	data_type.clear();
	condition->semantic();
	body->semantic();
}

void IfBodyAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void IfConditionAST::semantic()
{	
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void MainFunctionAST::semantic()
{
	args->semantic();
	body->semantic();
}

void MainFunctionBodyAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void MainFunctionArgsAST::semantic()
{
	for (int i = 0; i < args.size() - 1; ++i)
		args[i]->semantic();	
}

void AssignmentAST::semantic()
{	
	if (op.empty())
		op = definition;

	l_operand->semantic();
	r_operand->semantic();

	num = 0;

	left_operand.clear();

	operands = sema->checkOperatorsDataType(operands, type_id, op);

	if (op == definition)
		op.clear();

	declr = false;

	prev_node.clear();
}

void LogicOperationAST::semantic()
{
	if (op.empty())
		op = definition;

	l_operand->semantic();
	r_operand->semantic();

	if (op == definition)
		op.clear();
}

void TernarOperationAST::semantic()
{
	if (op.empty())
		op = definition;

	l_operand->semantic();
	r_operand->semantic();

	if (op == definition)
		op.clear();
}

void BinOperationAST::semantic()
{
	if (op.empty())
		op = definition;
	
	l_operand->semantic();
	r_operand->semantic();

	if (op == definition)
		op.clear();

}

void UnaryOperationAST::semantic()
{
	if (op.empty())
		op = definition;

	operand->semantic();

	if (op == definition)
		op.clear();
}

void PointerAST::semantic()
{
	if (op.empty())
		op = definition;

	identificator->semantic();

	if (op == definition)
		op.clear();
}

void DataTypeAST::semantic()
{
	data_type = definition;

	identificator->semantic();
}

void ConstAST::semantic()
{
	identificator->semantic();
}

void PrintfAST::semantic()
{
	data_type.clear();
	op.clear();

	prev_node = "printf";

	for (int i = 0; i < params.size(); ++i)
		params[i]->semantic();
}

void ReturnAST::semantic()
{
	identificator->semantic();
}

void StringLexemeAST::semantic()
{
	if (data_type != "char" && !data_type.empty()) 
		cout<<"Incorrect operators for operation '"<<op<<"': '"<<data_type<<"' and 'string'"<<endl;

	if (prev_node != "array_name" && prev_node != "printf")
			cout<<"Cannot assign 'string', variable must be array"<<endl;
}

void SymbolLexemeAST::semantic()
{
	if (data_type != "char" && !data_type.empty())
		cout<<"Incorrect operators for operation '"<<op<<"': '"<<data_type<<"' and 'char'"<<endl;

	if (prev_node == "array_name")
			cout<<"Cannot assign 'char' to array, right operand must be 'string'"<<endl;
}

void DigitIdAST::semantic()
{
	if (data_type != "int" && data_type != "double" && data_type != "float" && !data_type.empty() && prev_node != "array_name")
		cout<<"Incorrect operators for operation '"<<op<<"': '"<<data_type<<"' and 'int'"<<endl;
}

void SymbolIdAST::semantic()
{
	bool error = false;

	if (op == "=") {

		if (!num) {

			if ((type_id.find(definition)) == type_id.end() && !data_type.empty()) {

					type_id.emplace(definition, data_type);

					declr = true;

					left_operand = definition;	
			}

			else if ((type_id.find(definition)) == type_id.end() && data_type.empty()) {

				error = true;

				cout<<"Identificator '"<<definition<<"' was not declarated in this scope"<<endl;

				return;
			}

			if (!error)
				left_operand = definition;
		}

		else  {

			if ((type_id.find(definition)) == type_id.end() || ((definition == left_operand) && declr)) {
				
				error = true;

				cout<<"Identificator '"<<definition<<"' was not declarated in this scope"<<endl;
			}
		}

		if (!error && num == 1) {
			operands.push_back(left_operand);
		}

		if (!error && num) {
			operands.push_back(definition);
		}
	
		++num;
	}

	else if (!data_type.empty()) {

		if ((type_id.find(definition)) == type_id.end()) 
			type_id.emplace(definition, data_type);
	}

}

void BreakAST::semantic()
{
}

Sema::Sema() {}

void Sema::checkSemantic(AST *tree)
{
	DataTypeAST *data_type = static_cast<DataTypeAST*>(tree);
	
	data_type->semantic();

	/*for (auto it = type_id.begin(); it != type_id.end(); ++it)
		cout<<it->second<<" "<<it->first<<endl;*/
}