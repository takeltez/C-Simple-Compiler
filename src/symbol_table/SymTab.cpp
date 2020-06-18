#include "Parser.h"

string declr_level;
string prev_declr_level;

bool id_declr = false;

string alphabet[] = {"", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", 
														"q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
int ind = 0;

vector <string> identificators;
map <string, vector <string>> symTab;
multiset <string> levels;

SymbolTable *symbol_table = new SymbolTable();

SymbolTable::SymbolTable(void) {}

void RootAST::sym_tab()
{	
	for (int i = 0; i < blocks.size(); ++i)
	{
		prev_declr_level = "0";
		declr_level = "0";
		blocks[i]->sym_tab();
	}
}

void ArrayDataAST::sym_tab()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->sym_tab();
}

void ArrayNameAST::sym_tab()
{	
	if (id_declr)
		identificators.push_back(definition);

	id_declr = false;

	if (identificator != NULL)
		identificator->sym_tab();
}

void ForAST::sym_tab()
{
	condition->sym_tab();

	prev_declr_level = declr_level;

	body->sym_tab();

	prev_declr_level = to_string(stoi(prev_declr_level) - 1);
}

void ForBodyAST::sym_tab()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->sym_tab();
}

void ForConditionAST::sym_tab()
{	
	identificators = symbol_table->checkMultiDeclaration(identificators);

	symTab.emplace(declr_level, identificators);

	++ind;

	if (symbol_table->compareLevels(declr_level, to_string(stoi(prev_declr_level) + 1)))
		ind = levels.count(to_string(stoi(prev_declr_level) + 1)) + 1;

	if (declr_level == "1")
		--ind;

	declr_level = to_string(stoi(prev_declr_level) + 1) + alphabet[ind];

	levels.insert(to_string(stoi(prev_declr_level) + 1));

	identificators.clear();

	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->sym_tab();
}

void WhileAST::sym_tab()
{   	
	condition->sym_tab();

	prev_declr_level = declr_level;

	body->sym_tab();

	prev_declr_level = to_string(stoi(prev_declr_level) - 1);
}

void WhileBodyAST::sym_tab()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->sym_tab();
}

void WhileConditionAST::sym_tab()
{
	identificators = symbol_table->checkMultiDeclaration(identificators);

	symTab.emplace(declr_level, identificators);

	++ind;

	if (symbol_table->compareLevels(declr_level, to_string(stoi(prev_declr_level) + 1)))
		ind = levels.count(to_string(stoi(prev_declr_level) + 1)) + 1;

	if (declr_level == "1")
		--ind;

	declr_level = to_string(stoi(prev_declr_level) + 1) + alphabet[ind];

	levels.insert(to_string(stoi(prev_declr_level) + 1));

	identificators.clear();

	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->sym_tab();
}

void IfAST::sym_tab()
{
	condition->sym_tab();

	prev_declr_level = declr_level;

	body->sym_tab();

	prev_declr_level = to_string(stoi(prev_declr_level) - 1);
}

void IfBodyAST::sym_tab()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->sym_tab();
}

void IfConditionAST::sym_tab()
{	
	identificators = symbol_table->checkMultiDeclaration(identificators);

	symTab.emplace(declr_level, identificators);

	++ind;

	if (symbol_table->compareLevels(declr_level, to_string(stoi(prev_declr_level) + 1)))
		ind = levels.count(to_string(stoi(prev_declr_level) + 1)) + 1;


	if (declr_level == "1")
		--ind;

	declr_level = to_string(stoi(prev_declr_level) + 1) + alphabet[ind];

	levels.insert(to_string(stoi(prev_declr_level) + 1));

	identificators.clear();

	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->sym_tab();
}

void ElseAST::sym_tab()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->sym_tab();
}

void FunctionAST::sym_tab()
{
	if (id_declr)
		identificators.push_back(definition);

	id_declr = false;

	args->sym_tab();
	body->sym_tab();

	identificators = symbol_table->checkMultiDeclaration(identificators);

	symTab.emplace(declr_level, identificators);
}

void FunctionBodyAST::sym_tab()
{
	for (int i = 0; i < blocks.size(); ++i)
		blocks[i]->sym_tab();
}

void FunctionArgsAST::sym_tab()
{
	identificators = symbol_table->checkMultiDeclaration(identificators);

	symTab.emplace(declr_level, identificators);
	
	declr_level = to_string(stoi(declr_level) + 1);
	prev_declr_level = declr_level;

	levels.insert(to_string(stoi(prev_declr_level) + 1));

	identificators.clear();

	for (int i = 0; i < args.size() - 1; ++i)
		args[i]->sym_tab();	
}

void AssignmentAST::sym_tab()
{	
	l_operand->sym_tab();
	r_operand->sym_tab();
}

void LogicOperationAST::sym_tab()
{
	l_operand->sym_tab();
	r_operand->sym_tab();
}

void TernarOperationAST::sym_tab()
{
	l_operand->sym_tab();
	r_operand->sym_tab();
}

void BinOperationAST::sym_tab()
{
	l_operand->sym_tab();
	r_operand->sym_tab();
}

void UnaryOperationAST::sym_tab()
{
	operand->sym_tab();
}

void PointerAST::sym_tab()
{
	identificator->sym_tab();
}

void DataTypeAST::sym_tab()
{
	id_declr = true;

	identificator->sym_tab();
}

void ConstAST::sym_tab()
{
	identificator->sym_tab();
}

void PrintfAST::sym_tab()
{
	for (int i = 0; i < params.size(); ++i)
		params[i]->sym_tab();
}

void ReturnAST::sym_tab()
{

	identificator->sym_tab();
}

void StringLexemeAST::sym_tab()
{
}

void SymbolLexemeAST::sym_tab()
{
}

void DigitIdAST::sym_tab()
{
}

void SymbolIdAST::sym_tab()
{
	if (id_declr) 
		identificators.push_back(definition);
	
	id_declr = false;
}

void BreakAST::sym_tab() {}


void SymbolTable::printSymTab(void)
{
	cout<<endl<<"Identificator name | "<<"Declaration level"<<endl;
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

void SymbolTable::setSymTab(AST *tree)
{
	RootAST *root = static_cast<RootAST*>(tree);
	
	root->sym_tab();

}