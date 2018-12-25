#include <fstream>
#include "Grades.h"

Grades::Grades(const char * fileName)
{
	this->size = 0;
	std::fstream file(fileName);

	std::string temp1;
	if (file.is_open())
	{
		while (file.good() && !file.eof())//finding size
		{
			std::getline(file, temp1, '\n');
			size++;
		}
		studentID = new std::string[size];
		NumberGrade = new double[size];

		file.clear();// clears eof state
		file.seekg(0);//moves file ptr to start of file

		int i = 0;
		temp1 = "";
		int index = 0;
		//copying data to strings
		while (file.good() && !file.eof()) //Getting student ID and Grade
		{
			std::getline(file, temp1, '\n');
			index = temp1.find(' ') +1;
			studentID[i] = temp1.substr(0, index);
			temp1 = temp1.substr(index, temp1.length());
			NumberGrade[i] = std::stof(temp1);
			i++;
		}
	}
	else {
		throw "Could ot open file!";
	}

}

Grades::~Grades()
{
	delete[] this->NumberGrade;
	delete[] this->studentID;
}
