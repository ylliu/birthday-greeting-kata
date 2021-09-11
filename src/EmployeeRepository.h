//
// Created by youlong on 2021/9/11.
//

#ifndef BIRTHDAYGREETING3_EMPLOYEEREPOSITORY_H
#define BIRTHDAYGREETING3_EMPLOYEEREPOSITORY_H


#include "Employee.h"
#include <vector>

class EmployeeRepository {
public:
    virtual std::vector<Employee> findEmployeesWhoseBirthdayIs(Date *today) = 0;
};


#endif //BIRTHDAYGREETING3_EMPLOYEEREPOSITORY_H
