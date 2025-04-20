#include "employee.h"

Employee::Employee(){
    this->id = "EID:0";
    this->name = "Name:0";
    this->designation = "Designation:0";
}

Employee::Employee(
    std::string p_id,
    std::string p_name,
    std::string p_designation
)  {
    this->id = p_id;
    this->name = p_name;
    this->designation = p_designation;
}

std::string Employee::getId() const {
    return this->id;
}

void Employee::setId(const std::string &value) {
    this->id = value;
}

std::string Employee::getName() const {
    return this->name;
}

void Employee::setName(const std::string &value) {
    this->name = value;
}

std::string Employee::getDesignation() const {
    return this->designation;
}

void Employee::setDesignation(const std::string &value) {
    this->designation = value;
}


