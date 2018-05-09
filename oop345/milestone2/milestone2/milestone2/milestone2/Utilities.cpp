
#include <iostream>
#include <string>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include "Utilities.h"


	char Utilities::delimiter;
	std::ofstream Utilities::logFile;
	//set utilities to safe state
	Utilities::Utilities() {
		field_width = 1;
	}
	//return field width
	size_t Utilities::getFieldWidth() const {
		return this->field_width;
	}
	//read from file until dilimiter or end of line
	const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& more) {
		std::string token = "";

		while (str.size() != next_pos && str[next_pos] != delimiter) {
			token += str[next_pos];
			next_pos++;
		}

		if (str.size() == next_pos) {
			more = false;
		}
		else {
			more = true;
			next_pos++;
		}

		size_t p = token.find_first_not_of(" \t\r\n");
		token.erase(0, p);

		p = token.find_last_not_of(" \t\r\n");
		if (std::string::npos != p) {
			token.erase(p + 1);
		}

		if (field_width < token.size()) {
			field_width = token.size();
		}

		return token;
	}
	//set delimiter
	void Utilities::setDelimiter(const char pDelim) {
		Utilities::delimiter = pDelim;
	}
	//set logfile
	void Utilities::setLogFile(const char* logfile) {
		logFile.close();
		logFile.open(logfile);
	}
	//return logfile
	std::ofstream& Utilities::getLogFile() {
		return logFile;
	}




