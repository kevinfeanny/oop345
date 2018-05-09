

#include <iostream>
#include <string>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include "Utilities.h"

using namespace std;

	char Utilities::delimiter;
	ofstream Utilities::logFile;
	//constructor to set fieldwidth to 1
	Utilities::Utilities() {
		
		field_width = 1;
	}
	//return fieldwidth function
	size_t Utilities::getFieldWidth() const {
	
		return this->field_width;
	}
	//constuctor function to read from file up to deliminator or new line
	const string Utilities::nextToken(const string& str, size_t& next_pos, bool& more) {
	
		string token = str.substr(next_pos);

		size_t delimiter_pos = token.find(delimiter);
		token = delimiter_pos == string::npos ?
			token.substr(0, token.find_first_of("\r\n")) : 
			token.substr(0, delimiter_pos);                

		if (field_width < token.size()) field_width = token.size();

		next_pos += token.size() + 1;
		more = (next_pos < str.size() - 1); 

		size_t token_pos;
	
		while ((token_pos = token.size() - 1) != string::npos) {
			if (isspace(token.at(token_pos))) token.erase(token_pos);
			else break;
		}
		
		while (token.size() > 0) {
			if (isspace(token.at(0))) token.erase(0, 1);
			else break;
		}

		return token;
	}
	//set deliminastor function
	void Utilities::setDelimiter(const char pDelim) {
		
		Utilities::delimiter = pDelim;
	}
	//set log file function
	void Utilities::setLogFile(const char* logfile) {
		
		logFile.close();
		logFile.open(logfile);
	}
	//return log file function
	std::ofstream& Utilities::getLogFile() {
		
		return logFile;
	}




