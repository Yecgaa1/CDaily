#include<stdio.h>
#include "function.h"
#include <string.h>
void run()
{
    printf("У���˶������ϵͳ����\n"
           "1.��ӳɼ�\n"
           "2.��ӱ���\n"
           "3.���ѧУ\n"
           "4.�޸ļ�¼\n"
           "5.����\n"
           "6.�˳���\n"
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

