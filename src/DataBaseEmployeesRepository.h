//
// Created by youlong on 2021/9/11.
//

#ifndef BIRTHDAYGREETING3_DATABASEEMPLOYEESREPOSITORY_H
#define BIRTHDAYGREETING3_DATABASEEMPLOYEESREPOSITORY_H


#include "Date.h"
#include "Employee.h"
#include "EmployeeRepository.h"

class DataBaseEmployeesRepository : public EmployeeRepository {

public:
    std::vector<Employee> findEmployeesWhoseBirthdayIs(Date *today) override;
};


#endif //BIRTHDAYGREETING3_DATABASEEMPLOYEESREPOSITORY_H
