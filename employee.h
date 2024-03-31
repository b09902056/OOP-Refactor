#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Employee {
    int id;
    string first_name;
    string last_name;
    int boss_id;
};

Employee getEmployeeByName(string first_name, string last_name, const vector<Employee> &employeeList);

// check if employee1 is the subordinate of employee2
bool isSubordinate(Employee employee1, Employee employee2, const vector<Employee> &employeeList);

bool haveSameTopBoss(Employee employee1, Employee employee2, const vector<Employee> &employeeList);