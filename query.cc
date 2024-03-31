#include <iostream>
#include <string>
#include "query.h"

using namespace std;

void Query::run(const EmployeeList &employeeList) const
{
    for (int i = 0; i < queryNumber; i++){
        string first_name1, last_name1, first_name2, last_name2;
        cin >> first_name1 >> last_name1 >> first_name2 >> last_name2;
        
        Employee employee1 = employeeList.getEmployeeByName(first_name1, last_name1);
        Employee employee2 = employeeList.getEmployeeByName(first_name2, last_name2);
 
        if(employeeList.isSubordinate(employee1, employee2)){
            cout << "subordinate" << endl;
        }
        else if (employeeList.isSubordinate(employee2, employee1)){
            cout << "supervisor" << endl;
        }
        else if (employeeList.haveSameTopBoss(employee1, employee2)){
            cout << "colleague" << endl;
        }
        else{
            cout << "unrelated" << endl;
        }
    }

    return;
}