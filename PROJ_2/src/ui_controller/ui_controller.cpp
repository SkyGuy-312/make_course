#include <iostream>
#include "ui_contoller.h"

UI_Controller::UI_Controller() {
    std::clog << "UI_Controller constructor called" << std::endl;
}

void UI_Controller::get_emp_id_and_show_details(){
    std::string id;
    DB_Mgr dbMgrObj;

    do
    {
        id.erase();
        std::clog << "\nEnter employee ID: ";
        std::getline(std::cin, id);

        auto emp = dbMgrObj.get_emp_details(id);

        if (emp.getId().empty()) {
            std::clog << "Invalid employee ID!" << std::endl;
        } else {
            std::clog << "\n Employee ID: " << emp.getId() << "\nName: " << emp.getName() << "\nDesignation: " << emp.getDesignation() << std::endl;
        }
    } while (id !="0");
}

void UI_Controller::show() {
    std::clog << __PRETTY_FUNCTION__ << std::endl;
    get_emp_id_and_show_details();
}