//
// Created by youlong on 2021/9/11.
//

#include <gtest/gtest.h>
#include <fstream>
#include <libpq-fe.h>
#include "../src/BirthdayService.h"
#include "../lib/json/json.h"
#include "EmployeeRepositorySub.h"
#include "../src/MailSender.h"

class BirthdayServiceTest : public ::testing::Test {

};

TEST_F(BirthdayServiceTest, should_send_greetings_to_employees_whose_birthday_is_today) {

    EmployeeRepository *employeeRepository = new EmployeeRepositorySub();
    GreetingSender *greetingSender = new MailSender();

    BirthdayService *birthdayService = new BirthdayService(employeeRepository, greetingSender);
    birthdayService->sendGreetings(new Date("2021/12/08"));

    std::string line;
    std::ifstream greetings("greetings.json");
    ASSERT_TRUE(greetings.is_open());
    Json::Reader reader;
    Json::Value greetingItem;
    if (reader.parse(greetings, greetingItem, FALSE)) {
        EXPECT_EQ("Happy Birthday!", greetingItem["Subject"].asString());
        EXPECT_EQ("sender@gmail.com", greetingItem["From"].asString());
        EXPECT_EQ("john.doe@gmail.com", greetingItem["To"].asString());
        EXPECT_EQ("Happy Birthday, dear John!", greetingItem["Body"].asString());
    }

    greetings.close();
    remove("greetings.json");
}
