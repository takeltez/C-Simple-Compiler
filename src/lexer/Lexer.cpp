#include "Lexer.h"

string root_path_to_file = "resources/";

string file_name[] = {"keyWords.txt", "stdHeaders.txt", "stdFuncs.txt", "parens.txt", "specSymbols.txt", 
						"dataTypes.txt","compOps.txt", "logicOps.txt", "arithOps.txt"};
						
string symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_1234567890";

string unaccept_symbols = "@$^\\№АаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщЪъЫыЬьЭэЮюЯя";

string path;

Lexer::Lexer() 
{ 
	string str;

	for(int i = 0; i < CountOfFiles; ++i){

		ifstream file (root_path_to_file + file_name[i]);
		
		while (getline(file, str)) 
			stdLexemesVec[i].push_back(str);
		
		file.close();
		str.clear();
	}
}

void Lexer::makeSpaces() 
{ 
    bool is_str = false;
    new_file_string = ' ' + new_file_string;

    for (int i  = 0; i < new_file_string.length(); i++) {

        if (new_file_string[i] == '\"')
            is_str = ((is_str) ? false : true);

        if ((new_file_string[i] == '/') && (new_file_string[i + 1] == '/')) 
	        break;
        
        for (int j  = 0; j < shrinked_lexemes.size(); j++) {
           
            if ((new_file_string.substr(i, shrinked_lexemes[j].length()) == shrinked_lexemes[j]) && !is_str && new_file_string[i - 1] != ' ') {
                new_file_string.replace(i, shrinked_lexemes[j].length(), ' ' + shrinked_lexemes[j] + ' ');
                i += shrinked_lexemes[j].length();
                break;
            }
            if ((new_file_string.substr(i, shrinked_lexemes[j].length()) == shrinked_lexemes[j]) && !is_str && new_file_string[i - 1] == ' ') {
                new_file_string.replace(i, shrinked_lexemes[j].length(), shrinked_lexemes[j] + ' ');
                i += shrinked_lexemes[j].length();
                break;
            }
        }
    }
}

string Lexer::shrinkLexemeFromString (int *start_pos) 
{ 
	int end_pos = new_file_string.find(" ", *start_pos + 1); 

	string lexeme = new_file_string.substr(*start_pos + 1, (end_pos - *start_pos - 1)); 

	*start_pos = new_file_string.find(" ", end_pos); 	

	return lexeme;
}

string Lexer::findStringLexeme(int newLineCount, string *lexeme, int *lexeme_pos) 
{ 
	int start_pos = new_file_string.find('"');
	int end_pos; 

	if (start_pos != string::npos) { 

		end_pos = new_file_string.find('"', start_pos + 1);

		if (end_pos == string::npos) {	
			*lexeme = new_file_string.substr(start_pos);
			*lexeme_pos = file_string.find(*lexeme) + 1;

			file_string.replace(file_string.find(*lexeme), (*lexeme).length(), (*lexeme).length(), ' ');
			new_file_string.replace(new_file_string.find(*lexeme), (*lexeme).length(), (*lexeme).length(), ' ');
			return "unknown";
		}

		else { 
			*lexeme = new_file_string.substr(start_pos, (end_pos - start_pos + 1));
			*lexeme_pos = file_string.find(*lexeme) + 1;

			file_string.replace(file_string.find(*lexeme), (*lexeme).length(), (*lexeme).length(), ' ');
			new_file_string.replace(new_file_string.find(*lexeme), (*lexeme).length(), (*lexeme).length(), ' ');
			return "string_literal";
		}
	}

	return NOLEXEME;
}

string Lexer::findSymbolLexeme(int newLineCount, string *lexeme, int *lexeme_pos) 
{ 
	int start_pos = new_file_string.find('\''); 
	int end_pos;

	if (start_pos != string::npos) { 

		end_pos = new_file_string.find('\'', start_pos + 1);

		if (end_pos == string::npos) { 
			*lexeme = new_file_string.substr(start_pos);
			*lexeme_pos = file_string.find(*lexeme) + 1;

			file_string.replace(file_string.find(*lexeme), (*lexeme).length(), (*lexeme).length(), ' ');
			new_file_string.replace(new_file_string.find(*lexeme), (*lexeme).length(), (*lexeme).length(), ' ');
			return "unknown";
		}

		else if ((end_pos - start_pos) != 2) { 

			*lexeme = new_file_string.substr(start_pos, (end_pos - start_pos) + 1);

			file_string.replace(file_string.find(*lexeme), (*lexeme).length(), (*lexeme).length(), ' ');
			new_file_string.replace(new_file_string.find(*lexeme), (*lexeme).length(), (*lexeme).length(), ' ');
			return "not_symbol_length";
		}

		else { 

			file_string.replace(file_string.find(*lexeme), (*lexeme).length(), (*lexeme).length(), ' ');
			new_file_string.replace(new_file_string.find(*lexeme), (*lexeme).length(), (*lexeme).length(), ' ');
			return "symbol_literal";
		}
	}

	return NOLEXEME;
}

void Lexer::delSimpleComment() 
{ 
	string lexeme;
	int start_pos = new_file_string.find("//"); 

	if (start_pos != string::npos) { 

		lexeme = new_file_string.substr(start_pos);

		file_string.replace(file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
		new_file_string.replace(new_file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
	}
}

string Lexer::findStandartLexeme(int newLineCount, string lexeme, int *lexeme_pos) 
{ 
	for (int i = 0; i < CountOfFiles; ++i) { 

		for (auto it = stdLexemesVec[i].begin(); it != stdLexemesVec[i].end(); ++it) { 

			int pos = lexeme.find(*it);

			if (pos != string::npos) { 

				*lexeme_pos = file_string.find(*it) + 1;	
				string tokenClass = checkStdLexemes(lexeme);

				file_string.replace(file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
				new_file_string.replace(new_file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
				return tokenClass;
			}
		}
    }
    return NOLEXEME;
}

string Lexer::findDigitLexeme(int newLineCount, string lexeme, int *lexeme_pos) 
{ 
	int start_pos = lexeme.find_first_of(symbols); 

	if (start_pos != string::npos) { 

		if (regex_search(lexeme.begin(), lexeme.end(), REGULAR_HEX)) { 	
			*lexeme_pos = file_string.find(lexeme) + 1;				
			
			file_string.replace(file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			new_file_string.replace(new_file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			return "digit_literal_hex";
		}

		else if (regex_search(lexeme.begin(), lexeme.end(), REGULAR_BIN)) { 
			*lexeme_pos = file_string.find(lexeme) + 1;				
		
			file_string.replace(file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			new_file_string.replace(new_file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			return "digit_literal_bin";
		}

			
		else if (regex_search(lexeme.begin(), lexeme.end(), REGULAR_OCT)) { 
			*lexeme_pos = file_string.find(lexeme) + 1;

			file_string.replace(file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			new_file_string.replace(new_file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			return "digit_literal_oct";
		}

		else if (regex_search(lexeme.begin(), lexeme.end(), REGULAR_DEC) || lexeme == "0") { 
			*lexeme_pos = file_string.find(lexeme) + 1;

			file_string.replace(file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			new_file_string.replace(new_file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			return "digit_literal_dec";
		}
	}

	return NOLEXEME;
}

string Lexer::findVariables(int newLineCount, string lexeme, int *lexeme_pos, int start_pos_next_lexeme) 
{ 
	string next_lexeme;
	int start_pos = lexeme.find_first_of(symbols); 

	if (start_pos != string::npos) { 

		while(next_lexeme == "") 
			 next_lexeme = shrinkLexemeFromString(&start_pos_next_lexeme);

		if (isdigit(lexeme[0])) { 
			*lexeme_pos = file_string.find(lexeme) + 1;

			file_string.replace(file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			new_file_string.replace(new_file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			return "unknown";
		}

		else if (next_lexeme == "[") {
			*lexeme_pos = file_string.find(lexeme) + 1;

			file_string.replace(file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			new_file_string.replace(new_file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			return "array_name";
		}

		else if (next_lexeme == "(") {
			*lexeme_pos = file_string.find(lexeme) + 1;

			file_string.replace(file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			new_file_string.replace(new_file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			return "function_name";
		}

		else if (regex_search(lexeme.begin(), lexeme.end(), REGULAR_VARS)) {
			*lexeme_pos = file_string.find(lexeme) + 1;

			file_string.replace(file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			new_file_string.replace(new_file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
			return "variable";
		}
	}	

	return NOLEXEME;
}

string Lexer::findUnacceptSymbols(int newLineCount, string lexeme, int *lexeme_pos) 
{ 
	int start_pos = lexeme.find_first_of(unaccept_symbols); 

	if (start_pos != string::npos) {
		*lexeme_pos = file_string.find(lexeme) + 1;

		file_string.replace(file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
		new_file_string.replace(new_file_string.find(lexeme), lexeme.length(), lexeme.length(), ' ');
		return "unacceptable_symbol";
	}

	return NOLEXEME;
}

Token Lexer::getNextToken() 
{ 
	int lexeme_pos = 0;
	string lexeme;
	string tokenClass;
	Token token;

	if (new_file_string.find_first_not_of(" 	") == string::npos) { 

		ifstream file (path);
		file_pos += file_string.length() + 1;

		file.seekg(file_pos);
		getline(file, file_string);

		new_file_string = file_string;
		
		makeSpaces(); 
		start_pos = 0;

		if (file.eof() && new_file_string.find_first_not_of(" ") == string::npos) 
			e_o_f = true;

		++newLineCount;	
		file.close();
	}

	lexeme = shrinkLexemeFromString(&start_pos); 

	if (lexeme[0] == '/' && lexeme[1] == '/') { 
		delSimpleComment();
		return token;
	}

	if (lexeme[0] == '\"') { 

		tokenClass = findStringLexeme(newLineCount, &lexeme, &lexeme_pos);

		if (tokenClass != NOLEXEME) { 
			Token token(tokenClass, lexeme, newLineCount, lexeme_pos);
			return token;
		}
	}

	if (lexeme[0] == '\'') { 

		tokenClass = findSymbolLexeme(newLineCount, &lexeme, &lexeme_pos);

		if (tokenClass != NOLEXEME) {
			Token token(tokenClass, lexeme, newLineCount, lexeme_pos);
			return token; 
		}
	}

	tokenClass = findStandartLexeme(newLineCount, lexeme, &lexeme_pos);

	if (tokenClass != NOLEXEME) {
		Token token(tokenClass, lexeme, newLineCount, lexeme_pos);
		return token;
	}

	tokenClass = findDigitLexeme(newLineCount, lexeme, &lexeme_pos);

	if (tokenClass!= NOLEXEME) {
		Token token(tokenClass, lexeme, newLineCount, lexeme_pos);
		return token;
	}

	tokenClass = findVariables(newLineCount, lexeme, &lexeme_pos, start_pos);

	if (tokenClass != NOLEXEME) {
		Token token(tokenClass, lexeme, newLineCount, lexeme_pos);
		return token;
	}

	tokenClass = findUnacceptSymbols(newLineCount, lexeme, &lexeme_pos);
   
	if (tokenClass != NOLEXEME) {
		Token token(tokenClass, lexeme, newLineCount, lexeme_pos);
		return token;
	}

	if (e_o_f) { 
		token.setLexeme(" ");
		return token;
	}

   	return token;
}

void Lexer::setStartFileString(string file_path) 
{
	path = file_path;

	ifstream file (path);

	getline(file, file_string);

	new_file_string = file_string;
	makeSpaces();

	file.close();
}