#pragma once

#include <map>
#include <string>

using std::string;

class IdManager {
public:
	IdManager();

	bool isExist(string name);
	int regist(string name);

	int getIdFromName(string name);

	int getMaxId();
private:
	std::map<string, int> nameToId;

	int maxIdVal;
};
