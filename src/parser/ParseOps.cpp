#include "Parser.h"

extern vector <AST*> blocks;

AST *Parser::parseAssignment(Token token, Lexer *lexer)
{
	Token tok, buff, prev;
	AssignmentAST *assignment;
	AST *r_operand, *l_operand;

	buff = Parser::prev_token;
	Parser::prev_token = token;

	l_operand = blocks[blocks.size() - 1];

	while (tok.getLexeme() != ";" && tok.getLexeme() != "," && Parser::curr_token.getLexeme() != ";") 
	{	
		prev = tok;
		tok = getNextTok(lexer);

		checkSemicolonAndCommaError(tok, prev);

		if (checkAssignmentTok(tok))
			blocks.push_back(handler(tok, lexer));	
	}

	r_operand = blocks[blocks.size() - 1];

	assignment = new AssignmentAST(r_operand, l_operand, token);

	blocks.pop_back();
	blocks.pop_back();

	Parser::prev_token = buff;
	Parser::curr_token.setLexeme("");

	return assignment;
}

AST *Parser::parseLogicOperation(Token token, Lexer *lexer)
{
	Token tok;
	LogicOperationAST *logic_op;
	AST *r_operand, *l_operand;

	while (!checkLogicOpTok(tok))
		tok = getNextTok(lexer);

	l_operand = blocks[blocks.size() - 1];
	
	while (checkLogicOpTok(tok)) 
	{	
		blocks.push_back(handler(tok, lexer));
		tok = getNextTok(lexer);
		Parser::curr_token = tok;
	}

	r_operand = blocks[blocks.size() - 1];

	logic_op = new LogicOperationAST(r_operand, l_operand, token);

	blocks.pop_back();
	blocks.pop_back();

	return logic_op;
}

AST *Parser::parseTernarOperation(Token token, Lexer *lexer)
{
	Token tok;
	TernarOperationAST *ternar_op;
	AST *r_operand, *l_operand;

	while (!checkTernarOpTok(tok))
		tok = getNextTok(lexer);

	l_operand = blocks[blocks.size() - 1];
	
	while (checkTernarOpTok(tok)) 
	{	
		blocks.push_back(handler(tok, lexer));
		tok = getNextTok(lexer);
		Parser::curr_token = tok;
	}

	r_operand = blocks[blocks.size() - 1];

	ternar_op = new TernarOperationAST(r_operand, l_operand, token);

	blocks.pop_back();
	blocks.pop_back();

	return ternar_op;
}

AST *Parser::parseBinOperation(Token token, Lexer *lexer)
{ 
	Token tok;
	BinOperationAST *bin_op;
	AST *r_operand, *l_operand;

	while (!checkBinOpTok(tok))
		tok = getNextTok(lexer);
	
	l_operand = blocks[blocks.size() - 1];
	r_operand = handler(tok, lexer);

	blocks.pop_back();

	bin_op = new BinOperationAST(r_operand, l_operand, token);
	
	return bin_op;
}

AST *Parser::parseUnaryOperation(Token token, Lexer *lexer)
{
	Token tok;
	UnaryOperationAST *uanry_op;
	AST *operand;

	if (checkUnaryOpTok(Parser::prev_token)) {

		operand = blocks[blocks.size() - 1];

		blocks.pop_back();

		uanry_op = new UnaryOperationAST(operand, token);
	}

	else {

		while (!checkUnaryOpTok(tok))
			tok = getNextTok(lexer);

		operand = handler(tok, lexer);

		uanry_op = new UnaryOperationAST(operand, token);
	}

	return uanry_op;
}

AST *Parser::parsePointer(Token token, Lexer *lexer)
{
	Token tok;
	PointerAST *ptr;
	AST *identificator;

	tok = getNextTok(lexer);

	if (checkPonterTok(tok)) {

		identificator = handler(tok, lexer);

		ptr = new PointerAST(identificator, token);
	}

	return ptr;
}