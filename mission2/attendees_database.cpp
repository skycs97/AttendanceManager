#include "attendees_database.h"
#include "util.h"
#include "attendance_manager.h"
#include "config.h"
AttendeesDatabase::AttendeesDatabase()
{
	attendeesList.clear();
}

void AttendeesDatabase::regist(string name) {
	int id = idManager.regist(name);
	auto attendees = std::make_shared<Attendees>(id, name);

	attendeesList.insert({ id, attendees });
}

std::shared_ptr<Attendees> AttendeesDatabase::getAttendeesFromName(string name)
{
	if(idManager.isExist(name) == false) {
		throw std::exception("this name is not registed");
	}

	return getAttendeesFromId(idManager.getIdFromName(name));
}

int AttendeesDatabase::getMaxId()
{
	return idManager.getMaxId();;
}

std::shared_ptr<Attendees> AttendeesDatabase::getAttendeesFromId(int id)
{
	if (attendeesList.count(id) == 0) {
		throw std::exception("this id is not registed");
	}

	return attendeesList[id];
}

void AttendeesDatabase::attend(string name, string dayOfWeek)
{
	int day = getWeekDayIdxFromString(dayOfWeek);

	if (day == -1) {
		throw std::exception("dayOfWeek is invalid");
	}

	if (idManager.isExist(name) == false) {
		regist(name);
	}
	
	auto attendees = getAttendeesFromName(name);
	attendees->attend((DayOfWeek)day);
}
