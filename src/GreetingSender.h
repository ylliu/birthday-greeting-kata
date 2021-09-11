//
// Created by youlong on 2021/9/11.
//

#ifndef BIRTHDAYGREETING3_GREETINGSENDER_H
#define BIRTHDAYGREETING3_GREETINGSENDER_H

#include "Employee.h"

class GreetingSender {
public:
    virtual void sendMessage(Employee &employee) = 0;
};


#endif //BIRTHDAYGREETING3_GREETINGSENDER_H
