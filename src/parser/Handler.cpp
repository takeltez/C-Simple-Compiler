#include "Parser.h"

Token Parser::prev_token;
Token Parser::curr_token;

vector <AST*> blocks;

Parser::Parser() {}

Token Parser::getNextTok(Lexer *lexer)
{
	Token tok = lexer->getNextToken();

	return tok;
}

AST *Parser::handler(Token token, Lexer *lexer)
{
	AST *node;

	if (checkParseDataType(token)) 
		return parseDataType(token, lexer);

	if (checkParsePointer(token, Parser::prev_token))
		return parsePointer(token, lexer);

	if (checkParseCosnt(token))
		return  parseConst(token, lexer);

	if (checkParseMainFunction(token))
		return parseMainFunction (token, lexer);

	if (checkParseMainFuncArgs(token, Parser::prev_token)) 
		return parseMainFunctionBody(lexer);

	if (checkParseMainFuncBody(token, Parser::prev_token))
		return parseMainFunctionArgs(lexer);

	if (checkParseIfBody(token, Parser::prev_token))
		return parseIfBody(lexer);

	if (checkParseIfCondition(token, Parser::prev_token))
		return parseIfCondition(lexer);

	if (checkParseWhileBody(token, Parser::prev_token))
		return parseWhileBody(lexer);

	if (checkParseWhileCond(token, Parser::prev_token))
		return parseWhileCondition(lexer);

	if (checkParseForBody(token, Parser::prev_token))
		return parseForBody(lexer);

	if (checkParseForCond(token, Parser::prev_token))
		return parseForCondition(lexer);

	if (checkParseArrayData(token, Parser::prev_token)) 
		return parseArrayData(lexer);

	if (checkParseArrayName(token)) 
		return parseArrayName(token, lexer);
	
	if (checkParsePrintf(token)) 
		return parsePrintf(token, lexer);

	if (checkParseReturn(token)) 
		return parseReturn(token, lexer);

	if (checkParseIf(token)) 
		return parseIf(token, lexer);

	if (checkParseWhile(token)) 
		return parseWhile(token, lexer);

	if (checkParseFor(token)) 
		return parseFor(token, lexer);

	if (checkParseStringLexeme(token))
		return parseStringLexeme(token);

	if (checkParseSymbolLexeme(token))
		return parseSymbolLexeme(token);

	if (checkParseDigitId(token))
		return parseDigitId(token);

	if (checkParseSymbolId(token))
		return parseSymbolId(token);

	if (checkParseBreak(token))
		return parseBreak(token, lexer);

	if (checkParseAssignment(token)) 
		return parseAssignment(token, lexer);

	if (checkParseLogicOperation(token))
		return parseLogicOperation(token, lexer);

	if (checkParseBinOperation(token)) 
		return parseBinOperation(token, lexer);

	if (checkParseUnaryOperation(token)) 
		return parseUnaryOperation(token, lexer);

	if (checkParseTernarOperation(token)) 
		return parseTernarOperation(token, lexer);

	return node;
}

AST *Parser::buildAST(Lexer *lexer)
{
	Token token;

	token = getNextTok(lexer);
	
	return handler(token, lexer);
}