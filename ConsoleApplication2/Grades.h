#pragma once
#include <string>

	class Grades {
		std::string* studentID;
		double* NumberGrade;
		int size;
	public:
		Grades(const Grades&) = delete;//cpy constructor
		Grades& operator=(const Grades&) = delete; //cpy assign
		Grades(Grades&& src) = delete; //move const
		Grades& operator=(Grades&& src) = delete;
		~Grades();
		Grades(const char* fileName);

		template<typename F>
		void displayGrades(std::ostream& os, F myLambdaFunc) const
		{
			for (int i = 0; i < this->size; i++)
			{
				os << this->studentID[i] << this->NumberGrade[i] << ' ' << myLambdaFunc(this->NumberGrade[i]) << std::endl;
			}
		}
		};