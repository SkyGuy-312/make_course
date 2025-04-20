#pragma once

#include "employee.h"
#include <list>

class DB_Reader {

    public:
        bool read_emp_data(
            const std::list<Employee> &emp_list,
            const std::string &emp_id,
            Employee &emp
        );
};