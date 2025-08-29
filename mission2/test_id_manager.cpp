#include "gmock/gmock.h"
#include "id_manager.h"
class IdManagerFixture : public ::testing::Test {
protected:
	void SetUp() override {
		idManager.regist("Bob");
		idManager.regist("Jena");
	}
	void TearDown() override {

	}
public:
	IdManager idManager;
};

TEST_F(IdManagerFixture, getIdTc1) {
	int expected = 1;
	int actual = idManager.getIdFromName("Bob");

	EXPECT_EQ(expected, actual);
}

TEST_F(IdManagerFixture, getIdTc2) {
	int expected = 2;
	int actual = idManager.getIdFromName("Jena");

	EXPECT_EQ(expected, actual);
}

TEST_F(IdManagerFixture, getIdFail) {
	int expected = -1;
	int actual = idManager.getIdFromName("Jhon");

	EXPECT_EQ(expected, actual);
}