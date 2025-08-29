#pragma once
#include "file_reader.h"
#include "id_manager.h"
#include "attendees_database.h"
#include "grade.h"
#include <vector>

struct AttendanceFormat {
	string name;
	string dayOfWeek;
};

class AttendanceManager {
public:
	AttendanceManager(int NUM_MAX_LINE)
		:NUM_MAX_LINE(NUM_MAX_LINE) , gradeGenerator(GradeGenerator::getInstance()){
	}

	void setFileReader(std::shared_ptr<FileReader> fileReader);

	void printAttendanceInfo();
	void process();

private:
	std::shared_ptr<FileReader> fileReader;

	AttendeesDatabase attendeesDB;
	IdManager idManager;
	GradeGenerator& gradeGenerator;

	const int NUM_MAX_LINE;

	void parseFileAndMakeAttendList();
	void calPointAllAttendees();
	void setGradeAllAttendees();

	AttendanceFormat getNextAttendance();
	void checkAndRegisterAttendees(const AttendanceFormat& atendance);

	void printAttendees(std::shared_ptr<Attendees> attendees);
	void printRemovePlayer();
};