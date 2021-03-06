#include "Parser.h"

int num = 0;
bool declr = false;

string data_type;
string op;
string left_operand;
string prev_node;
string cond;

map <string, string> id_table;
vector <string> operands;

Sema *sema = new Sema();

void RootAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void ArrayDataAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void ArrayNameAST::semantic()
{		
	if ((id_table.find(definition)) == id_table.end() && !data_type.empty())
		id_table.emplace(definition, data_type);

	else if ((id_table.find(definition)) == id_table.end() && data_type.empty()) {

		cout<<"Identificator '"<<definition<<"' was not declarated in this scope"<<endl;
		exit(1);
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
	{
		if (i == 1) {

			cond = "for condition";
			blocks[i]->semantic();
			cond.clear();
		}

		else
			blocks[i]->semantic();
	}
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

void ElseAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void FunctionAST::semantic()
{
	args->semantic();
	body->semantic();
}

void FunctionBodyAST::semantic()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->semantic();
}

void FunctionArgsAST::semantic()
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

	operands = sema->checkOperatorsDataType(operands, id_table, op);

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
	auto it = id_table.find(left_operand);

	data_type = it->second;

	if (sema->checkBinOperationSign(op)) {

		cout<<"Cannot execute bin operation with 'string'"<<endl;
		exit(1);
	}

	else if (data_type != "char" && !data_type.empty() && op != "printf") {

		cout<<"Incorrect operators for operation '"<<op<<"': '"<<data_type<<"' and 'string'"<<endl;
		exit(1);
	}

	else if (prev_node != "array_name" && prev_node != "printf") {

		cout<<"Cannot assign 'string', variable must be array"<<endl;
		exit(1);
	}
}

void SymbolLexemeAST::semantic()
{
	auto it = id_table.find(left_operand);

	data_type = it->second;

	if (sema->checkBinOperationSign(op)) {

		cout<<"Cannot execute bin operation with 'char'"<<endl;
		exit(1);
	}

	else if (data_type != "char" && !data_type.empty()) {
		
		cout<<"Incorrect operators for operation '"<<op<<"': '"<<data_type<<"' and 'char'"<<endl;
		exit(1);
	}
}

void DigitIdAST::semantic()
{
	if ((cond == "if condition" || cond == "while condition" || cond == "for condition")  
		&& (op != ">" && op != "<" && op != ">=" && op != "<=" && op != "==" && op != "!=")) {
			
			cout<<"Cannot execute arithmetic operation in '"<<cond<<"'"<<endl;
			exit(1);
	}

	else if (data_type != "int" && data_type != "double" && data_type != "float" && !data_type.empty() && prev_node != "array_name") {
		
		cout<<"Incorrect operators for operation '"<<op<<"': '"<<data_type<<"' and 'int'"<<endl;
		exit(1);
	}
}

void SymbolIdAST::semantic()
{
	bool error = false;

	if (op == "=" || op == "unary_op" || op == "return" || op == "printf" || sema->checkBinOperationSign(op)) {

		if ((cond == "if condition" || cond == "while condition" || cond == "for condition") 
				&& (op != ">" && op != "<" && op != ">=" && op != "<=" && op != "==" && op != "%" && op != "!=")) {
		
			cout<<"Cannot execute arithmetic operation in '"<<cond<<"'"<<endl;
			exit(1);
		}

		if (!num) {

			if ((id_table.find(definition)) == id_table.end() && !data_type.empty()) {

					id_table.emplace(definition, data_type);

					declr = true;

					left_operand = definition;	
			}

			else if ((id_table.find(definition)) == id_table.end() && data_type.empty()) {

				error = true;

				cout<<"Identificator '"<<definition<<"' was not declarated in this scope"<<endl;
				exit(1);
			}

			if (!error)
				left_operand = definition;
		}

		else  {

			if ((id_table.find(definition)) == id_table.end() || ((definition == left_operand) && declr)) {
				
				error = true;

				cout<<"Identificator '"<<definition<<"' was not declarated in this scope"<<endl;
				exit(1);
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

		if ((id_table.find(definition)) == id_table.end()) 
			id_table.emplace(definition, data_type);
	}

}

void BreakAST::semantic()
{
}

void Sema::printIdTable(void)
{
	cout << endl << endl <<"Identificator type | "<< "Identificator name" <<endl;
	cout<<"--------------------------------------"<<endl;

	for (auto it = id_table.begin(); it != id_table.end(); ++it) 
	{
		cout << it->second << endl;
		cout << "\t\t\t" << it->first << endl;
		cout << "--------------------------------------" << endl;
	}
}

Sema::Sema() {}

void Sema::checkSemantic(AST *tree)
{
	RootAST *root = static_cast<RootAST*>(tree);
	
	root->semantic();
}