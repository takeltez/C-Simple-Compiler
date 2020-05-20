#pragma once

using namespace std;

class CodGen
{
	public:
		CodGen();
		void printAsm(void);
		void handleProlog(void);
		void handleEpilog(void);
		void compileAsmFile(void);
		void setFileName(string file_path);
		void startCodGen(AST *tree, string file_path);
		void handleAsmMov(void);
		void handleAsmAdd(void);
		void handleAsmSub(void);
		void handleAsmMul(void);
		void handleAsmDiv(void);
		void handleAsmCmp(void);
		void handleAsmCondPassIf(void);
		void handleAsmCondPassLoop(void);
		void handleAsmJmp(void);
};