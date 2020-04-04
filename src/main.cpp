#include "Parser.h"

int main(int argc, char const **argv)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *tree = new AST();
	SymbolTable *symbol_table = new SymbolTable();

	Token token;

	string command = argv[1];
	string file_path = argv[2];

	lexer->setStartFileString(file_path);

	if (command == "--dump-tokens") {

		while (1) {

			token = lexer->getNextToken(); //Возвращаем каждый найденный токен

			if (token.getLexeme() == " ")
				break;

			if (!token.getLexeme().empty()) {
				cout<<"Loc=<"<<token.getLine()<<":"<<token.getPos()<<">	";
				cout<<token.getTokenClass()<<"		"<<token.getLexeme()<<endl;
			}
		}
	}

	else if (command == "--dump-ast") {

		tree = parser->buildAST(lexer);
		
		if (file_path == "./examples/hello.c") {

			//printAST (tree);
			symbol_table->setSymTab(tree);
			symbol_table->printSymTab();
		}

		else if (file_path == "./examples/array_min.c") {

			//printAST1 (tree);
			symbol_table->setSymTab1(tree);
			symbol_table->printSymTab();
		}

		else if (file_path == "./examples/substr.c") {

			//printAST2 (tree);
			symbol_table->setSymTab2(tree);
			symbol_table->printSymTab();
		}

		else if (file_path == "./examples/nod.c") {
			
			//printAST3 (tree);
			symbol_table->setSymTab3(tree);
			symbol_table->printSymTab();	
		}
	}

	free(lexer);
	free(parser);
	free(tree);
	free(symbol_table);

	return 0;
}