#include "Parser.h"

int num = 0;
bool declr = false;

string data_type;
string op;
string left_operand;
string prev_node;
string cond;

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
	if ((type_id.find(definition)) == type_id.end() && !data_type.empty())
		type_id.emplace(definition, data_type);

	else if ((type_id.find(definition)) == type_id.end() && data_type.empty()) 
		cout<<"Identificator '"<<definition<<"' was not declarated in this scope"<<endl;
	
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
	cond = "while condition";

	condition->semantic();
	
	cond.clear();

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
	cond = "if condition";

	condition->semantic();

	cond.clear();

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
	string buff = op;
	op = definition;

	l_operand->semantic();
	r_operand->semantic();

	operands = sema->checkOperatorsDataType(operands, type_id, op);

	op = buff;

	num = 0;
	declr = false;

	left_operand.clear();
	prev_node.clear();
}

void LogicOperationAST::semantic()
{
	l_operand->semantic();
	r_operand->semantic();
}

void TernarOperationAST::semantic()
{
	l_operand->semantic();
	r_operand->semantic();
}

void BinOperationAST::semantic()
{
	string buff = op;
	op = definition;
	
	l_operand->semantic();
	r_operand->semantic();

	op = buff;
	
	//if (op == "?")
		num = 0;
}

void UnaryOperationAST::semantic()
{
	string buff = op;
	op = "unary_op";

	operand->semantic();

	op = buff;
	num = 0;
}

void PointerAST::semantic()
{
	identificator->semantic();
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

	op = "printf";
	prev_node = "printf";

	for (int i = 0; i < params.size(); ++i)
		params[i]->semantic();
}

void ReturnAST::semantic()
{
	string buff = op;
	op = definition;

	data_type.clear();

	identificator->semantic();

	op = buff;
	num = 0;
}

void StringLexemeAST::semantic()
{
	auto it = type_id.find(left_operand);

	data_type = it->second;

	if (sema->checkBinOperationSign(op))
		cout<<"Cannot execute bin operation with 'string'"<<endl;

	else if (data_type != "char" && !data_type.empty()) 
		cout<<"Incorrect operators for operation '"<<op<<"': '"<<data_type<<"' and 'string'"<<endl;

	else if (prev_node != "array_name" && prev_node != "printf")
			cout<<"Cannot assign 'string', variable must be array"<<endl;
}

void SymbolLexemeAST::semantic()
{
	auto it = type_id.find(left_operand);

	data_type = it->second;

	if (sema->checkBinOperationSign(op))
		cout<<"Cannot execute bin operation with 'char'"<<endl;

	else if (data_type != "char" && !data_type.empty())
		cout<<"Incorrect operators for operation '"<<op<<"': '"<<data_type<<"' and 'char'"<<endl;

	else if (prev_node == "array_name")
			cout<<"Cannot assign 'char' to array, right operand must be 'string'"<<endl;
}

void DigitIdAST::semantic()
{
	if ((cond == "if condition" || cond == "while condition")  && (op != ">" && op != "<" && op != ">=" && op != "<=" && op != "=="))
			cout<<"Cannot execute arithmetic operation in '"<<cond<<"'"<<endl;

	else if (data_type != "int" && data_type != "double" && data_type != "float" && !data_type.empty() && prev_node != "array_name")
		cout<<"Incorrect operators for operation '"<<op<<"': '"<<data_type<<"' and 'int'"<<endl;
}

void SymbolIdAST::semantic()
{
	bool error = false;

	if (op == "=" || op == "unary_op" || op == "return" || op == "printf" || sema->checkBinOperationSign(op)) {

		if ((cond == "if condition" || cond == "while condition") 
				&& (op != ">" && op != "<" && op != ">=" && op != "<=" && op != "==" && op != "%")) {
		
			cout<<"Cannot execute arithmetic operation in '"<<cond<<"'"<<endl;

			return;
		}

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
}