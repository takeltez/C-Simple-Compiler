#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include "Token.h"
#include "Lexer.h"
#include "AST.h"
#include "SymTab.h"
#include "Sema.h"

using namespace std;

class Parser
{
	public:
		static Token prev_token;
		static Token curr_token;

	public:
		Parser();
		AST *buildAST(Lexer *lexer);
		AST *parseRoot(Lexer *lexer);
		AST *handler(Token token, Lexer *lexer);
		AST *parseDataType(Token token, Lexer *lexer); 
		AST *parseConst(Token token, Lexer *lexer);
		AST *parseFunction(Token token, Lexer *lexer);
		AST *parseFunctionBody(Lexer *lexer);
		AST *parseFunctionArgs(Lexer *lexer);
		AST *parsePrintf(Token token, Lexer *lexer);
		AST *parseReturn(Token token, Lexer *lexer);
		AST *parseAssignment(Token token, Lexer *lexer);
		AST *parseLogicOperation(Token token, Lexer *lexer);
		AST *parseTernarOperation(Token token, Lexer *lexer);
		AST *parseBinOperation(Token token, Lexer *lexer);
		AST *parseUnaryOperation(Token token, Lexer *lexer);
		AST *parsePointer(Token token, Lexer *lexer);
		AST *parseIf(Token token, Lexer *lexer);
		AST *parseIfCondition(Lexer *lexer);
		AST *parseIfBody(Lexer *lexer); 
		AST *parseWhile(Token token, Lexer *lexer);
		AST *parseWhileCondition(Lexer *lexer);
		AST *parseWhileBody(Lexer *lexer);
		AST *parseFor(Token token, Lexer *lexer);
		AST *parseForCondition(Lexer *lexer);
		AST *parseForBody(Lexer *lexer);
		AST *parseArrayData(Lexer *lexer);
		AST *parseArrayName(Token token, Lexer *lexer); 
		AST *parseStringLexeme(Token token);
		AST *parseSymbolLexeme(Token token);
		AST *parseDigitId(Token token);
		AST *parseSymbolId(Token token);
		AST *parseBreak(Token token, Lexer *lexer);
		Token getNextTok(Lexer *lexer);
};

bool checkRootTok(Token token);
bool checkFuncArgsTok(Token token);
bool checkBodyTok(Token token);
bool checkDataTypeTok(Token token);
bool checkReturnTok(Token token);
bool checkConstTok(Token token);
bool checkAssignmentTok(Token token);
bool checkTernarOpTok(Token tok);
bool checkBinOpTok(Token token);
bool checkUnaryOpTok(Token token);
bool checkLogicOpTok(Token token);
bool checkPonterTok(Token token);
bool checkIfConditionTok(Token token);
bool checkWhileConditionTok(Token token);
bool checkForConditionTok(Token token);
bool checkArrayDataTok(Token token);
bool checkArrayNameTok(Token token);
bool checkPrintfTok(Token token);

bool checkParseDataType(Token token);
bool checkParsePointer(Token curr_token, Token prev_token);
bool checkParseCosnt(Token token);
bool checkParseFunction(Token token);
bool checkParseFuncArgs(Token curr_token, Token prev_token);
bool checkParseFuncBody(Token curr_token, Token prev_token);
bool checkParseIf(Token token);
bool checkParseIfCondition(Token curr_token, Token prev_token);
bool checkParseIfBody(Token curr_token, Token prev_token);
bool checkParseFor(Token token);
bool checkParseForCond(Token curr_token, Token prev_token);
bool checkParseForBody(Token curr_token, Token prev_token);
bool checkParseWhile(Token token);
bool checkParseWhileCond(Token curr_token, Token prev_token);
bool checkParseWhileBody(Token curr_token, Token prev_token);
bool checkParseArrayData(Token curr_token, Token prev_token);
bool checkParseArrayName(Token token);
bool checkParsePrintf(Token token);
bool checkParseReturn(Token token);
bool checkParseStringLexeme(Token token);
bool checkParseSymbolLexeme(Token token);
bool checkParseDigitId(Token token);
bool checkParseSymbolId(Token token);
bool checkParseBreak(Token token);
bool checkParseAssignment(Token token);
bool checkParseBinOperation(Token token);
bool checkParseUnaryOperation(Token token);
bool checkParseLogicOperation(Token token);
bool checkParseTernarOperation(Token token);

bool CheckRightParenError(Token next_token, Token curr_token);
bool CheckLeftParenError(Token token);
bool checkRightBraceError(Token token);
bool checkLeftBraceError(Token token);
bool checkConstNextTokError(Token next_token, Token curr_token);
bool checkDataTypeNextTokError(Token next_token, Token curr_token);
bool checkReturnNextTokError(Token next_token, Token curr_token);
bool checkSemicolonAndCommaError(Token curr_token, Token prev_token);
bool checkEndOfOperatorError(Token curr_token, Token next_token);
