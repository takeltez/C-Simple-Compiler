#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AST 
{
	public:
  		virtual ~AST() {}
};

class DataTypeAST : public AST 
{
  public:
      AST *identificator;

  public:
      string definition;
      DataTypeAST(AST *identificator, Token token);
};

class ConstAST : public AST 
{
  public:
      AST *identificator;

  public:
      string definition;
      ConstAST(AST *identificator, Token token);
};

class MainFunctionAST : public AST 
{
  public:
      AST *args;
      AST *body;

	public:
      string definition;
  		MainFunctionAST(AST *args, AST *body, Token token);
};

class MainFunctionBodyAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    MainFunctionBodyAST(vector <AST*> blocks);
};

class MainFunctionArgsAST : public AST 
{
  public:
      vector <AST*> args;

  public:
    string definition;
    MainFunctionArgsAST(vector <AST*> args);
};


class PrintfAST : public AST 
{
  public:
      vector <AST*> params;

  public:
      string definition;
      PrintfAST(vector <AST*> params, Token token);
};

class ReturnAST : public AST 
{
  public:
      AST *identificator;

  public:
      string definition;
      ReturnAST(AST *identificator, Token token);
};


class AssignmentAST : public AST 
{
  public:
      AST *r_operand;
      AST *l_operand;

  public:
      string definition;
      AssignmentAST(AST *r_operand, AST *l_operand, Token token);
};

class LogicOperationAST : public AST 
{
  public:
      AST *r_operand;
      AST *l_operand;

  public:
      string definition;
      LogicOperationAST(AST *r_operand, AST *l_operand, Token token);
};

class TernarOperationAST : public AST 
{
  public:
      AST *r_operand;
      AST *l_operand;

  public:
      string definition;
      TernarOperationAST(AST *r_operand, AST *l_operand, Token token);
};

class BinOperationAST : public AST 
{
  public:
      AST *r_operand;
      AST *l_operand;

  public:
      string definition;
      BinOperationAST(AST *r_operand, AST *l_operand, Token token);
};

class UnaryOperationAST : public AST 
{
  public:
      AST *operand;

  public:
      string definition;
      UnaryOperationAST(AST *operand, Token token);
};

class PointerAST : public AST 
{
  public:
      AST *identificator;

  public:
      string definition;
      PointerAST(AST *identificator, Token token);
};


class IfAST : public AST 
{
  public:
      AST *condition;
      AST *body;

  public:
      string definition;
      IfAST(AST *condition, AST *body, Token token);
};

class IfBodyAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    IfBodyAST(vector <AST*> blocks);
};

class IfConditionAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    IfConditionAST(vector <AST*> blocks);
};


class WhileAST : public AST 
{
  public:
      AST *condition;
      AST *body;

  public:
      string definition;
      WhileAST(AST *condition, AST *body, Token token);
};

class WhileBodyAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    WhileBodyAST(vector <AST*> blocks);
};

class WhileConditionAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    WhileConditionAST(vector <AST*> blocks);
};


class ForAST : public AST 
{
  public:
      AST *condition;
      AST *body;

  public:
      string definition;
      ForAST(AST *condition, AST *body, Token token);
};

class ForBodyAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    ForBodyAST(vector <AST*> blocks);
};

class ForConditionAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    ForConditionAST(vector <AST*> blocks);
};


class ArrayDataAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    ArrayDataAST(vector <AST*> blocks);
};

class ArrayNameAST : public AST 
{
  public:
       AST *identificator;

  public:
    string definition;
    ArrayNameAST(AST *identificator, Token token);
};


class StringLexemeAST : public AST 
{
  public:
      string definition;
      StringLexemeAST(Token token);
};

class DigitIdAST : public AST 
{
  public:
      int definition;
      DigitIdAST(Token token);
};

class SymbolIdAST : public AST 
{
  public:
      string definition;
      SymbolIdAST(Token token);
};

class BreakAST : public AST 
{
  public:
      string definition;
      BreakAST(Token token);
};

void printAST (AST *tree);
void printAST1 (AST *tree);
void printAST2 (AST *tree);
void printAST3 (AST *tree);