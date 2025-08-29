#pragma once
#include <string>
#include <map>
using namespace std;

const string ATTENDANCE_LIST_FILE_PATH = "attendance_weekday_500.txt";

const int NUM_WEEKDAY = 7;

const int SCORE_WEEKDAY[NUM_WEEKDAY] =
{
	1,1,3,1,1,2,2
};

const int BONUS_SCORE_MORE_THAN_10_ATTANDANCE = 10;

enum WEEKDAY {
	MONDAY = 0,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

string WEEKDAY_STRING[NUM_WEEKDAY] = {
	"monday",
	"tuesday",
	"wednesday",
	"thursday",
	"friday",
	"saturday",
	"sunday"
};