#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

using namespace std;

Employee getEmployeeByName(string first_name, string last_name, const vector<Employee> &employeeList){
    for (const Employee &employee : employeeList){
        if (first_name == employee.first_name && last_name == employee.last_name){
            return employee;
        }
    }
    cout << first_name << " " << last_name << " not found.\n";
    exit(-1);
}
Employee getEmployeeById(int id, const vector<Employee> &employeeList){
    for (const Employee &employee : employeeList){
        if (id == employee.id){
            return employee;
        }
    }
    cout << id << " not found.\n";
    exit(-1);
}

// check if employee1 is the subordinate of employee2
bool isSubordinate(Employee employee1, Employee employee2, const vector<Employee> &employeeList){
    Employee employee = employee1;
    Employee boss = getEmployeeById(employee.boss_id, employeeList);
    while (employee.id != boss.id){
        if (boss.id == employee2.id){
            return true;
        }
        employee = boss;
        boss = getEmployeeById(employee.boss_id, employeeList);
    }
    return false;
}

Employee getTopBoss(Employee employee, const vector<Employee> &employeeList){
    Employee boss = getEmployeeById(employee.boss_id, employeeList);
    while (employee.id != boss.id){
        employee = boss;
        boss = getEmployeeById(employee.boss_id, employeeList);
    }
    return employee;
}

bool haveSameTopBoss(Employee employee1, Employee employee2, const vector<Employee> &employeeList){
    if (getTopBoss(employee1, employeeList).id == getTopBoss(employee2, employeeList).id){
        return true;
    }
    return false;
}