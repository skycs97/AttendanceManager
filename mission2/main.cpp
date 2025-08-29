#include <string>

#include "gmock/gmock.h"
#include "attendance_manager.h"
#include "file_reader.h"
#include "config.h"

using std::string;

void runAttendanceManager(string attendanceListFilePath) {
	auto fileReader = std::make_shared<FileReader>(attendanceListFilePath);

	AttendanceManager attendanceManager(NUM_LINE_ATTENDANCE);
	attendanceManager.setFileReader(fileReader);

	attendanceManager.process();

	attendanceManager.printAttendanceInfo();
}

int main() {
#if defined(_DEBUG)
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
#else
	runAttendanceManager(ATTENDANCE_LIST_FILE_PATH);

	return 0;
#endif
}