#pragma once
#include <string>

using namespace std;

const string ATTENDANCE_LIST_FILE_PATH = "attendance_weekday_500.txt";
const int NUM_LINE_ATTENDANCE = 500;

const int NUM_DAY_OF_WEEK = 7;

const int SCORE_WEEKDAY[NUM_DAY_OF_WEEK] =
{
	1,1,3,1,1,2,2
};

const int BONUS_SCORE_MORE_THAN_10_ATTANDANCE = 10;

const enum DayOfWeek {
	MONDAY = 0,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

extern const string DAY_OF_WEEK_STRING[NUM_DAY_OF_WEEK];