#include "gmock/gmock.h"
#include "attendees_database.h"

class AttendeesDatabaseFixture : public ::testing::Test {
protected:
	void SetUp() override {
		attendeesDB.attend("Bob", "monday");
		attendeesDB.attend("Jhon", "sunday");
	}
	void TearDown() override {

	}
public:
	AttendeesDatabase attendeesDB;
};

TEST_F(AttendeesDatabaseFixture, dbTestTC1) {
	string expected = "Bob";
	string actual = attendeesDB.getAttendeesFromId(1)->getName();

	EXPECT_EQ(expected, actual);
}

TEST_F(AttendeesDatabaseFixture, dbTestTC2) {
	string expected = "Jhon";
	string actual = attendeesDB.getAttendeesFromId(2)->getName();

	EXPECT_EQ(expected, actual);
}

TEST_F(AttendeesDatabaseFixture, dbTestExceptionId) {
	EXPECT_THROW(attendeesDB.getAttendeesFromId(3), std::exception);
}


TEST_F(AttendeesDatabaseFixture, dbTestExceptionName) {
	EXPECT_THROW(attendeesDB.getAttendeesFromName("cheolsun"), std::exception);
}

TEST_F(AttendeesDatabaseFixture, dbAttendInvalidWeekday) {
	EXPECT_THROW(attendeesDB.attend("cheolsun", "dayday"), std::exception);
}