#include<stdio.h>
#include "function.h"
#include <string.h>
void run()
{
    printf("校际运动会管理系统程序\n"
           "1.添加成绩\n"
           "2.添加比赛\n"
           "3.添加学校\n"
           "4.修改记录\n"
           "5.排名\n"
           "6.退出！\n"
           "Author:Xutongxin\n");
    int i=0;
    scanf("%d", &i);

    switch(i) {
        case 1: {
            AddScore();
            run();
        }
        case 2: {
            AddGame();
            run();
        }
        case 3: {
            AddSchool();
            run();
        }
        case 4: {
            Change();
            run();
        }
        case 5: {
            Sort();
            run();
        }
        case 6: {
            Save();
            exit(0);
        }
    }
}

int main(){
    Load();
    run();
    return 0;
}

