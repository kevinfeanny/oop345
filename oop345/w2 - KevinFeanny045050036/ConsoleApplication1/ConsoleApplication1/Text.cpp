#include "Text.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

namespace w3 {


	Text::Text() {

		text = nullptr;
		fldsize = 0;

	}

	Text::Text(const string fileName) : fldsize(0)
	{

		std::ifstream f(fileName, std::ifstream::in);
		

		if (f.is_open())
		{
			int count = 0;
			string line;

			do
			{
				getline(f, line, '\n');
				count++;

			} while (!f.fail());

			f.clear();
			f.seekg(0, ios::beg);
			text = new string[count];


			for (int i = 0; !f.fail(); i++) {
				getline(f, text[i], '\n');
			}
			fldsize = count;
			f.close();

		}
		else {
			Text();


		}

		

	}
	Text::Text(const Text& copy) {

		fldsize = 0;
		text = nullptr;
		*this = copy;

	}
	Text& Text::operator=(const Text& copy) {

		if (this != &copy)
		{
			if (text) {

				delete[] text;
				text = nullptr;
				fldsize = 0;

			}
			if (copy.text)
			{
				fldsize = copy.fldsize;
				text = new string[fldsize];

				for (size_t i = 0; i < fldsize; i++) {
					text[i] = copy.text[i];


				}




			}





		}
		return *this;

	}
	Text::Text(Text&& copy)
	{
		fldsize = 0;
		text = nullptr;
		*this = move(copy);

	}
	Text&& Text::operator=(Text&& copy) {

		if (this != &copy) {

			if (text) {
				delete[] text;
				text = nullptr;
				fldsize = 0;


			}

			if (copy.text) {

				fldsize = copy.fldsize;
				text = copy.text;
				copy.fldsize = 0;
				copy.text = nullptr;


			}



		}

		return move(*this);

	}
	Text::~Text() {

		delete[] text;
		text = nullptr;

	}

	size_t Text::size() const {


		return fldsize;


	}




}
