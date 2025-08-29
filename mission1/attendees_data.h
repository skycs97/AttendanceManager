#pragma once
#include <string>
#include <vector>
using namespace std;

enum GRADE {
	NORMAL = 0,
	SILVER,
	GOLD,
	NUM_GRADE
};

string GRADE_STRING[NUM_GRADE] =
{
	"NORMAL",
	"SILVER",
	"GOLD",
};

int GRADE_MINIMUM_SCORE[NUM_GRADE] = {
	0,
	30,
	50,
};

struct Attendees {
	int id;
	string name;	
	int attendEachWeekDay[7];
	int point;
	int grade;

	Attendees(int id, const string& name)
		: id(id), name(name), point(0), grade(0)
	{
		for (int i = 0; i < 7; ++i) {
			attendEachWeekDay[i] = 0;
		}
	}

	Attendees() = default;
};