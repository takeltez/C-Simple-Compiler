#include "Parser.h"

int main(int argc, char const **argv)
{
	Lexer *lexer = new Lexer();
	Parser *parser = new Parser();
	AST *tree = new AST();
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
		
		if (file_path == "./examples/hello.c")
			printAST (tree);

		else if (file_path == "./examples/array_min.c")
			printAST1 (tree);

		else if (file_path == "./examples/substr.c")
			printAST2 (tree);

		else if (file_path == "./examples/nod.c")
			printAST3 (tree);
	}

	free(lexer);
	free(parser);
	free(tree);

	return 0;
}