#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AST 
{
	public:
      void level(int lvl) 
      {
          for (int i = 0; i < lvl; ++i)
            cout<<"----";

          cout<<"|";
      }
  		
      virtual void print(int lvl) {}
      
      virtual ~AST() {}
};

class DataTypeAST : public AST 
{
  public:
      AST *identificator;

  public:
      string definition;
      DataTypeAST(AST *identificator, Token token);
      void print(int lvl) override;
};

class ConstAST : public AST 
{
  public:
      AST *identificator;

  public:
      string definition;
      ConstAST(AST *identificator, Token token);
      void print(int lvl) override;
};

class MainFunctionAST : public AST 
{
  public:
      AST *args;
      AST *body;

	public:
      string definition;
  		MainFunctionAST(AST *args, AST *body, Token token);
      void print(int lvl) override;
};

class MainFunctionBodyAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    MainFunctionBodyAST(vector <AST*> blocks);
    void print(int lvl) override;
};

class MainFunctionArgsAST : public AST 
{
  public:
      vector <AST*> args;

  public:
    string definition;
    MainFunctionArgsAST(vector <AST*> args);
    void print(int lvl) override;
};


class PrintfAST : public AST 
{
  public:
      vector <AST*> params;

  public:
      string definition;
      PrintfAST(vector <AST*> params, Token token);
      void print(int lvl) override;
};

class ReturnAST : public AST 
{
  public:
      AST *identificator;

  public:
      string definition;
      ReturnAST(AST *identificator, Token token);
      void print(int lvl) override;
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
};

class UnaryOperationAST : public AST 
{
  public:
      AST *operand;

  public:
      string definition;
      UnaryOperationAST(AST *operand, Token token);
      void print(int lvl) override;
};

class PointerAST : public AST 
{
  public:
      AST *identificator;

  public:
      string definition;
      PointerAST(AST *identificator, Token token);
      void print(int lvl) override;
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
};

class IfBodyAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    IfBodyAST(vector <AST*> blocks);
    void print(int lvl) override;
};

class IfConditionAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    IfConditionAST(vector <AST*> blocks);
    void print(int lvl) override;
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
};

class WhileBodyAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    WhileBodyAST(vector <AST*> blocks);
    void print(int lvl) override;
};

class WhileConditionAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    WhileConditionAST(vector <AST*> blocks);
    void print(int lvl) override;
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
};

class ForBodyAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    ForBodyAST(vector <AST*> blocks);
    void print(int lvl) override;
};

class ForConditionAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    ForConditionAST(vector <AST*> blocks);
    void print(int lvl) override;
};


class ArrayDataAST : public AST 
{
  public:
      vector <AST*> blocks;

  public:
    string definition;
    ArrayDataAST(vector <AST*> blocks);
    void print(int lvl) override;
};

class ArrayNameAST : public AST 
{
  public:
       AST *identificator;

  public:
    string definition;
    ArrayNameAST(AST *identificator, Token token);
    void print(int lvl) override;
};


class StringLexemeAST : public AST 
{
  public:
      string definition;
      StringLexemeAST(Token token);
      void print(int lvl) override;
};

class DigitIdAST : public AST 
{
  public:
      int definition;
      DigitIdAST(Token token);
      void print(int lvl) override;
};

class SymbolIdAST : public AST 
{
  public:
      string definition;
      SymbolIdAST(Token token);
      void print(int lvl) override;
};

class BreakAST : public AST 
{
  public:
      string definition;
      BreakAST(Token token);
      void print(int lvl) override;
};

void printAST (AST *tree);
void printAST1 (AST *tree);
void printAST2 (AST *tree);
void printAST3 (AST *tree);

void printRootNode(AST *tree);
void printDataTypeNode(void);
void printMainFuncNode(void);
void printMainFuncArgsNode(void);
void printSymbolIdNode(void);
void printConstNode(void);
void printPtrNode(void);
void printMainFuncBodyNode(void);
void printAssignmentNode(void);
void printBinOpNode(void);
void printDigitIdNode(void);