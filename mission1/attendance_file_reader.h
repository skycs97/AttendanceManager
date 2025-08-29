#pragma once
#include <vector>
#include <string>

using namespace std;

const static int ATTENDANCE_LIST_LINE_NUM = 500;

struct Attendance {
	string name;
	string weekday;

	Attendance(const string& name, const string& weekday)
		: name(name), weekday(weekday)
	{
	}
};

vector<Attendance> readAttendanceListFromFile(string filePath);
