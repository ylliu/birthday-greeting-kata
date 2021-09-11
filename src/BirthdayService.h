//
// Created by youlong on 2021/9/11.
//

#ifndef BIRTHDAYGREETING3_BIRTHDAYSERVICE_H
#define BIRTHDAYGREETING3_BIRTHDAYSERVICE_H


#include "Date.h"
#include "EmployeeRepository.h"
#include "GreetingSender.h"

class BirthdayService {

public:
    BirthdayService(EmployeeRepository *employeeRepository, GreetingSender *greetingSender);

    void sendGreetings(Date *today);

private:
    EmployeeRepository *employeeRepository;
    GreetingSender *greetingSender;
};


#endif //BIRTHDAYGREETING3_BIRTHDAYSERVICE_H
