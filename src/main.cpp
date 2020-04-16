#include "Parser.h"

int main(int argc, char const **argv)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *tree = new AST();
	SymbolTable *symbol_table = new SymbolTable();
	Sema *sema = new Sema();

	Token token;

	string command = argv[1];
	string file_path = argv[2];

	lexer->setStartFileString(file_path);

	if (command == "--dump-tokens") {

		while (1) {

			token = lexer->getNextToken();

			if (token.getLexeme() == " ")
				break;

			if (!token.getLexeme().empty())
				lexer->print(token);
		}
	}

	else if (command == "--dump-ast") {

		tree = parser->buildAST(lexer);

		printAST(tree);
		
		if (file_path == "./examples/hello.c") {

			//symbol_table->setSymTab(tree);
			//symbol_table->printSymTab();
		}

		else if (file_path == "./examples/array_min.c") {

			//symbol_table->setSymTab1(tree);
			//symbol_table->printSymTab();
		}

		else if (file_path == "./examples/substr.c") {

			//symbol_table->setSymTab2(tree);
			//symbol_table->printSymTab();
		}

		else if (file_path == "./examples/nod.c") {
			
			//symbol_table->setSymTab3(tree);
			//symbol_table->printSymTab();	
		}

		sema->checkSemantic(tree);
	}

	free(lexer);
	free(parser);
	free(tree);
	free(symbol_table);
	free(sema);

	return 0;
}