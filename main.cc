#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

using namespace std;

int main(void){
    int employeeNumber;
    cin >> employeeNumber;

    vector<Employee> employeeList(employeeNumber);
    for (Employee &employee : employeeList){
        cin >> employee.id;
        cin >> employee.first_name;
        cin >> employee.last_name;
        cin >> employee.boss_id;
    }
 
    int queryNumber;
    cin >> queryNumber;

    for (int i = 0; i < queryNumber; i++){
        string first_name1, last_name1, first_name2, last_name2;
        cin >> first_name1 >> last_name1 >> first_name2 >> last_name2;
        
        Employee employee1 = getEmployeeByName(first_name1, last_name1, employeeList);
        Employee employee2 = getEmployeeByName(first_name2, last_name2, employeeList);
 
        if(isSubordinate(employee1, employee2, employeeList)){
            cout << "subordinate" << endl;
        }
        else if (isSubordinate(employee2, employee1, employeeList)){
            cout << "supervisor" << endl;
        }
        else if (haveSameTopBoss(employee1, employee2, employeeList)){
            cout << "colleague" << endl;
        }
        else{
            cout << "unrelated" << endl;
        }
    }
    return 0;
}