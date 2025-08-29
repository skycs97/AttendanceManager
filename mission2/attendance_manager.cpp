#include "attendance_manager.h"
#include <iostream>

void AttendanceManager::setFileReader(std::shared_ptr<FileReader> fileReader)
{
	this->fileReader = fileReader;
}

void AttendanceManager::parseFileAndMakeAttendList()
{
	for (int i = 0; i < NUM_MAX_LINE; ++i) {
		auto attendance = getNextAttendance();

		checkAndRegisterAttendees(attendance);
	}
}

AttendanceFormat AttendanceManager::getNextAttendance()
{
	AttendanceFormat attendance;
	//name
	attendance.name = fileReader->getNext();
	//dayOfWeek
	attendance.dayOfWeek = fileReader->getNext();

	return attendance;
}

void AttendanceManager::checkAndRegisterAttendees(const AttendanceFormat& atendance)
{
	attendeesDB.attend(atendance.name, atendance.dayOfWeek);
}

void AttendanceManager::printAttendees(std::shared_ptr<Attendees> attendees)
{
	std::cout << "NAME : " << attendees->getName() << ", ";
	std::cout << "POINT : " << attendees->getPoint() << ", ";
	std::cout << "GRADE : " << attendees->getGrade()->getGradeName() << "\n";
}

void AttendanceManager::printRemovePlayer() {
	std::cout << "\n";
	std::cout << "Removed player\n";
	std::cout << "==============\n";
	for (int id = 1; id <= attendeesDB.getMaxId(); id++) {
		auto attendees = attendeesDB.getAttendeesFromId(id);

		if (attendees->isRemovePlayer()) {
			std::cout << attendees->getName() << "\n";
		}
	}
}

void AttendanceManager::calPointAllAttendees()
{
	for (int id = 1; id <= attendeesDB.getMaxId(); ++id) {
		auto attendees = attendeesDB.getAttendeesFromId(id);
		attendees->calPoint();
	}
}

void AttendanceManager::setGradeAllAttendees()
{
	for (int id = 1; id <= attendeesDB.getMaxId(); ++id) {
		auto attendees = attendeesDB.getAttendeesFromId(id);
		auto grade = gradeGenerator.makeGrade(attendees->getPoint());

		attendees->setGrade(grade);
	}
}

void AttendanceManager::printAttendanceInfo()
{
	for (int id = 1; id <= attendeesDB.getMaxId(); ++id) {
		auto attendees = attendeesDB.getAttendeesFromId(id);

		printAttendees(attendees);
	}

	printRemovePlayer();
}

void AttendanceManager::process()
{
	parseFileAndMakeAttendList();
	calPointAllAttendees();
	setGradeAllAttendees();
}
