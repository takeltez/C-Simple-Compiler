#include "Parser.h"

int main(int argc, char const **argv)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *tree = new AST();
	SymbolTable *symbol_table = new SymbolTable();
	Sema *sema = new Sema();
	CodGen *cod_gen = new CodGen();

	Token token;

	string file_path;
	string command;

	if (argc == 3) {

		command = argv[1];
		file_path = argv[2];
	}

	else if (argc == 2)
		file_path = argv[1];

	lexer->setStartFileString(file_path);

	tree = parser->buildAST(lexer);

	symbol_table->setSymTab(tree);
		
	sema->checkSemantic(tree);

	cod_gen->startCodGen(tree, file_path);

	lexer = new Lexer();

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
		
		printAST(tree);
		symbol_table->printSymTab();
	}

	else if (command == "--dump-asm")
		cod_gen->printAsm();

	free(lexer);
	free(parser);
	free(tree);
	free(symbol_table);
	free(sema);
	free(cod_gen);

	return 0;
}