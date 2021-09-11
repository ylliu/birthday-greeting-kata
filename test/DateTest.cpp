//
// Created by youlong on 2021/9/11.
//

#include <gtest/gtest.h>
#include "../src/Date.h"

class DateTest : public ::testing::Test {

};

TEST_F(DateTest, is_same_day) {
    Date *date = new Date("2021/12/08");
    Date *sameDay = new Date("2012/12/08");
    Date *isNotSameDay = new Date("2011/12/09");
    EXPECT_TRUE(date->isSameDate(sameDay));
    EXPECT_FALSE(date->isSameDate(isNotSameDay));
}
