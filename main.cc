#include <iostream>
# include <string>

using namespace std;

struct Employee {
    int id;
    string first_name;
    string last_name;
    int boss_id;
    int level;
};
 
int main(void){
    int employeeNumber;
    cin >> employeeNumber;

    Employee employee[employeeNumber];
    for (int i = 0; i < employeeNumber; i++){
        cin >> employee[i].id >> employee[i].first_name >> employee[i].last_name >> employee[i].boss_id;
    }
 
    int queryNumber;
    cin >> queryNumber;

    string employee1[2], employee2[2];
    int id1, id2;
    for (int i = 0; i < queryNumber; i++){
        cin >> employee1[0] >> employee1[1] >> employee2[0] >> employee2[1];
        for (int j = 0; j < employeeNumber; j++){
            if (employee1[0] == employee[j].first_name && employee1[1] == employee[j].last_name){
                id1 = j;
            }
            if (employee2[0] == employee[j].first_name && employee2[1] == employee[j].last_name){
                id2 = j;
            }
        }
 
        int employeeId = employee[id1].id;
        int bossId = employee[id1].boss_id;
        bool subordinate = false, supervisor = false;
        int topBossOfEmployee1 = -1, topBossOfEmployee2 = -1;
        while(bossId != employeeId){
            for (int j = 0; j < employeeNumber; j++){
                if(employee[j].id == bossId){
                    employeeId = bossId;
                    bossId = employee[j].boss_id;
                    break;
                }
            }
            if (employeeId == employee[id2].id){
                printf("subordinate\n");
                subordinate = true;
            }
        }
        topBossOfEmployee1 = employeeId;

        if (!subordinate){
            employeeId = employee[id2].id;
            bossId = employee[id2].boss_id;
            while(bossId != employeeId){
                for (int j = 0; j < employeeNumber; j++){
                    if(employee[j].id == bossId){
                        employeeId = bossId;
                        bossId = employee[j].boss_id;
                        break;
                    }
                }
                if (employeeId == employee[id1].id){
                    printf("supervisor\n");
                    supervisor = true;
                }
            }
            topBossOfEmployee2 = employeeId;
        }
 
        if ((!subordinate) && (!supervisor)){
            if (topBossOfEmployee1 == topBossOfEmployee2)
                printf("colleague\n");
            else
                printf("unrelated\n");
        }
    }
    return 0;
}