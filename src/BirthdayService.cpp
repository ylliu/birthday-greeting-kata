//
// Created by youlong on 2021/9/11.
//

#include <vector>
#include <iostream>
#include "BirthdayService.h"

BirthdayService::BirthdayService(EmployeeRepository *employeeRepository, GreetingSender *greetingSender) {
    this->employeeRepository = employeeRepository;
    this->greetingSender = greetingSender;
}

void BirthdayService::sendGreetings(Date *today) {
    std::vector<Employee> employees = employeeRepository->findEmployeesWhoseBirthdayIs(today);
    for (Employee employee:employees) {
        greetingSender->sendMessage(employee);
    }
}
