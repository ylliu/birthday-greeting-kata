//
// Created by youlong on 2021/9/11.
//

#ifndef BIRTHDAYGREETING3_EMPLOYEE_H
#define BIRTHDAYGREETING3_EMPLOYEE_H

#include <string>
#include "Date.h"

class Employee {

public:
    Employee(std::string lastName, std::string firstName, std::string birthOfDate, std::string email);

    std::string getFirstName();

    bool isBirthday(Date *today);

    bool operator==(const Employee &rhs) const;

    bool operator!=(const Employee &rhs) const;

    void print();

    std::string getEmail();

private:
    std::string lastName;
    std::string firstName;
    Date *birthOfDate;
    std::string email;
};


#endif //BIRTHDAYGREETING3_EMPLOYEE_H
