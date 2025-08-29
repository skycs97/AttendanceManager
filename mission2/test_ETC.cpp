#include "gmock/gmock.h"
#include "util.h"

TEST(ETC_TEST, DayOfWeekConvertTC1) {
	int expected = MONDAY;
	int actual = getWeekDayIdxFromString("monday");

	EXPECT_EQ(expected, actual);
}
TEST(ETC_TEST, DayOfWeekConvertTC2) {
	int expected = WEDNESDAY;
	int actual = getWeekDayIdxFromString("wednesday");

	EXPECT_EQ(expected, actual);
}
TEST(ETC_TEST, DayOfWeekConvertTC3) {
	int expected = SUNDAY;
	int actual = getWeekDayIdxFromString("sunday");

	EXPECT_EQ(expected, actual);
}

TEST(ETC_TEST, DayOfWeekConvertFail) {
	int expected = -1;
	int actual = getWeekDayIdxFromString("bewhydayday");

	EXPECT_EQ(expected, actual);
}