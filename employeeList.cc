#include <iostream>
#include <string>
#include <vector>
#include "employeeList.h"

using namespace std;

EmployeeList::EmployeeList(const int employeeNumber)
{
    for (int i = 0; i < employeeNumber; i++){
        int id, boss_id;
        string first_name, last_name;
        cin >> id >> first_name >> last_name >> boss_id;
        employeeList.push_back(Employee(id, first_name, last_name, boss_id));
    }
}

Employee EmployeeList::getEmployeeByName(string first_name, string last_name) const
{
    for (const Employee &employee : employeeList){
        if (first_name == employee.getFirstName() && last_name == employee.getLastName()){
            return employee;
        }
    }
    cout << first_name << " " << last_name << " not found.\n";
    exit(-1);
}

Employee EmployeeList::getEmployeeById(int id) const
{
    for (const Employee &employee : employeeList){
        if (id == employee.getId()){
            return employee;
        }
    }
    cout << id << " not found.\n";
    exit(-1);
}

// check if employee1 is the subordinate of employee2
bool EmployeeList::isSubordinate(const Employee &employee1, const Employee &employee2) const
{
    Employee employee = employee1;
    Employee boss = getEmployeeById(employee.getBossId());
    while (employee.getId() != boss.getId()){
        if (boss.getId() == employee2.getId()){
            return true;
        }
        employee = boss;
        boss = getEmployeeById(employee.getBossId());
    }
    return false;
}

Employee EmployeeList::getTopBoss(const Employee &employee) const
{
    Employee boss = getEmployeeById(employee.getBossId());
    Employee currentEmployee = employee;
    while (currentEmployee.getId() != boss.getId()){
        currentEmployee = boss;
        boss = getEmployeeById(currentEmployee.getBossId());
    }
    return currentEmployee;
}

bool EmployeeList::haveSameTopBoss(const Employee &employee1, const Employee &employee2) const
{
    if (getTopBoss(employee1).getId() == getTopBoss(employee2).getId()){
        return true;
    }
    return false;
}