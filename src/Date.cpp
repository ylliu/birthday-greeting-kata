//
// Created by youlong on 2021/9/11.
//

#include "Date.h"

Date::Date(std::string yyyyMMdd) {
    this->yyyyMMdd = yyyyMMdd;
}

int Date::getMonth() {
    return atoi(yyyyMMdd.substr(5, 2).c_str());
}

int Date::getDay() {
    return atoi(yyyyMMdd.substr(8, 2).c_str());
}

bool Date::isSameDate(Date *date) {
    return this->getMonth() == date->getMonth() && this->getDay() == date->getDay();
}

bool Date::operator==(const Date &rhs) const {
    return yyyyMMdd == rhs.yyyyMMdd;
}

bool Date::operator!=(const Date &rhs) const {
    return !(rhs == *this);
}
