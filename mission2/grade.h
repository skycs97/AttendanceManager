#pragma once
#include <string>
#include <memory>
using std::string;

enum GRADE {
	NORMAL = 0,
	SILVER,
	GOLD,
	NUM_GRADE
};

class Grade {
public:
	int getGradeLevel();
	string getGradeName();
	Grade(const string& gradeName, int gradeLevel);
private:
	string gradeName;
	int gradeLevel;
};

class GradeGenerator {
public:
	static GradeGenerator& getInstance();

	std::shared_ptr<Grade> makeGrade(int point);
private:
	GradeGenerator() {};
	GradeGenerator(const GradeGenerator& ref) = delete;
	GradeGenerator& operator=(const GradeGenerator& ref) = delete;
};