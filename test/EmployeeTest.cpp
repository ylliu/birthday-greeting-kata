//
// Created by youlong on 2021/9/11.
//

#include <gtest/gtest.h>
#include "../src/Employee.h"

class EmployeeTest : public ::testing::Test {

};

TEST_F(EmployeeTest, should_test_employee_birthday) {
    Employee *employee = new Employee("Doe", "John", "1990/12/08", "john.doe@gmail.com");
    EXPECT_TRUE(employee->isBirthday(new Date("2021/12/08")));
    EXPECT_FALSE(employee->isBirthday(new Date("2012/12/09")));
}