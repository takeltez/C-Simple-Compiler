#pragma once

using namespace std;

class CodGen
{
	public:
		CodGen();
		void printAsm(void);
		void printProlog(void);
		void printEpilog(void);
		void handleAsmMov(void);
		void compileAsmFile(void);
		void setFileName(string file_path);
		void startCodGen(AST *tree, string file_path);
};