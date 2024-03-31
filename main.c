#include<stdio.h>
#include<string.h>
#include<stdbool.h>
typedef struct employee {
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
    int level;
}   Employee;
 
int main(){
    int n;
    scanf("%d", &n);
    Employee employee[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &(employee[i].id));
        scanf("%s", employee[i].first_name);
        scanf("%s", employee[i].last_name);
        scanf("%d", &(employee[i].boss_id));
    }
 
 
    int m;
    scanf("%d", &m);
    char e1[2][32], e2[2][32];
    int i1, i2;
    for (int i = 0; i < m; i++){
        scanf("%s%s%s%s", e1[0], e1[1], e2[0], e2[1]);
        for (int j = 0; j < n; j++){
            if (strcmp(e1[0], employee[j].first_name) == 0){
                if (strcmp(e1[1], employee[j].last_name) == 0)
                    i1 = j;
            }
            if (strcmp(e2[0], employee[j].first_name) == 0){
                if (strcmp(e2[1], employee[j].last_name) == 0)
                    i2 = j;
            }
        }
 
        int thisid = employee[i1].id;
        int upid = employee[i1].boss_id;
        bool subordinate = false, supervisor = false;
        int highest1 = -1, highest2 = -1;
        while(upid != thisid){
            for (int j = 0; j < n; j++){
                if(employee[j].id == upid){
                    thisid = upid;
                    upid = employee[j].boss_id;
                    break;
                }
            }
            if (thisid == employee[i2].id){
                printf("subordinate\n");
                subordinate = true;
            }
        }
        highest1 = thisid;
        if (!subordinate){
            thisid = employee[i2].id;
            upid = employee[i2].boss_id;
            while(upid != thisid){
                for (int j = 0; j < n; j++){
                    if(employee[j].id == upid){
                        thisid = upid;
                        upid = employee[j].boss_id;
                        break;
                    }
                }
                if (thisid == employee[i1].id){
                    printf("supervisor\n");
                    supervisor = true;
                }
            }
            highest2 = thisid;
        }
 
        if ((!subordinate) && (!supervisor)){
            if (highest1 == highest2)
                printf("colleague\n");
            else
                printf("unrelated\n");
        }
 
 
 
    }
 
 
}