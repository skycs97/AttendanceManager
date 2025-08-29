#include "file_reader.h"

bool FileReader::openFile()
{
	ifs.open(filePath);

	if (ifs.is_open() == false) {
		return false;
	}
}

string FileReader::getNext()
{
	string word;

	if (ifs.is_open() == false) {
		throw std::exception("file is not open");
	}

	ifs >> word;

	return word;
}

FileReader::FileReader(const string& filePath) : filePath(filePath)
{
	if (openFile() == false) {
		std::exception("file is not open");
	}
}
