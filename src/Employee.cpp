//
// Created by youlong on 2021/9/11.
//

#include <string>
#include <iostream>
#include "Employee.h"

Employee::Employee(std::string lastName, std::string firstName, std::string birthOfDate, std::string email) {
    this->lastName = lastName;
    this->firstName = firstName;
    this->birthOfDate = new Date(birthOfDate);
    this->email = email;
}

std::string Employee::getFirstName() {
    return firstName;
}

bool Employee::isBirthday(Date *today) {
    if (birthOfDate->isSameDate(today)) {
        return true;
    }
    return false;
}

bool Employee::operator==(const Employee &rhs) const {
    return lastName == rhs.lastName &&
           firstName == rhs.firstName &&
           birthOfDate->isSameDate(rhs.birthOfDate) &&
           email == rhs.email;
}

bool Employee::operator!=(const Employee &rhs) const {
    return !(rhs == *this);
}

void Employee::print() {
    std::cout << lastName << "," << firstName << std::endl;
}

std::string Employee::getEmail() {
    return email;
}
