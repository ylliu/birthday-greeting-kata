//
// Created by youlong on 2021/9/11.
//

#include <gtest/gtest.h>
#include <libpq-fe.h>
#include <fstream>
#include "../src/Employee.h"
#include "../src/EmployeeRepository.h"
#include "../src/GreetingSender.h"
#include "../src/BirthdayService.h"
#include "../lib/json/json.h"
#include "../src/DataBaseEmployeesRepository.h"
#include "../src/MailSender.h"

class AcceptanceTest : public ::testing::Test {

};

TEST_F(AcceptanceTest, should_send_greetings_to_employees_whose_birthday_is_today) {
    //Given
    //往数据库里面写数据
    const char conninfo[] = "postgresql://postgres@localhost?port=5432&dbname=postgres&user=postgres&password=123456";
    PGconn *conn = PQconnectdb(conninfo);
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cout << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
    }
    PQexec(conn, "DELETE from employee");
    PQexec(conn, "INSERT INTO employee VALUES (1, 'Doe','John','1990/12/08','john.doe@gmail.com')");
    PQexec(conn, "INSERT INTO employee VALUES (2, 'Ann','Mary','1995/10/01','mary.ann@gmail.com')");

    EmployeeRepository *employeeRepository = new DataBaseEmployeesRepository();
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

TEST_F(AcceptanceTest, should_not_send_greetings_to_employees_whose_birthday_is_not_today) {
    //Given
    //往数据库里面写数据
    const char conninfo[] = "postgresql://postgres@localhost?port=5432&dbname=postgres&user=postgres&password=123456";
    PGconn *conn = PQconnectdb(conninfo);
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cout << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
    }
    PQexec(conn, "DELETE from employee");
    PQexec(conn, "INSERT INTO employee VALUES (1, 'Doe','John','1990/12/08','john.doe@gmail.com')");
    PQexec(conn, "INSERT INTO employee VALUES (2, 'Ann','Mary','1995/10/01','mary.ann@gmail.com')");

    EmployeeRepository *employeeRepository = new DataBaseEmployeesRepository();
    GreetingSender *greetingSender = new MailSender();

    BirthdayService *birthdayService = new BirthdayService(employeeRepository, greetingSender);
    birthdayService->sendGreetings(new Date("2021/12/09"));

    std::string line;
    std::ifstream greetings("greetings.json");
    ASSERT_FALSE(greetings.is_open());
    greetings.close();
}
