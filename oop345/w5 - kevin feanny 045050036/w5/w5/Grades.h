#ifndef  GRADES_H
#define GRADES_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Grades {
				
	string* studentno;
	double* mark;
	int count;
public:
	//constructor for safestate
	Grades() :studentno(nullptr), mark(nullptr), count(0) {}
	//constructor when passed a filename
	Grades(char* fileName) {
		try {
			ifstream f(fileName);
			if (!f) {
				throw "File cannot be opened";

			}
			if (f.is_open()) {
				string temp;
				int tmpcnt = 0;

				while (getline(f, temp)) {
					tmpcnt++;

				}
				f.clear();
				f.seekg(0);
				count = tmpcnt;
				studentno = new string[count];
				mark = new double[count];
				for (int i = 0; i < count; i++) {
					f >> studentno[i];
					f >> mark[i];


				}
				f.close();


			}


		}
		catch (ifstream::failure f1) {
			cerr << "File cannot be opened";
		}
	}
	//display using a template function we will pass it the lambda function in  main
	template<typename Func>
	void displayGrades(ostream& os, Func func) const {
		for (int i = 0; i < count; i++) {
			os << studentno[i] << " " << mark[i] << " " << func(mark[i]) << endl;

		}



	}





};





#endif

