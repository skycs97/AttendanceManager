#include "attendance_file_reader.h"
#include <fstream>

vector<Attendance> readAttendanceListFromFile(string filePath) {
	vector<Attendance> attendanceList;

	ifstream fin{ filePath };
	for (int i = 0; i < ATTENDANCE_LIST_LINE_NUM; i++) {
		string name, weekday;
		fin >> name >> weekday;

		attendanceList.emplace_back(name, weekday);
	}

	return attendanceList;
}