#include "gmock/gmock.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "attendance_file_reader.h"

using namespace std;

const static string ATTENDANCE_LIST_FILE_PATH = "attendance_weekday_500.txt";

map<string, int> id1;
int id_cnt = 0;

//dat[사용자ID][요일]
int dat[100][100];
int points[100];
int grade[100];
string names[100];

int wed[100];
int weeken[100];

void calAttendanceScore(string w, string wk) {
	//ID 부여
	if (id1.count(w) == 0) {
		id1.insert({ w, ++id_cnt });

		if (w == "Daisy") {
			int debug = 1;
		}

		names[id_cnt] = w;
	}
	int id2 = id1[w];

	//디버깅용
	if (w == "Daisy") {
		int debug = 1;
	}


	int add_point = 0;
	int index = 0;
	if (wk == "monday") {
		index = 0;
		add_point++;
	}
	if (wk == "tuesday") {
		index = 1;
		add_point++;
	}
	if (wk == "wednesday") {
		index = 2;
		add_point += 3;
		wed[id2] += 1;
	}
	if (wk == "thursday") {
		index = 3;
		add_point++;
	}
	if (wk == "friday") {
		index = 4;
		add_point++;
	}
	if (wk == "saturday") {
		index = 5;
		add_point += 2;
		weeken[id2] += 1;
	}
	if (wk == "sunday") {
		index = 6;
		add_point += 2;
		weeken[id2] += 1;
	}

	//사용자ID별 요일 데이터에 1씩 증가
	dat[id2][index] += 1;
	points[id2] += add_point;
}

void runAttendanceManager() {
	auto attendanceList = readAttendanceListFromFile(ATTENDANCE_LIST_FILE_PATH);

	for (auto& attendance : attendanceList) {
		calAttendanceScore(attendance.name, attendance.weekday);
	}

	for (int i = 1; i <= id_cnt; i++) {
		if (dat[i][2] > 9) {
			points[i] += 10;
		}

		if (dat[i][5] + dat[i][6] > 9) {
			points[i] += 10;
		}

		if (points[i] >= 50) {
			grade[i] = 1;
		}
		else if (points[i] >= 30) {
			grade[i] = 2;
		}
		else {
			grade[i] = 0;
		}

		cout << "NAME : " << names[i] << ", ";
		cout << "POINT : " << points[i] << ", ";
		cout << "GRADE : ";

		if (grade[i] == 1) {
			cout << "GOLD" << "\n";
		}
		else if (grade[i] == 2) {
			cout << "SILVER" << "\n";
		}
		else {
			cout << "NORMAL" << "\n";
		}
	}

	std::cout << "\n";
	std::cout << "Removed player\n";
	std::cout << "==============\n";
	for (int i = 1; i <= id_cnt; i++) {

		if (grade[i] != 1 && grade[i] != 2 && wed[i] == 0 && weeken[i] == 0) {
			std::cout << names[i] << "\n";
		}
	}
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