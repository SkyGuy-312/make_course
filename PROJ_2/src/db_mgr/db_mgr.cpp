#include "db_mgr.h"
#include "employee.h"
#include "db_reader.h"
#include <iostream>

DB_Mgr::DB_Mgr(){
    
    Employee obj1("Eid:1", "Subrat", "Software Engineer");
    std::clog << "Initializing employee list..." << std::endl;
    emp_list.emplace_back(obj1);

    emp_list.emplace_back("Eid:2", "Suman", "Sr.Software Engineer");
    emp_list.emplace_back("EID:3", "Bhagabat", "Engineering Lead");
    emp_list.emplace_back("EID:4", "Satyajit", "Manager");
    emp_list.emplace_back("EID:5", "Radha", "Sr.Manager");
}

Employee DB_Mgr::get_emp_details(const std::string &emp_id) {
    Employee emp;
    DB_Reader dbrObj;
    dbrObj.read_emp_data(emp_list, emp_id, emp);
    if (!found) {
        std::clog << "Employee not found!" << std::endl;
    }
    return emp;
}

std::list<Employee> DB_Mgr::getEmp_list() const {
    return emp_list;
}
