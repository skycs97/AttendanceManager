#pragma once
#include <map>

#include "id_manager.h"
#include "attendees.h"
#include <memory>


class AttendeesDatabase {
public:
	AttendeesDatabase();

	void attend(string name, string dayOfWeek);
	void regist(string name);

	std::shared_ptr<Attendees> getAttendeesFromId(int id);
	std::shared_ptr<Attendees> getAttendeesFromName(string name);

	int getMaxId();
private:
	IdManager idManager;
	std::map<int, std::shared_ptr<Attendees>> attendeesList;
};

