#include "Lexer.h"

string Lexer::checkStdLexemes(string lexeme) { //Вывод классов токенов

	if (lexeme == "++") {
		return "arithmetic_operator_++";
	}

	if (lexeme == "--") {
		return "arithmetic_operator_--";
	}

	if (lexeme == "=") {
		return "arithmetic_operator_=";
	}

	if (lexeme == "-") {
		return "arithmetic_operator_-";
	}

	if (lexeme == "+") {
		return "arithmetic_operator_+";
	}

	if (lexeme == "*") {
		return "arithmetic_operator_*";
	}

	if (lexeme == "/") {
		return "arithmetic_operator_/";
	}

	if (lexeme == "%") {
		return "arithmetic_operator_%";
	}

	if (lexeme == "+=") {
		return "arithmetic_operator_+=";
	}

	if (lexeme == "-=") {
		return "arithmetic_operator_-=";
	}

	if (lexeme == "*=") {
		return "arithmetic_operator_*=";
	}

	if (lexeme == "/=") {
		return "arithmetic_operator_/=";
	}

	if (lexeme == "%=") {
		return "arithmetic_operator_%=";
	}

	if (lexeme == "==") {
		return "compare_operator_==";
	}

	if (lexeme == "!=") {
		return "compare_operator_!=";
	}

	if (lexeme == ">=") {
		return "compare_operator_>=";
	}

	if (lexeme == "<=") {
		return "compare_operator_<=";
	}

	if (lexeme == ">") {
		return "compare_operator_>";
	}

	if (lexeme == "<") {
		return "compare_operator_<";
	}

	if (lexeme == "int") {
		return "data_type_int";
	}

	if (lexeme == "char") {
		return "data_type_char";
	}

	if (lexeme == "float") {
		return "data_type_float";
	}

	if (lexeme == "double") {
		return "data_type_double";
	}

	if (lexeme == "void") {
		return "data_type_void";
	}

	if (lexeme == "define") {
		return "key_word_define";
	}

	if (lexeme == "include") {
		return "key_word_include";
	}

	if (lexeme == "return") {
		return "key_word_return";
	}

	if (lexeme == "break") {
		return "key_word_break";
	}

	if (lexeme == "continue") {
		return "key_word_continue";
	}

	if (lexeme == "for") {
		return "key_word_for";
	}

	if (lexeme == "if") {
		return "key_word_if";
	}

	if (lexeme == "else") {
		return "key_word_else";
	}

	if (lexeme == "while") {
		return "key_word_while";
	}

	if (lexeme == "argc") {
		return "key_word_argc";
	}

	if (lexeme == "argv") {
		return "key_word_argv";
	}

	if (lexeme == "const") {
		return "key_word_const";
	}

	if (lexeme == "!") {
		return "logic_operator_!";
	}

	if (lexeme == "&&") {
		return "logic_operator_&&";
	}

	if (lexeme == "||") {
		return "logic_operator_||";
	}

	if (lexeme == "(") {
		return "right_paren_(";
	}

	if (lexeme == ")") {
		return "left_paren_)";
	}

	if (lexeme == "[") {
		return "right_paren_[";
	}

	if (lexeme == "]") {
		return "left_paren_]";
	}

	if (lexeme == "{") {
		return "right_paren_{";
	}

	if (lexeme == "}") {
		return "left_paren_}";
	}

	if (lexeme == "#") {
		return "spec_symbol_#";	
	}

	if (lexeme == ";") {
		return "spec_symbol_;";	
	}

	if (lexeme == ":") {
		return "spec_symbol_:";
	}

	if (lexeme == "?") {
		return "spec_symbol_?";
	}

	if (lexeme == ",") {
		return "spec_symbol_,";
	}

	if (lexeme == ".") {
		return "spec_symbol_.";
	}

	if (lexeme == "&") {
		return "spec_symbol_&";
	}

	if (lexeme == "main") {
		return "std_function_main";
	}

	if (lexeme == "printf") {
		return "std_function_printf";
	}

	if (lexeme == "strlen") {
		return "std_function_strlen";
	}

	if (lexeme == "stdio") {
		return "std_header_stdio";
	}

	if (lexeme == "stdlib") {
		return "std_header_stdlib";
	}

	if (lexeme == "string") {
		return "std_header_string";
	}

	return NOLEXEME;
}