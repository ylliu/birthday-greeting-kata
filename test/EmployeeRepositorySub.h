//
// Created by youlong on 2021/9/11.
//

#ifndef BIRTHDAYGREETING3_EMPLOYEEREPOSITORYSUB_H
#define BIRTHDAYGREETING3_EMPLOYEEREPOSITORYSUB_H


#include <vector>
#include "../src/EmployeeRepository.h"

class EmployeeRepositorySub : public EmployeeRepository {
public:
    std::vector<Employee> findEmployeesWhoseBirthdayIs(Date *today);
};


#endif //BIRTHDAYGREETING3_EMPLOYEEREPOSITORYSUB_H
