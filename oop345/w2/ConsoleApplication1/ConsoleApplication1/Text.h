#pragma once
#ifndef W2_TEXT_H
#define W2_TEXT_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;
namespace w3 {


	class Text {

		string* text;
		int fldsize;

	public:
		Text();
		Text(const string fileName);

		//copy constructor and operator
		Text(const Text& copy);
		Text& operator=(const Text& copy);

		//move constructor and operator
		Text(Text&& copy);
		Text&& operator=(Text&& copy);

		//deconstructor
		~Text();

		//size function
		size_t size() const;




	};


























}
#endif // !W2_TEXT_H
