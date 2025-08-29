#include "util.h"

const string DAY_OF_WEEK_STRING[NUM_DAY_OF_WEEK] = {
	"monday",
	"tuesday",
	"wednesday",
	"thursday",
	"friday",
	"saturday",
	"sunday"
};


int getWeekDayIdxFromString(string weekday) {
	for (int weekday_idx = 0; weekday_idx < NUM_DAY_OF_WEEK; ++weekday_idx) {
		if (weekday == DAY_OF_WEEK_STRING[weekday_idx]) {
			return weekday_idx;
		}
	}

	return -1;
}