#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AST 
{
	public:
      void level(int lvl);	
      virtual void print(int lvl) {}
      virtual void semantic() {}
      virtual ~AST() {}
};

class RootAST : public AST 
{
  public:
    vector <AST*> blocks;

  public:
    string definition;
    RootAST(vector <AST*> blocks);
    void print(int lvl) override;
    void semantic(void) override;
};

class DataTypeAST : public AST 
{
  public:
      AST *identificator;

  public:
      string definition;
      DataTypeAST(AST *identificator, Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class ConstAST : public AST 
{
  public:
      AST *identificator;

  public:
      string definition;
      ConstAST(AST *identificator, Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class FunctionAST : public AST 
{
  public:
      AST *args;
      AST *body;

	public:
      string definition;
  		FunctionAST(AST *args, AST *body, Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class FunctionBodyAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    FunctionBodyAST(vector <AST*> blocks);
    void print(int lvl) override;
    void semantic(void) override;
};

class FunctionArgsAST : public AST 
{
  public:
      vector <AST*> args;

  public:
    string definition;
    FunctionArgsAST(vector <AST*> args);
    void print(int lvl) override;
    void semantic(void) override;
};


class PrintfAST : public AST 
{
  public:
      vector <AST*> params;

  public:
      string definition;
      PrintfAST(vector <AST*> params, Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class ReturnAST : public AST 
{
  public:
      AST *identificator;

  public:
      string definition;
      ReturnAST(AST *identificator, Token token);
      void print(int lvl) override;
      void semantic(void) override;
};


class AssignmentAST : public AST 
{
  public:
      AST *r_operand;
      AST *l_operand;

  public:
      string definition;
      AssignmentAST(AST *r_operand, AST *l_operand, Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class LogicOperationAST : public AST 
{
  public:
      AST *r_operand;
      AST *l_operand;

  public:
      string definition;
      LogicOperationAST(AST *r_operand, AST *l_operand, Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class TernarOperationAST : public AST 
{
  public:
      AST *r_operand;
      AST *l_operand;

  public:
      string definition;
      TernarOperationAST(AST *r_operand, AST *l_operand, Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class BinOperationAST : public AST 
{
  public:
      AST *r_operand;
      AST *l_operand;

  public:
      string definition;
      BinOperationAST(AST *r_operand, AST *l_operand, Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class UnaryOperationAST : public AST 
{
  public:
      AST *operand;

  public:
      string definition;
      UnaryOperationAST(AST *operand, Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class PointerAST : public AST 
{
  public:
      AST *identificator;

  public:
      string definition;
      PointerAST(AST *identificator, Token token);
      void print(int lvl) override;
      void semantic(void) override;
};


class IfAST : public AST 
{
  public:
      AST *condition;
      AST *body;

  public:
      string definition;
      IfAST(AST *condition, AST *body, Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class IfBodyAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    IfBodyAST(vector <AST*> blocks);
    void print(int lvl) override;
    void semantic(void) override;
};

class IfConditionAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    IfConditionAST(vector <AST*> blocks);
    void print(int lvl) override;
    void semantic(void) override;
};


class WhileAST : public AST 
{
  public:
      AST *condition;
      AST *body;

  public:
      string definition;
      WhileAST(AST *condition, AST *body, Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class WhileBodyAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    WhileBodyAST(vector <AST*> blocks);
    void print(int lvl) override;
    void semantic(void) override;
};

class WhileConditionAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    WhileConditionAST(vector <AST*> blocks);
    void print(int lvl) override;
    void semantic(void) override;
};


class ForAST : public AST 
{
  public:
      AST *condition;
      AST *body;

  public:
      string definition;
      ForAST(AST *condition, AST *body, Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class ForBodyAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    ForBodyAST(vector <AST*> blocks);
    void print(int lvl) override;
    void semantic(void) override;
};

class ForConditionAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    ForConditionAST(vector <AST*> blocks);
    void print(int lvl) override;
    void semantic(void) override;
};


class ArrayDataAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    ArrayDataAST(vector <AST*> blocks);
    void print(int lvl) override;
    void semantic(void) override;
};

class ArrayNameAST : public AST 
{
  public:
       AST *identificator;

  public:
    string definition;
    ArrayNameAST(AST *identificator, Token token);
    void print(int lvl) override;
    void semantic(void) override;
};


class StringLexemeAST : public AST 
{
  public:
      string definition;
      StringLexemeAST(Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class SymbolLexemeAST : public AST 
{
  public:
      string definition;
      SymbolLexemeAST(Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class DigitIdAST : public AST 
{
  public:
      string definition;
      DigitIdAST(Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class SymbolIdAST : public AST 
{
  public:
      string definition;
      SymbolIdAST(Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

class BreakAST : public AST 
{
  public:
      string definition;
      BreakAST(Token token);
      void print(int lvl) override;
      void semantic(void) override;
};

void printAST (AST *tree);