#pragma once
#include <string>
#include <fstream>

using std::string;

class FileReader {
private:
	string filePath;
	std::ifstream ifs;
public:
	virtual bool openFile();
	virtual string getNext();

	FileReader(const string& filePath);
};