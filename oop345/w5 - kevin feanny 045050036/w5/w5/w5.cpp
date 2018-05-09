// Kevin Feanny 045 050 036
// w5.cpp

#include <iostream>
#include "Grades.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] <<
			": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}


	Grades grades(argv[1]);
	// define the lambda expression for letter
	auto letter = [](double mark)->string {
		string grade;
		if (mark >= 90) {
			grade = "A+";
		}
		else if (mark > 80 && mark < 90) {
			grade = "A";
		}
		else if (mark > 75 && mark < 80) {
			grade = "B+";
		}
		else if (mark > 70 & mark < 75) {
			grade = "B";
		}
		else if (mark > 65 && mark < 70) {
			grade = "C+";
		}
		else if (mark > 60 && mark < 65) {
			grade = "C";
		}
		else if (mark > 55 && mark < 60) {
			grade = "D+";
		}
		else if (mark > 50 && mark < 55) {
			grade = "D";
		}
		else {
			grade = "F";

		}


		return grade;


		
	};




	grades.displayGrades(std::cout, letter);




	std::cout << "Press any key to continue ... ";
	std::cin.get();
}