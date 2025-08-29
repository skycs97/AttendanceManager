#include "id_manager.h"

IdManager::IdManager()
{
	nameToId.clear();

	maxIdVal = 0;
}

bool IdManager::isExist(string name)
{
	if (nameToId.count(name) == 0) {
		return false;
	}

	return true;
}

int IdManager::regist(string name)
{
	int id = ++maxIdVal;
	
	nameToId.insert({ name, id });

	return id;
}

int IdManager::getIdFromName(string name)
{
	if (isExist(name) == false)
	{
		return -1;
	}

	return nameToId[name];
}

int IdManager::getMaxId() {
	return maxIdVal;
}
