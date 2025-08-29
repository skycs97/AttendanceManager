#include "gmock/gmock.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "attendees_data.h"
#include "attendance_file_reader.h"

#include "constants.h"

using namespace std;

map<string, int> idFromName;
map<int, Attendees> attendeesInfo;

int id_cnt = 0;

int getWeekDayIdxFromString(string weekday) {
	for (int weekday_idx = 0; weekday_idx < NUM_WEEKDAY; ++weekday_idx) {
		if (weekday == WEEKDAY_STRING[weekday_idx]) {
			return weekday_idx;
		}
	}

	return -1;
}

bool isExistAttendees(string name) {
	return (idFromName.count(name) != 0);
}

void checkAndAddAttendeesInfo(string name, string weekday) {
	if (isExistAttendees(name) == false) {
		int id = ++id_cnt;
		idFromName.insert({ name, id });
		attendeesInfo.insert({ id, Attendees {id, name} });
	}
}

void addAttendanceWeekday(string name, string weekday) {
	int weekday_idx = getWeekDayIdxFromString(weekday);

	if (weekday_idx == -1) {
		return;
	}

	auto& attendees = attendeesInfo[idFromName[name]];

	attendees.attendEachWeekDay[weekday_idx] += 1;
}

void makeAllAttendeesInfo(const vector<Attendance>& attendanceList) {
	for (auto& attendance : attendanceList) {
		checkAndAddAttendeesInfo(attendance.name, attendance.weekday);
		addAttendanceWeekday(attendance.name, attendance.weekday);
	}
}

void calWeekDayScore(Attendees& attendees) {
	for (int i = 0; i < NUM_WEEKDAY; ++i) {
		attendees.point += (attendees.attendEachWeekDay[i] * SCORE_WEEKDAY[i]);
	}
}

bool checkWednesDayAttendanceMore10(const Attendees& attendees) {
	return (attendees.attendEachWeekDay[WEDNESDAY] >= 10);
}
bool checkWeekendAttendanceMore10(const Attendees& attendees) {
	int numAttendanceWeekend = attendees.attendEachWeekDay[SATURDAY] + attendees.attendEachWeekDay[SUNDAY];
	return (numAttendanceWeekend >= 10);
}

void calAttendanceScore() {
	for (int id = 1; id <= id_cnt; ++id) {
		auto& attendees = attendeesInfo[id];

		calWeekDayScore(attendees);

		if (checkWednesDayAttendanceMore10(attendees)) {
			attendees.point += BONUS_SCORE_MORE_THAN_10_ATTANDANCE;
		}

		if (checkWeekendAttendanceMore10(attendees)) {
			attendees.point += BONUS_SCORE_MORE_THAN_10_ATTANDANCE;
		}
	}
}

GRADE getGrade(int point) {
	if (point >= GRADE_MINIMUM_SCORE[GOLD]) {
		return GOLD;
	}
	else if (point >= GRADE_MINIMUM_SCORE[SILVER]) {
		return SILVER;
	}

	return NORMAL;
}

void makeGradeAllAttendees() {
	for (int id = 1; id <= id_cnt; ++id) {
		auto& attendees = attendeesInfo[id];

		attendees.grade = getGrade(attendees.point);
	}
}

void printAttendeesInfo(const Attendees& attendees) {
	cout << "NAME : " << attendees.name << ", ";
	cout << "POINT : " << attendees.point << ", ";
	cout << "GRADE : " << GRADE_STRING[attendees.grade] << "\n";
}

bool isRemovePlayer(const Attendees& attendees) {
	if (attendees.grade == NORMAL
		&& attendees.attendEachWeekDay[WEDNESDAY] == 0
		&& attendees.attendEachWeekDay[SATURDAY] == 0
		&& attendees.attendEachWeekDay[SUNDAY] == 0){
		return true;
	}

	return false;
}

void printRemovePlayer() {
	std::cout << "\n";
	std::cout << "Removed player\n";
	std::cout << "==============\n";
	for (int i = 1; i <= id_cnt; i++) {
		auto& attendees = attendeesInfo[i];

		if (isRemovePlayer(attendees)){
			std::cout << attendees.name << "\n";

		}
	}
}

void printAllAttendeesInfo() {
	for (int id = 1; id <= id_cnt; ++id) {
		auto& attendees = attendeesInfo[id];

		printAttendeesInfo(attendees);
	}

	printRemovePlayer();
}

void runAttendanceManager() {
	auto attendanceList = readAttendanceListFromFile(ATTENDANCE_LIST_FILE_PATH);

	attendeesInfo.clear();
	makeAllAttendeesInfo(attendanceList);

	calAttendanceScore();
	makeGradeAllAttendees();

	printAllAttendeesInfo();
}

int main() {
#if defined(_DEBUG)
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
#else
	runAttendanceManager();

	return 0;
#endif
}