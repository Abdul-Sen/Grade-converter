// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include <fstream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

	std::ofstream ofs("Lab5Output.txt");

	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}
	try {
		Grades grades(argv[1]);

		auto letter = [](double ui_numGrade) {
			std::string temp;
			if (ui_numGrade >= Ap)
				temp = enumToStr(Letter::Ap);
			else if (ui_numGrade >= A)
				temp = enumToStr(Letter::A);
			else if (ui_numGrade >= Bp)
				temp = enumToStr(Letter::Bp);
			else if (ui_numGrade >= B)
				temp = enumToStr(Letter::B);
			else if (ui_numGrade >= Cp)
				temp = enumToStr(Letter::Cp);
			else if (ui_numGrade >= C)
				temp = enumToStr(Letter::C);
			else if (ui_numGrade >= Dp)
				temp = enumToStr(Letter::Dp);
			else if (ui_numGrade >= D)
				temp = enumToStr(Letter::D);
			else
				temp = enumToStr(Letter::F);
			return temp;
		};

		//Update the main functions as per the specifications here
		grades.displayGrades(ofs, letter);

	}
	catch (std::string err)
	{
		throw err;
	}
	catch (...)
	{
		throw "OOPS! Something went wrong!";
	}

	ofs.close();
}