#include "grade.h"

const string GRADE_STRING[NUM_GRADE] =
{
	"NORMAL",
	"SILVER",
	"GOLD"
};

const int GRADE_MINIMUM_SCORE[NUM_GRADE] = {
	0,
	30,
	50,
};

int Grade::getGradeLevel()
{
	return gradeLevel;
}

string Grade::getGradeName()
{
	return gradeName;
}

Grade::Grade(const string& gradeName, int gradeLevel)
	: gradeName(gradeName), gradeLevel(gradeLevel)
{
}


GradeGenerator& GradeGenerator::getInstance()
{
	static GradeGenerator gradeGenerator;
	return gradeGenerator;
}

std::shared_ptr<Grade> GradeGenerator::makeGrade(int point)
{
	int grade = 0;
	for (grade = NUM_GRADE - 1; grade >= 0; --grade) {
		if (point >= GRADE_MINIMUM_SCORE[grade]) {
			break;
		}
	}

	return std::make_shared<Grade>(GRADE_STRING[grade], grade);
}
