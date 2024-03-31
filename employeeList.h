#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H

#include <vector>
#include "employee.h"

using namespace std;

class EmployeeList {
  private:
    vector<Employee> employeeList;
    Employee getEmployeeById(const int id) const;
    Employee getTopBoss(const Employee &employee) const;
  public:
    EmployeeList(const int employeeNumber);
    Employee getEmployeeByName(const string first_name, const string last_name) const;
    bool isSubordinate(const Employee &employee1, const Employee &employee2) const;
    bool haveSameTopBoss(const Employee &employee1, const Employee &employee2) const;
};

#endif