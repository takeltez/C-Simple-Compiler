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

		symbol_table->setSymTab(tree);
		symbol_table->printSymTab();
		
		sema->checkSemantic(tree);
	}

	free(lexer);
	free(parser);
	free(tree);
	free(symbol_table);
	free(sema);

	return 0;
}