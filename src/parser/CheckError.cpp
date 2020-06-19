#include "Parser.h"


//nodes

bool checkRootTok(Token tok)
{
	return (tok.getTokenClass() =="data_type_int" || tok.getTokenClass() == "data_type_char" 
			|| tok.getTokenClass() == "data_type_float" || tok.getTokenClass() == "data_type_double" 
				|| tok.getTokenClass() == "data_type_void" || tok.getTokenClass() == "arithmetic_operator_=");
}

bool checkFuncArgsTok(Token tok)
{
	return (tok.getTokenClass() =="data_type_int" || tok.getTokenClass() == "data_type_char" 
			|| tok.getTokenClass() == "data_type_float" || tok.getTokenClass() == "data_type_double" 
				|| tok.getTokenClass() == "key_word_const" || tok.getTokenClass() == "left_paren_)");
}

bool checkBodyTok(Token tok)
{
	return (tok.getTokenClass() =="std_function_printf" || tok.getTokenClass() == "key_word_return" 
			|| tok.getTokenClass() == "variable" || tok.getTokenClass() =="arithmetic_operator_=" 
				|| tok.getTokenClass() =="data_type_int"|| tok.getTokenClass() == "data_type_char" 
					|| tok.getTokenClass() == "data_type_float" || tok.getTokenClass() == "data_type_double" 
						|| tok.getTokenClass() == "key_word_const" || tok.getTokenClass() == "key_word_if"
							|| tok.getTokenClass() == "key_word_while" || tok.getTokenClass() == "key_word_for"
								|| tok.getTokenClass() == "arithmetic_operator_++" || tok.getTokenClass() == "arithmetic_operator_%"
									|| tok.getTokenClass() == "arithmetic_operator_*" || tok.getTokenClass() == "arithmetic_operator_--"
										|| tok.getTokenClass() == "key_word_break" || tok.getTokenClass() == "array_name"
											|| tok.getTokenClass() == "key_word_else");
}

bool checkDataTypeTok(Token tok)
{
	return (tok.getTokenClass() == "function_name" || tok.getTokenClass() == "variable" 
			|| tok.getTokenClass() == "arithmetic_operator_*" || tok.getTokenClass() == "key_word_const"
				|| tok.getTokenClass() == "array_name");

}

bool checkConstTok(Token tok)
{
	return (tok.getTokenClass() =="data_type_int" || tok.getTokenClass() == "data_type_char" 
			|| tok.getTokenClass() == "data_type_float" || tok.getTokenClass() == "data_type_double" 
				|| tok.getTokenClass() == "variable" || tok.getTokenClass() == "arithmetic_operator_*" 
					|| tok.getTokenClass() == "array_name");
}

bool checkPrintfTok(Token tok)
{
	return (tok.getTokenClass() == "variable" || tok.getTokenClass() == "string_literal" 
			|| tok.getTokenClass() == "array_name");
}

bool checkReturnTok(Token tok)
{
	return (tok.getTokenClass() == "variable" || tok.getTokenClass() == "digit_literal_dec" 
			|| tok.getTokenClass() == "digit_literal_bin"|| tok.getTokenClass() == "digit_literal_hex" 
				|| tok.getTokenClass() == "digit_literal_oct" || tok.getTokenClass() == "array_name");
}

bool checkAssignmentTok(Token tok)
{
	return (tok.getTokenClass() == "variable" || tok.getTokenClass() == "digit_literal_dec" 
			|| tok.getTokenClass() == "digit_literal_bin"|| tok.getTokenClass() == "digit_literal_hex" 
				|| tok.getTokenClass() == "digit_literal_oct" || tok.getTokenClass() == "arithmetic_operator_+" 
					|| tok.getTokenClass() == "arithmetic_operator_-"|| tok.getTokenClass() == "arithmetic_operator_*" 
						|| tok.getTokenClass() == "arithmetic_operator_/" || tok.getTokenClass() == "right_paren_{"
							|| tok.getTokenClass() == "string_literal" || tok.getTokenClass() == "symbol_literal" || tok.getTokenClass() == "spec_symbol_?"
								|| tok.getTokenClass() == "compare_operator_==" || tok.getTokenClass() == "compare_operator_!=" 
									|| tok.getTokenClass() == "compare_operator_>=" || tok.getTokenClass() == "compare_operator_<="
										|| tok.getTokenClass() == "compare_operator_>" || tok.getTokenClass() == "compare_operator_<"
											|| tok.getTokenClass() == "array_name");
}

bool checkLogicOpTok(Token tok)
{
	return (tok.getTokenClass() == "variable" || tok.getTokenClass() == "digit_literal_dec" 
			|| tok.getTokenClass() == "digit_literal_bin"|| tok.getTokenClass() == "digit_literal_hex" 
				|| tok.getTokenClass() == "digit_literal_oct" || tok.getTokenClass() == "arithmetic_operator_+" 
					|| tok.getTokenClass() == "arithmetic_operator_-"|| tok.getTokenClass() == "arithmetic_operator_*" 
						|| tok.getTokenClass() == "arithmetic_operator_/" || tok.getTokenClass() == "compare_operator_==" 
							|| tok.getTokenClass() == "compare_operator_!=" || tok.getTokenClass() == "compare_operator_>="
								|| tok.getTokenClass() == "compare_operator_<=" || tok.getTokenClass() == "compare_operator_>" 
									|| tok.getTokenClass() == "compare_operator_<" || tok.getTokenClass() == "arithmetic_operator_%"
										|| tok.getTokenClass() == "array_name");
}

bool checkBinOpTok(Token tok)
{
	return (tok.getTokenClass() == "variable" || tok.getTokenClass() == "digit_literal_dec" 
			|| tok.getTokenClass() == "digit_literal_bin"|| tok.getTokenClass() == "digit_literal_hex" 
				|| tok.getTokenClass() == "digit_literal_oct" || tok.getTokenClass() == "string_literal" 
					|| tok.getTokenClass() == "symbol_literal" || tok.getTokenClass() == "array_name"
					  	||tok.getTokenClass() == "arithmetic_operator_+" || tok.getTokenClass() == "arithmetic_operator_-"
							|| tok.getTokenClass() == "arithmetic_operator_*" || tok.getTokenClass() == "arithmetic_operator_/"
								|| tok.getTokenClass() == "arithmetic_operator_-" || tok.getTokenClass() == "arithmetic_operator_*" 
									|| tok.getTokenClass() == "arithmetic_operator_/"  || tok.getTokenClass() == "arithmetic_operator_%");
}

bool checkTernarOpTok(Token tok)
{
	return (tok.getTokenClass() == "variable" || tok.getTokenClass() == "digit_literal_dec" 
			|| tok.getTokenClass() == "digit_literal_bin"|| tok.getTokenClass() == "digit_literal_hex" 
				|| tok.getTokenClass() == "digit_literal_oct" || tok.getTokenClass() == "spec_symbol_:" 
					|| tok.getTokenClass() == "array_name");
}


bool checkUnaryOpTok(Token tok)
{
	return (tok.getTokenClass() == "variable" || tok.getTokenClass() == "digit_literal_dec" 
			|| tok.getTokenClass() == "digit_literal_bin"|| tok.getTokenClass() == "digit_literal_hex" 
				|| tok.getTokenClass() == "digit_literal_oct" || tok.getTokenClass() == "array_name");
}

bool checkPonterTok(Token tok)
{
	return (tok.getTokenClass() == "variable" || tok.getTokenClass() == "arithmetic_operator_*" || tok.getTokenClass() == "array_name");

}

bool checkIfConditionTok(Token tok)
{
	return (tok.getTokenClass() == "variable" || tok.getTokenClass() == "digit_literal_dec" 
			|| tok.getTokenClass() == "digit_literal_bin"|| tok.getTokenClass() == "digit_literal_hex" 
				|| tok.getTokenClass() == "digit_literal_oct" || tok.getTokenClass() == "compare_operator_==" 
					|| tok.getTokenClass() == "compare_operator_!=" || tok.getTokenClass() == "compare_operator_>="
						|| tok.getTokenClass() == "compare_operator_<=" || tok.getTokenClass() == "compare_operator_>" 
							|| tok.getTokenClass() == "compare_operator_<" || tok.getTokenClass() == "logic_operator_&&"
							  	|| tok.getTokenClass() == "logic_operator_||" || tok.getTokenClass() == "arithmetic_operator_%"
							  		|| tok.getTokenClass() == "array_name" || tok.getTokenClass() == "arithmetic_operator_+" 
										|| tok.getTokenClass() == "arithmetic_operator_-"|| tok.getTokenClass() == "arithmetic_operator_*" 
											|| tok.getTokenClass() == "arithmetic_operator_/");
}

bool checkWhileConditionTok(Token tok)
{
	return (tok.getTokenClass() == "variable" || tok.getTokenClass() == "digit_literal_dec" 
			|| tok.getTokenClass() == "digit_literal_bin"|| tok.getTokenClass() == "digit_literal_hex" 
				|| tok.getTokenClass() == "digit_literal_oct" || tok.getTokenClass() == "compare_operator_==" 
					|| tok.getTokenClass() == "compare_operator_!=" || tok.getTokenClass() == "compare_operator_>="
						|| tok.getTokenClass() == "compare_operator_<=" || tok.getTokenClass() == "compare_operator_>" 
							|| tok.getTokenClass() == "compare_operator_<" || tok.getTokenClass() == "logic_operator_&&"
								|| tok.getTokenClass() == "logic_operator_||" || tok.getTokenClass() == "arithmetic_operator_%"
									|| tok.getTokenClass() == "array_name" || tok.getTokenClass() == "arithmetic_operator_+" 
										|| tok.getTokenClass() == "arithmetic_operator_-"|| tok.getTokenClass() == "arithmetic_operator_*" 
											|| tok.getTokenClass() == "arithmetic_operator_/");
}

bool checkForConditionTok(Token tok)
{
	return (tok.getTokenClass() == "variable" || tok.getTokenClass() == "digit_literal_dec" 
			|| tok.getTokenClass() == "digit_literal_bin"|| tok.getTokenClass() == "digit_literal_hex" 
				|| tok.getTokenClass() == "digit_literal_oct" || tok.getTokenClass() == "compare_operator_!=" 
					|| tok.getTokenClass() == "compare_operator_>="|| tok.getTokenClass() == "compare_operator_<=" 
						|| tok.getTokenClass() == "compare_operator_>" 	|| tok.getTokenClass() == "compare_operator_<" 
							|| tok.getTokenClass() == "arithmetic_operator_++" || tok.getTokenClass() == "arithmetic_operator_--"
								||tok.getTokenClass() =="data_type_int" || tok.getTokenClass() == "data_type_char" 
									|| tok.getTokenClass() == "data_type_float" || tok.getTokenClass() == "data_type_double" 
										|| tok.getTokenClass() =="arithmetic_operator_=" || tok.getTokenClass() == "compare_operator_=="
											|| tok.getTokenClass() == "logic_operator_&&"|| tok.getTokenClass() == "logic_operator_||"
												|| tok.getTokenClass() == "arithmetic_operator_%" || tok.getTokenClass() == "array_name"
													|| tok.getTokenClass() == "arithmetic_operator_+" || tok.getTokenClass() == "arithmetic_operator_-"
														|| tok.getTokenClass() == "arithmetic_operator_*" || tok.getTokenClass() == "arithmetic_operator_/");
}

bool checkArrayDataTok(Token tok)
{
	return (tok.getTokenClass() == "digit_literal_dec" || tok.getTokenClass() == "digit_literal_bin"
			|| tok.getTokenClass() == "digit_literal_hex" || tok.getTokenClass() == "digit_literal_oct" 
				|| tok.getTokenClass() == "symbol_literal");
}

bool checkArrayNameTok(Token tok)
{
	return (tok.getTokenClass() == "digit_literal_dec" || tok.getTokenClass() == "digit_literal_bin"
			|| tok.getTokenClass() == "digit_literal_hex" || tok.getTokenClass() == "digit_literal_oct"
				|| tok.getTokenClass() == "variable" || tok.getTokenClass() == "left_paren_]");
}


//Parse


bool checkParseDataType(Token tok)
{
	return (tok.getTokenClass() == "data_type_int" || tok.getTokenClass() == "data_type_char" 
			|| tok.getTokenClass() == "data_type_float" || tok.getTokenClass() == "data_type_void"
				|| tok.getTokenClass() == "data_type_double");
}

bool checkParsePointer(Token curr_tok, Token prev_tok)
{
	return ((prev_tok.getTokenClass() =="data_type_int"|| prev_tok.getTokenClass() == "data_type_char" 
					|| prev_tok.getTokenClass() == "data_type_float" || prev_tok.getTokenClass() == "data_type_double" 
						|| prev_tok.getTokenClass() == "key_word_const" || prev_tok.getTokenClass() == "arithmetic_operator_*")
							&& curr_tok.getTokenClass() == "arithmetic_operator_*");

}

bool checkParseCosnt(Token tok)
{
	return (tok.getTokenClass() == "key_word_const");
}

bool checkParseFunction(Token tok)
{
	return (tok.getTokenClass() == "function_name");
}

bool checkParseFuncArgs(Token curr_tok, Token prev_tok)
{
	return (curr_tok.getTokenClass() =="right_paren_{" && prev_tok.getTokenClass() == "function_name");

}

bool checkParseFuncBody(Token curr_tok, Token prev_tok)
{
	return (curr_tok.getTokenClass() =="right_paren_(" && prev_tok.getTokenClass() == "function_name");

}

bool checkParseIf(Token tok)
{
	return (tok.getTokenClass() == "key_word_if");
}


bool checkParseIfCondition(Token curr_tok, Token prev_tok)
{
	return (curr_tok.getTokenClass() == "right_paren_(" && prev_tok.getLexeme() == "if");
}

bool checkParseIfBody(Token curr_tok, Token prev_tok)
{
	return (curr_tok.getTokenClass() == "right_paren_{" && prev_tok.getLexeme() == "if");
}

bool checkParseElse(Token tok)
{
	return (tok.getTokenClass() == "key_word_else");
}


bool checkParseFor(Token tok)
{
	return (tok.getTokenClass() == "key_word_for");
}


bool checkParseForCond(Token curr_tok, Token prev_tok)
{
	return (curr_tok.getTokenClass() =="right_paren_(" && prev_tok.getTokenClass() == "key_word_for");

}

bool checkParseForBody(Token curr_tok, Token prev_tok)
{
	return (curr_tok.getTokenClass() =="right_paren_{" && prev_tok.getTokenClass() == "key_word_for");

}

bool checkParseWhile(Token tok)
{
	return (tok.getTokenClass() == "key_word_while");
}

bool checkParseWhileCond(Token curr_tok, Token prev_tok)
{
	return (curr_tok.getTokenClass() =="right_paren_(" && prev_tok.getTokenClass() == "key_word_while");

}

bool checkParseWhileBody(Token curr_tok, Token prev_tok)
{
	return (curr_tok.getTokenClass() =="right_paren_{" && prev_tok.getTokenClass() == "key_word_while");

}

bool checkParseArrayData(Token curr_tok, Token prev_tok)
{
	return (curr_tok.getTokenClass() =="right_paren_{" && prev_tok.getTokenClass() == "arithmetic_operator_=");

}

bool checkParseArrayName(Token tok)
{
	return (tok.getTokenClass() == "array_name");

}

bool checkParsePrintf(Token tok)
{
	return (tok.getTokenClass() == "std_function_printf");

}

bool checkParseReturn(Token tok)
{
	return (tok.getTokenClass() == "key_word_return");

}

bool checkParseStringLexeme(Token tok)
{
	return (tok.getTokenClass() == "string_literal");

}

bool checkParseSymbolLexeme(Token tok)
{
	return (tok.getTokenClass() == "symbol_literal");

}

bool checkParseDigitId(Token tok)
{
	return (tok.getTokenClass() == "digit_literal_dec" || tok.getTokenClass() == "digit_literal_bin"
			|| tok.getTokenClass() == "digit_literal_hex" || tok.getTokenClass() == "digit_literal_oct");
}

bool checkParseSymbolId(Token tok)
{
	return (tok.getTokenClass() == "variable");

}

bool checkParseBreak(Token tok)
{
	return (tok.getTokenClass() == "key_word_break");

}

bool checkParseAssignment(Token tok)
{
	return (tok.getTokenClass() == "arithmetic_operator_=");

}

bool checkParseLogicOperation(Token tok)
{
	return (tok.getTokenClass() == "logic_operator_&&" || tok.getTokenClass() == "logic_operator_||");
}

bool checkParseBinOperation(Token tok)
{
	return (tok.getTokenClass() == "arithmetic_operator_+" || tok.getTokenClass() == "arithmetic_operator_-"
			|| tok.getTokenClass() == "arithmetic_operator_*" || tok.getTokenClass() == "arithmetic_operator_/"
			 	|| tok.getTokenClass() == "compare_operator_==" || tok.getTokenClass() == "compare_operator_!=" 
			 		|| tok.getTokenClass() == "compare_operator_>=" || tok.getTokenClass() == "compare_operator_<="
			 			|| tok.getTokenClass() == "compare_operator_>"|| tok.getTokenClass() == "compare_operator_<" 
			 				|| tok.getTokenClass() == "spec_symbol_:" || tok.getTokenClass() == "arithmetic_operator_%");
}

bool checkParseUnaryOperation(Token tok)
{
	return (tok.getTokenClass() == "arithmetic_operator_++" || tok.getTokenClass() == "arithmetic_operator_--");
}

bool checkParseTernarOperation(Token tok)
{
	return (tok.getTokenClass() == "spec_symbol_?");

}


//errors


void CheckRightParenError(Token next_tok, Token curr_tok)
{
	if (next_tok.getLexeme() != "(" && next_tok.getLexeme() != "") {

		cout<<"Loc=<"<<next_tok.getLine()<<":"<<next_tok.getPos()<<"> ";
		cout<<"Expected '(' after '"<<curr_tok.getLexeme()<<"'"<<endl;
		
		exit(1);
	}
}

void CheckLeftParenError(Token tok)
{
	if (tok.getLexeme() == "{") {

		cout<<"Loc=<"<<tok.getLine()<<":"<<tok.getPos()<<"> ";
		cout<<"Expected ')' becouse '(' previously used"<<endl;
		
		exit(1);
	}
}


void checkRightBraceError(Token tok)
{
	if (tok.getLexeme() != "{" && tok.getLexeme() != "") {

		cout<<"Loc=<"<<tok.getLine()<<":"<<tok.getPos()<<"> ";
		cout<<"Expected '{' after  ')'"<<endl;
		
		exit(1); 
	}
}

void checkDataTypeNextTokError(Token next_tok, Token curr_tok)
{
	if (next_tok.getTokenClass() != "function_name" &&  next_tok.getTokenClass() != "variable" 
			&&  next_tok.getTokenClass() != "arithmetic_operator_*" &&  next_tok.getTokenClass() != "key_word_const"
				&&  next_tok.getTokenClass() != "array_name" &&  next_tok.getTokenClass() != "") 
	{
		cout<<"Loc=<"<<next_tok.getLine()<<":"<<next_tok.getPos()<<"> ";
		cout<<"Expected identificator after '"<<curr_tok.getLexeme()<<"'"<<endl;
		
		exit(1);
	}
}

void checkConstNextTokError(Token next_tok, Token curr_tok)
{
	if (next_tok.getTokenClass() != "data_type_int" && next_tok.getTokenClass() != "data_type_char" 
			&& next_tok.getTokenClass() != "data_type_float" && next_tok.getTokenClass() != "data_type_double" 
				&& next_tok.getTokenClass() != "variable" && next_tok.getTokenClass() != "arithmetic_operator_*" 
					&& next_tok.getTokenClass() != "array_name" &&  next_tok.getTokenClass() != "") 
	{
		cout<<"Loc=<"<<next_tok.getLine()<<":"<<next_tok.getPos()<<"> ";
		cout<<"Expected identificator after '"<<curr_tok.getLexeme()<<"'"<<endl;
		
		exit(1);
	}
}

void checkReturnNextTokError(Token next_tok, Token curr_tok)
{
	if (next_tok.getTokenClass() != "variable" && next_tok.getTokenClass() != "digit_literal_dec" 
			&& next_tok.getTokenClass() != "digit_literal_bin" && next_tok.getTokenClass() != "digit_literal_hex" 
				&& next_tok.getTokenClass() != "digit_literal_oct" && next_tok.getTokenClass() != "array_name" 
					&& next_tok.getTokenClass() != "")
	{
		cout<<"Loc=<"<<next_tok.getLine()<<":"<<next_tok.getPos()<<"> ";
		cout<<"Expected identificator after '"<<curr_tok.getLexeme()<<"'"<<endl;
		
		exit(1); 
	}
}

void checkSemicolonAndCommaError(Token curr_tok, Token prev_tok)
{
	if (prev_tok.getTokenClass() != "variable" && prev_tok.getTokenClass() != "digit_literal_oct"
		&& prev_tok.getTokenClass() != "digit_literal_hex" && prev_tok.getTokenClass() != "digit_literal_bin"
			&& prev_tok.getTokenClass() != "digit_literal_dec" && prev_tok.getTokenClass() != "data_type_int" 
				&& prev_tok.getTokenClass() != "data_type_char" && prev_tok.getTokenClass() != "data_type_float"
					&& prev_tok.getTokenClass() != "data_type_double" && prev_tok.getTokenClass() != "key_word_return"
						&& prev_tok.getTokenClass() != "arithmetic_operator_++" && prev_tok.getTokenClass() != "arithmetic_operator_+")

		return;

	if (curr_tok.getLexeme() != "," && curr_tok.getLexeme() != ";" && curr_tok.getLexeme() != "(" 
		&& curr_tok.getLexeme() != ")" && curr_tok.getLexeme() != "=" && curr_tok.getLexeme() != "=="
		 && curr_tok.getLexeme() != "<" && curr_tok.getLexeme() != ">"  && curr_tok.getLexeme() != ">="
		 	&& curr_tok.getLexeme() != "<=" && curr_tok.getLexeme() != "++" && curr_tok.getLexeme() != "--"
		 		&& curr_tok.getLexeme() != "+" && curr_tok.getLexeme() != "-" && curr_tok.getLexeme() != "/" 
		 			&& curr_tok.getLexeme() != "*" && curr_tok.getLexeme() != "")
	{
		cout<<"Loc=<"<<prev_tok.getLine()<<":"<<prev_tok.getPos()<<"> ";
		cout<<"expected ',' or ';' after identidicator"<<endl;
		
		exit(1);
	}

}

void checkEndOfOperatorError(Token curr_tok, Token next_tok)
{
	if (next_tok.getLexeme() != ";")
	{
		cout<<"Loc=<"<<curr_tok.getLine()<<":"<<curr_tok.getPos()<<"> ";
		cout<<"expected ';' after '"<<curr_tok.getLexeme()<<"'"<<endl;
		
		exit(1);
	}
}
