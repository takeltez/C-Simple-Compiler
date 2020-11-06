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
		sema->printIdTable();
	}

	else if (command == "--dump-asm") {

		tree = parser->buildAST(lexer);

		symbol_table->setSymTab(tree);

		sema->checkSemantic(tree);

		cod_gen->startCodGen(tree, file_path);
		cod_gen->printAsm();
	}

	else if (command.empty()) {

		tree = parser->buildAST(lexer);

		symbol_table->setSymTab(tree);

		sema->checkSemantic(tree);

		cod_gen->startCodGen(tree, file_path);
		cod_gen->compileAsmFile();
	}

	else
		cout<<"Error: Incorrect interrupt command"<<endl;

	free(lexer);
	free(parser);
	free(tree);
	free(symbol_table);
	free(sema);
	free(cod_gen);

	return 0;
}