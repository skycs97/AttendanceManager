#include "attendees.h"
#include "config.h"

bool Attendees::isRemovePlayer()
{
	if (grade->getGradeLevel() == NORMAL
		&& attendEachDayOfWeek[WEDNESDAY] == 0
		&& attendEachDayOfWeek[SATURDAY] == 0
		&& attendEachDayOfWeek[SUNDAY] == 0) {
		return true;
	}

	return false;
}

void Attendees::attend(DayOfWeek dayOfWeek)
{
	attendEachDayOfWeek[dayOfWeek]++;
}

int Attendees::calDayOfWeekScore()
{
	int point = 0;
	for (int w = 0; w < NUM_DAY_OF_WEEK; ++w) {
		point += (attendEachDayOfWeek[w] * SCORE_WEEKDAY[w]);
	}

	return point;
}

bool Attendees::checkWednesDayBonus()
{
	return (attendEachDayOfWeek[WEDNESDAY] >= 10);
}

bool Attendees::checkWeekendBonus()
{
	int numAttendanceWeekend = attendEachDayOfWeek[SATURDAY] + attendEachDayOfWeek[SUNDAY];
	return (numAttendanceWeekend >= 10);
}

void Attendees::calPoint()
{
	point = 0;
	point += calDayOfWeekScore();
	
	if (checkWednesDayBonus()) {
		point += BONUS_SCORE_MORE_THAN_10_ATTANDANCE;
	}

	if (checkWeekendBonus()) {
		point += BONUS_SCORE_MORE_THAN_10_ATTANDANCE;
	}
}

void Attendees::setGrade(std::shared_ptr<Grade> grade)
{
	this->grade = grade;
}

string Attendees::getName()
{
	return name;
}

int Attendees::getPoint()
{
	return point;
}

std::shared_ptr<Grade> Attendees::getGrade()
{
	return grade;
}

Attendees::Attendees(int id, const string& name)
	: id(id), name(name), point(0), grade(0)
{
	for (int i = 0; i < 7; ++i) {
		attendEachDayOfWeek[i] = 0;
	}
}

