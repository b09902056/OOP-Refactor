#include <iostream>
#include "employeeList.h"
#include "query.h"

using namespace std;

int main(void){
    int employeeNumber;
    cin >> employeeNumber;

    EmployeeList employeeList(employeeNumber);
 
    int queryNumber;
    cin >> queryNumber;

    Query query(queryNumber);
    query.run(employeeList);

    return 0;
}