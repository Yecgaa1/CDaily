//
// Created by 星星 on 2020/12/9.
//

#ifndef CDAILY_FUNCTION_H
#define CDAILY_FUNCTION_H

#include <mem.h>

int gameFormNum = 0;
int schoolFormNum = 0;
int FormNum = 0;
struct gameForm {
    char gameName[100];
    char authName[100];
    char schoolName[100];
    int rank;
    int score;
} gameForm[1000];
struct schoolName {
    char name[100];
} schoolName[100];
struct gameName {
    char name[100];
    int type;
} gameName[100];

void NoneAvoid() {
    printf("输入不合法\n");
}
void Load() {
    //加载学校
    char filename1[] = "./SQL/School/schoolName.txt"; //文件名
    FILE *fp1;
    FILE *fp2;
    char StrLine[1024];             //每行最大读取的字符数
    fp1 = fopen(filename1,"r");
    while (!feof(fp1)) {
        fgets(StrLine, 1024, fp1);  //读取一行
        //printf("%s\n", StrLine); //输出
        strcpy(schoolName[schoolFormNum].name,StrLine);
        schoolFormNum++;
    }
    fclose(fp1);                     //关闭文件
    //加载比赛
    strcpy(filename1,"./SQL/Game/gameName.txt");
    char filename2[]="./SQL/Game/gameType.txt";
    fp1 = fopen(filename1,"r");
    fp2 = fopen(filename2,"r");
    while (!feof(fp1)) {
        fgets(StrLine, 1024, fp1);  //读取一行
        //printf("%s\n", StrLine); //输出
        strcpy(gameName[gameFormNum].name,StrLine);
        fgets(StrLine, 1024, fp2);  //读取一行
        gameName[gameFormNum].type= (int) (StrLine - '0');
        gameFormNum++;
    }
    fclose(fp1);
    fclose(fp2);
    //加载主数据


}

void AddScore() {
    printf("选择比赛\n");
    int j;
    for (j = 0; gameName[j + 1].name != NULL; j++) {
        printf("%d:%s\n", j, gameName[j].name);
    }
    int i = 0;
    scanf("%d", i);
    if (i > j) {
        NoneAvoid();
        return;
    }
    struct gameForm tmpForm;
    strcpy(tmpForm.schoolName, schoolName[i].name);

    int q;//决定后面写几条数据
    if (gameName[i].type == 0) {
        q = 5;
    } else {
        q = 3;
    }
    for (int i_q = 1; i_q <= q; i_q++) {
        printf("第%d名录入\n", i_q);
        printf("选择学校\n");
        for (j = 0; schoolName[j + 1].name != NULL; j++) {
            printf("%d:%s\n", j, schoolName[j].name);
        }
        scanf("%d", i);
        if (i > j) {
            NoneAvoid();
            return;
        }
        strcpy(tmpForm.gameName, gameName[i].name);
        printf("名字\n");
        char t[100];
        strcpy(tmpForm.authName, gets(t));
        tmpForm.rank = i_q;
        if (q == 3) {
            switch (i_q) {
                case 1: {
                    tmpForm.score = 5;
                    break;
                }
                case 2: {
                    tmpForm.score = 3;
                    break;
                }
                case 3: {
                    tmpForm.score = 2;
                    break;
                }
            }
        } else {
            switch (i_q) {
                case 1: {
                    tmpForm.score = 7;
                    break;
                }
                case 2: {
                    tmpForm.score = 5;
                    break;
                }
                case 3: {
                    tmpForm.score = 3;
                    break;
                }
                case 4: {
                    tmpForm.score = 2;
                    break;
                }
                case 5: {
                    tmpForm.score = 1;
                    break;
                }
            }
        }
        strcpy(gameForm[FormNum + 1].gameName, tmpForm.gameName);
        strcpy(gameForm[FormNum + 1].schoolName, tmpForm.schoolName);
        strcpy(gameForm[FormNum + 1].authName, tmpForm.authName);
        gameForm[FormNum + 1].rank = tmpForm.rank;
        gameForm[FormNum + 1].score = tmpForm.score;
        FormNum += 1;
    }


}

void Sort() {

}

void Change() {

}

void Check() {

}

void Save() {

}

void AddSchool() {
    char i[100] = "";
    gets(i);
    if (i == NULL) {
        NoneAvoid();
        return;
    }
    int j;
    for (j = 0; schoolName[j + 1].name != NULL; j++) {
        if (schoolName[j].name == i) {
            printf("已存在");
            return;
        }
    }
    strcpy(schoolName[j + 1].name, i);
    printf("已添加");
}

void AddGame() {
    char i[100] = "";
    gets(i);
    if (i == NULL) {
        NoneAvoid();
        return;
    }
    int j;
    for (j = 0; gameName[j + 1].name != NULL; j++) {
        if (gameName[j].name == i) {
            printf("已存在");
            return;
        }
    }
    strcpy(gameName[j + 1].name, i);
    printf("输入比赛积分类型");
    gets(i);
    if (strcmp(i, "1") == 0)
        gameName[j].type = 0;
    else
        gameName[j].type = 1;
    printf("已添加");
}

#endif //CDAILY_FUNCTION_H
