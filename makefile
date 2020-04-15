comp := bin/compiler/my-compiler
examp_array_min := bin/examples/array_min
examp_substr := bin/examples/substr
examp_nod := bin/examples/nod
lexer_test := bin/test/lexer_tests
parser_test := bin/test/parser_tests
SymTab_test := bin/test/SymTab_tests
semantic_test := bin/test/semantic_tests
G++ := g++

.PHONY: all clean dir

all: $(comp) $(examp_array_min) $(examp_substr) $(examp_nod) $(lexer_test) $(parser_test) $(SymTab_test) $(semantic_test)

#compiler

$(comp): build/compiler/main.o build/compiler/Lexer.o build/compiler/Token.o build/compiler/CheckStdLexemes.o build/compiler/Handler.o 
$(comp): build/compiler/ParseArray.o build/compiler/ParseFor.o build/compiler/ParseIf.o build/compiler/ParseMainFunc.o build/compiler/ParseOps.o
$(comp): build/compiler/ParseSimpleNodes.o build/compiler/ParseOtherNodes.o build/compiler/ParseWhile.o build/compiler/CheckError.o 
$(comp): build/compiler/MainFuncAST.o build/compiler/OpsAST.o build/compiler/ArrayAST.o build/compiler/ForAST.o build/compiler/IfAST.o 
$(comp): build/compiler/OtherNodesAST.o build/compiler/SimpleNodesAST.o build/compiler/WhileAST.o build/compiler/PrintAST.o
$(comp): build/compiler/SymTab.o build/compiler/CheckSymTabError.o build/compiler/Sema.o build/compiler/checkSemanticError.o
	
	$(G++) $(CFLAGS) build/compiler/main.o build/compiler/Lexer.o build/compiler/Token.o build/compiler/CheckStdLexemes.o build/compiler/Handler.o build/compiler/ParseArray.o build/compiler/ParseFor.o build/compiler/ParseIf.o build/compiler/ParseMainFunc.o build/compiler/ParseOps.o build/compiler/ParseSimpleNodes.o build/compiler/ParseOtherNodes.o build/compiler/ParseWhile.o build/compiler/CheckError.o build/compiler/MainFuncAST.o build/compiler/OpsAST.o build/compiler/ArrayAST.o build/compiler/ForAST.o build/compiler/IfAST.o build/compiler/OtherNodesAST.o build/compiler/SimpleNodesAST.o build/compiler/WhileAST.o build/compiler/PrintAST.o build/compiler/SymTab.o build/compiler/CheckSymTabError.o build/compiler/Sema.o build/compiler/checkSemanticError.o -o $(comp)

build/compiler/main.o: src/main.cpp 
	$(G++) $(CFLAGS) -c src/main.cpp -o build/compiler/main.o -Isrc/lexer -Isrc/parser -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic

build/compiler/Lexer.o: src/lexer/Lexer.cpp
	$(G++) $(CFLAGS) -c src/lexer/Lexer.cpp -o build/compiler/Lexer.o
build/compiler/Token.o: src/lexer/Token.cpp
	$(G++) $(CFLAGS) -c src/lexer/Token.cpp -o build/compiler/Token.o
build/compiler/CheckStdLexemes.o: src/lexer/CheckStdLexemes.cpp
	$(G++) $(CFLAGS) -c src/lexer/CheckStdLexemes.cpp -o build/compiler/CheckStdLexemes.o

build/compiler/Handler.o: src/parser/Handler.cpp
	$(G++) $(CFLAGS) -c src/parser/Handler.cpp -o build/compiler/Handler.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/compiler/ParseArray.o: src/parser/ParseArray.cpp
	$(G++) $(CFLAGS) -c src/parser/ParseArray.cpp -o build/compiler/ParseArray.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/compiler/ParseFor.o: src/parser/ParseFor.cpp
	$(G++) $(CFLAGS) -c src/parser/ParseFor.cpp -o build/compiler/ParseFor.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/compiler/ParseIf.o: src/parser/ParseIf.cpp
	$(G++) $(CFLAGS) -c src/parser/ParseIf.cpp -o build/compiler/ParseIf.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/compiler/ParseMainFunc.o: src/parser/ParseMainFunc.cpp
	$(G++) $(CFLAGS) -c src/parser/ParseMainFunc.cpp -o build/compiler/ParseMainFunc.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/compiler/ParseOps.o: src/parser/ParseOps.cpp
	$(G++) $(CFLAGS) -c src/parser/ParseOps.cpp -o build/compiler/ParseOps.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/compiler/ParseSimpleNodes.o: src/parser/ParseSimpleNodes.cpp
	$(G++) $(CFLAGS) -c src/parser/ParseSimpleNodes.cpp -o build/compiler/ParseSimpleNodes.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/compiler/ParseOtherNodes.o: src/parser/ParseOtherNodes.cpp
	$(G++) $(CFLAGS) -c src/parser/ParseOtherNodes.cpp -o build/compiler/ParseOtherNodes.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/compiler/ParseWhile.o: src/parser/ParseWhile.cpp
	$(G++) $(CFLAGS) -c src/parser/ParseWhile.cpp -o build/compiler/ParseWhile.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/compiler/CheckError.o: src/parser/CheckError.cpp
	$(G++) $(CFLAGS) -c src/parser/CheckError.cpp -o build/compiler/CheckError.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic

build/compiler/MainFuncAST.o: src/parser/AST/MainFuncAST.cpp
	$(G++) $(CFLAGS) -c src/parser/AST/MainFuncAST.cpp -o build/compiler/MainFuncAST.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic -Isrc/parser
build/compiler/OpsAST.o: src/parser/AST/OpsAST.cpp
	$(G++) $(CFLAGS) -c src/parser/AST/OpsAST.cpp -o build/compiler/OpsAST.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic -Isrc/parser
build/compiler/ArrayAST.o: src/parser/AST/ArrayAST.cpp
	$(G++) $(CFLAGS) -c src/parser/AST/ArrayAST.cpp -o build/compiler/ArrayAST.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic -Isrc/parser
build/compiler/ForAST.o: src/parser/AST/ForAST.cpp
	$(G++) $(CFLAGS) -c src/parser/AST/ForAST.cpp -o build/compiler/ForAST.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic -Isrc/parser
build/compiler/IfAST.o: src/parser/AST/IfAST.cpp
	$(G++) $(CFLAGS) -c src/parser/AST/IfAST.cpp -o build/compiler/IfAST.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic -Isrc/parser
build/compiler/WhileAST.o: src/parser/AST/WhileAST.cpp
	$(G++) $(CFLAGS) -c src/parser/AST/WhileAST.cpp -o build/compiler/WhileAST.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic -Isrc/parser
build/compiler/OtherNodesAST.o: src/parser/AST/OtherNodesAST.cpp
	$(G++) $(CFLAGS) -c src/parser/AST/OtherNodesAST.cpp -o build/compiler/OtherNodesAST.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic -Isrc/parser
build/compiler/SimpleNodesAST.o: src/parser/AST/SimpleNodesAST.cpp
	$(G++) $(CFLAGS) -c src/parser/AST/SimpleNodesAST.cpp -o build/compiler/SimpleNodesAST.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic -Isrc/parser
build/compiler/PrintAST.o: src/parser/AST/PrintAST.cpp
	$(G++) $(CFLAGS) -c src/parser/AST/PrintAST.cpp -o build/compiler/PrintAST.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic -Isrc/parser

build/compiler/SymTab.o: src/symbol_table/SymTab.cpp
	$(G++) $(CFLAGS) -c src/symbol_table/SymTab.cpp -o build/compiler/SymTab.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic -Isrc/parser
build/compiler/CheckSymTabError.o: src/symbol_table/CheckSymTabError.cpp
	$(G++) $(CFLAGS) -c src/symbol_table/CheckSymTabError.cpp -o build/compiler/CheckSymTabError.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic -Isrc/parser


build/compiler/Sema.o: src/semantic/Sema.cpp
	$(G++) $(CFLAGS) -c src/semantic/Sema.cpp -o build/compiler/Sema.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic -Isrc/parser
build/compiler/checkSemanticError.o: src/semantic/checkSemanticError.cpp
	$(G++) $(CFLAGS) -c src/semantic/checkSemanticError.cpp -o build/compiler/checkSemanticError.o -Isrc/lexer -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic -Isrc/parser

#examples

$(examp_array_min): build/examples/array_min.o
	$(G++) $(CFLAGS) build/examples/array_min.o -o $(examp_array_min)
build/examples/array_min.o: examples/array_min.c 
	$(G++) $(CFLAGS) -c examples/array_min.c -o build/examples/array_min.o

$(examp_substr): build/examples/substr.o
	$(G++) $(CFLAGS) build/examples/substr.o -o $(examp_substr)
build/examples/substr.o: examples/substr.c 
	$(G++) $(CFLAGS) -c examples/substr.c -o build/examples/substr.o

$(examp_nod): build/examples/nod.o
	$(G++) $(CFLAGS) build/examples/nod.o -o $(examp_nod)
build/examples/nod.o: examples/nod.c 
	$(G++) $(CFLAGS) -c examples/nod.c -o build/examples/nod.o



#lexer tests

$(lexer_test): build/test/main.o build/test/lexer_tests.o build/compiler/Lexer.o build/compiler/Token.o build/compiler/CheckStdLexemes.o 
	$(G++) $(CFLAGS) build/test/main.o build/test/lexer_tests.o build/compiler/Lexer.o build/compiler/Token.o build/compiler/CheckStdLexemes.o -lgtest -lpthread -o $(lexer_test)

build/test/main.o: test/main.cpp
	$(G++) $(CFLAGS) -c test/main.cpp -o build/test/main.o 
build/test/lexer_tests.o: test/lexer/lexer_tests.cpp
	$(G++) $(CFLAGS) -c test/lexer/lexer_tests.cpp -o build/test/lexer_tests.o -Isrc/lexer



#parser tests

$(parser_test): build/test/main.o build/test/parse_build_AST_tests.o build/test/parse_main_func_tests.o build/test/parse_for_tests.o 
$(parser_test):	build/test/parse_while_tests.o build/test/parse_if_tests.o build/test/parse_array_tests.o build/test/parse_operations_tests.o 
$(parser_test):	build/test/parse_other_nodes_tests.o build/test/parse_simple_nodes_tests.o build/compiler/Lexer.o build/compiler/Token.o 
$(parser_test): build/compiler/CheckStdLexemes.o build/compiler/Handler.o build/compiler/ParseArray.o build/compiler/ParseFor.o build/compiler/ParseIf.o 
$(parser_test): build/compiler/ParseMainFunc.o build/compiler/ParseOps.o build/compiler/ParseSimpleNodes.o build/compiler/ParseOtherNodes.o 
$(parser_test): build/compiler/ParseWhile.o build/compiler/CheckError.o build/compiler/MainFuncAST.o build/compiler/OpsAST.o build/compiler/ArrayAST.o 
$(parser_test): build/compiler/ForAST.o build/compiler/IfAST.o build/compiler/OtherNodesAST.o build/compiler/SimpleNodesAST.o build/compiler/WhileAST.o 
$(parser_test):	build/compiler/PrintAST.o build/compiler/Sema.o build/compiler/checkSemanticError.o
	$(G++) $(CFLAGS) build/test/main.o build/test/parse_build_AST_tests.o build/test/parse_main_func_tests.o build/test/parse_for_tests.o build/test/parse_while_tests.o build/test/parse_if_tests.o build/test/parse_array_tests.o build/test/parse_operations_tests.o build/test/parse_other_nodes_tests.o build/test/parse_simple_nodes_tests.o build/compiler/Lexer.o build/compiler/Token.o build/compiler/CheckStdLexemes.o build/compiler/Handler.o build/compiler/ParseArray.o build/compiler/ParseFor.o build/compiler/ParseIf.o build/compiler/ParseMainFunc.o build/compiler/ParseOps.o build/compiler/ParseSimpleNodes.o build/compiler/ParseOtherNodes.o build/compiler/ParseWhile.o build/compiler/CheckError.o build/compiler/MainFuncAST.o build/compiler/OpsAST.o build/compiler/ArrayAST.o build/compiler/ForAST.o build/compiler/IfAST.o build/compiler/OtherNodesAST.o build/compiler/SimpleNodesAST.o build/compiler/WhileAST.o build/compiler/PrintAST.o build/compiler/Sema.o build/compiler/checkSemanticError.o  -lgtest -lpthread -o $(parser_test)

build/test/parse_build_AST_tests.o: test/parser/parse_build_AST_tests.cpp
	$(G++) $(CFLAGS) -c test/parser/parse_build_AST_tests.cpp -o build/test/parse_build_AST_tests.o -Isrc/lexer -Isrc/parser -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/test/parse_main_func_tests.o: test/parser/parse_main_func_tests.cpp
	$(G++) $(CFLAGS) -c test/parser/parse_main_func_tests.cpp -o build/test/parse_main_func_tests.o -Isrc/lexer -Isrc/parser -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/test/parse_for_tests.o: test/parser/parse_for_tests.cpp
	$(G++) $(CFLAGS) -c test/parser/parse_for_tests.cpp -o build/test/parse_for_tests.o -Isrc/lexer -Isrc/parser -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/test/parse_while_tests.o: test/parser/parse_while_tests.cpp
	$(G++) $(CFLAGS) -c test/parser/parse_while_tests.cpp -o build/test/parse_while_tests.o -Isrc/lexer -Isrc/parser -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/test/parse_if_tests.o: test/parser/parse_if_tests.cpp
	$(G++) $(CFLAGS) -c test/parser/parse_if_tests.cpp -o build/test/parse_if_tests.o -Isrc/lexer -Isrc/parser -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/test/parse_array_tests.o: test/parser/parse_array_tests.cpp
	$(G++) $(CFLAGS) -c test/parser/parse_array_tests.cpp -o build/test/parse_array_tests.o -Isrc/lexer -Isrc/parser -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/test/parse_operations_tests.o: test/parser/parse_operations_tests.cpp 
	$(G++) $(CFLAGS) -c test/parser/parse_operations_tests.cpp -o build/test/parse_operations_tests.o -Isrc/lexer -Isrc/parser -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/test/parse_other_nodes_tests.o: test/parser/parse_other_nodes_tests.cpp
	$(G++) $(CFLAGS) -c test/parser/parse_other_nodes_tests.cpp -o build/test/parse_other_nodes_tests.o -Isrc/lexer -Isrc/parser -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic
build/test/parse_simple_nodes_tests.o: test/parser/parse_simple_nodes_tests.cpp
	$(G++) $(CFLAGS) -c test/parser/parse_simple_nodes_tests.cpp -o build/test/parse_simple_nodes_tests.o -Isrc/lexer -Isrc/parser -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic



#SymTab tests

$(SymTab_test): build/test/main.o build/test/SymTab_tests.o build/compiler/CheckSymTabError.o build/compiler/SymTab.o
	$(G++) $(CFLAGS) build/test/main.o build/test/SymTab_tests.o build/compiler/CheckSymTabError.o build/compiler/SymTab.o -lgtest -lpthread -o $(SymTab_test)

build/test/SymTab_tests.o: test/symbol_table/SymTab_tests.cpp
	$(G++) $(CFLAGS) -c test/symbol_table/SymTab_tests.cpp -o build/test/SymTab_tests.o -Isrc/lexer -Isrc/parser -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic



#semantic tests

$(semantic_test): build/test/main.o build/test/semantic_tests.o build/compiler/checkSemanticError.o build/compiler/Sema.o
	$(G++) $(CFLAGS) build/test/main.o build/test/semantic_tests.o build/compiler/checkSemanticError.o build/compiler/Sema.o -lgtest -lpthread -o $(semantic_test)

build/test/semantic_tests.o: test/semantic/Semantic_tests.cpp
	$(G++) $(CFLAGS) -c test/semantic/Semantic_tests.cpp -o build/test/semantic_tests.o -Isrc/lexer -Isrc/parser -Isrc/parser/AST -Isrc/symbol_table -Isrc/semantic


#Сборка

compiler: bin/compiler/my-compiler
	bin/compiler/my-compiler

array_min: bin/examples/array_min
	bin/examples/array_min

substr: bin/examples/substr
	bin/examples/substr

nod: bin/examples/nod
	bin/examples/nod

lexer_test: bin/test/lexer_tests
	bin/test/lexer_tests

parser_test: bin/test/parser_tests
	bin/test/parser_tests

SymTab_test: bin/test/SymTab_tests
	bin/test/SymTab_tests

semantic_test: bin/test/semantic_tests
	bin/test/semantic_tests

clean:
	@rm -rf build/test/*.o
	@rm -rf build/examples/*.o
	@rm -rf build/compiler/*.o
	@rm -rf bin/test/*
	@rm -rf bin/examples/*
	@rm -rf bin/compiler/*

dir:
	@mkdir build
	@mkdir build/test
	@mkdir build/examples
	@mkdir build/compiler
	@mkdir bin
	@mkdir bin/test
	@mkdir bin/examples
	@mkdir bin/compiler