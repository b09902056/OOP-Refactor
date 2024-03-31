#include "employeeList.h"

using namespace std;

class Query{
  private:
    int queryNumber;
  public:
    Query(const int QueryNumber = 0): queryNumber{QueryNumber} {};
    void run(const EmployeeList &employeeList) const;
};