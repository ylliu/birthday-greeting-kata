//
// Created by youlong on 2021/9/11.
//

#ifndef BIRTHDAYGREETING3_DATE_H
#define BIRTHDAYGREETING3_DATE_H


#include <string>

class Date {

public:
    Date(std::string yyyyMMdd);

    bool isSameDate(Date *date);

    bool operator==(const Date &rhs) const;

    bool operator!=(const Date &rhs) const;

private:

    int getMonth();

    int getDay();

    std::string yyyyMMdd;
};


#endif //BIRTHDAYGREETING3_DATE_H
