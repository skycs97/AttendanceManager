#pragma once

#include <string>
#include "config.h"
#include "grade.h"

using std::string;

class Attendees {
public:
	bool isRemovePlayer();

	void attend(DayOfWeek dayOfWeek);
	void calPoint();
	void setGrade(std::shared_ptr<Grade> grade);

	string getName();
	int getPoint();
	std::shared_ptr<Grade> getGrade();
	Attendees(int id, const string& name);
private:
	int id;
	string name;
	int attendEachDayOfWeek[NUM_DAY_OF_WEEK];
	int point;
	std::shared_ptr<Grade> grade;

	int calDayOfWeekScore();
	bool checkWednesDayBonus();
	bool checkWeekendBonus();
};