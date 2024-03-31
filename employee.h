#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
  private:
    int id;
    string first_name;
    string last_name;
    int boss_id;
  public:
    Employee(const int Id = 0, const string FirstName = "", const string LastName = "", const int BossId = 0):
        id{Id}, first_name{FirstName}, last_name{LastName}, boss_id{BossId} {};
    int getId() const {return id;};
    int getBossId() const {return boss_id;};
    string getFirstName() const {return first_name;};
    string getLastName() const {return last_name;};
};