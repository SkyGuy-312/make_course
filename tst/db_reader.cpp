#include <iostream>
#include "db_reader.h"

bool DB_Reader::read_emp_data(
    const std::list<Employee> &emp_list,
    const std::string &emp_id,
    Employee &emp
) {
    std::clog << "Reading employee data..." << std::endl;
    for (auto &itr: emp_list) {
        std::clog << "Checking employee ID: " << itr.getId() << std::endl;
        if (itr.getId() == emp_id) {
            emp = itr;
            return true;
        }
    }
    return false;
}