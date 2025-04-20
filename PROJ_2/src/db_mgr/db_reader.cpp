#include <iostream>
#include "db_reader.h"

bool DB_Reader::read_emp_data(
    const std::list<Employee> &emp_list,
    const std::string &emp_id,
    Employee &emp
) {
    bool found = false;
    for (auto &itr: emp_list){
        if (itr.getId() == emp_id){
            emp=itr;
            found = true;
            break;
        }
    }
    return found;
}