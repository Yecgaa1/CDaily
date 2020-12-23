//
// Created by 星星 on 2020/12/9.
//

#ifndef CDAILY_FUNCTION_H
#define CDAILY_FUNCTION_H

#include <mem.h>
# include <stdio.h>
# include <stdlib.h>

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
void bubble_sort(int arr[], int len,int sym[]) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                temp = sym[j];
                sym[j] = sym[j + 1];
                sym[j + 1] = temp;
            }
}

void Load() {

    //加载学校

    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    FILE *fp4;
    FILE *fp5;

    char filename1[] = "./SQL/School/schoolName.txt"; //文件名
    char StrLine[1024];             //每行最大读取的字符数
    fp1 = fopen(filename1,"r");
    if(fp1!=NULL)
    {
        while (!feof(fp1)) {
            memset(StrLine,0,sizeof(StrLine));
            fgets(StrLine, 1024, fp1);  //读取一行
            if(StrLine[0]==0||StrLine[0]=='\n')
                break;
            //printf("%s\n", StrLine); //输出
            strcpy(schoolName[schoolFormNum].name,StrLine);
            schoolFormNum++;
        }
    }

    fclose(fp1);                     //关闭文件

    //加载比赛
    strcpy(filename1,"./SQL/Game/gameName.txt");
    char filename2[]="./SQL/Game/gameType.txt";

    fp1 = fopen(filename1,"r");
    fp2 = fopen(filename2,"r");
    if(fp1!=NULL)
    {
        while (!feof(fp1)) {
            memset(StrLine,0,sizeof(StrLine));
            fgets(StrLine, 1024, fp1);
            if(StrLine[0]==0||StrLine[0]=='\n')
                break;
            strcpy(gameName[gameFormNum].name, StrLine);
            memset(StrLine,0,sizeof(StrLine));
            fgets(StrLine, 1024, fp2);
            gameName[gameFormNum].type = (int) (StrLine[0] - '0');
            gameFormNum++;
        }
    }
    fclose(fp1);
    fclose(fp2);


    //加载主数据
    strcpy(filename1,"./SQL/Form/authName.txt");
    strcpy(filename2,"./SQL/Form/gameName.txt");
    char filename3[]="./SQL/Form/schoolName.txt";
    char filename4[]="./SQL/Form/rank.txt";
    char filename5[]="./SQL/Form/score.txt";
    fp1 = fopen(filename1,"r");
    fp2 = fopen(filename2,"r");
    fp3 = fopen(filename3,"r");
    fp4 = fopen(filename4,"r");
    fp5 = fopen(filename5,"r");
    if(fp1!=NULL)
    {
        while (!feof(fp1)) {
            memset(StrLine,0,sizeof(StrLine));
            fgets(StrLine, 1024, fp1);
            if(StrLine[0]==0||StrLine[0]=='\n')
                break;

            strcpy(gameForm[FormNum].authName,StrLine);
            memset(StrLine,0,sizeof(StrLine));
            fgets(StrLine, 1024, fp2);
            strcpy(gameForm[FormNum].gameName,StrLine);
            memset(StrLine,0,sizeof(StrLine));
            fgets(StrLine, 1024, fp3);
            strcpy(gameForm[FormNum].schoolName,StrLine);
            memset(StrLine,0,sizeof(StrLine));
            fgets(StrLine, 1024, fp4);
            gameForm[FormNum].rank= (int) (StrLine[0] - '0');
            memset(StrLine,0,sizeof(StrLine));
            fgets(StrLine, 1024, fp5);
            gameForm[FormNum].score= (int) (StrLine[0] - '0');

            FormNum++;
        }
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);


}

void AddScore() {
    printf("选择比赛\n");
    int j;
    if(gameFormNum==0)
    {
        printf("先添加比赛？");
        return;
    }
    for (j = 0; j<gameFormNum; j++) {
        printf("%d:%s\n", j, gameName[j].name);
    }
    int i = 0;
    scanf("%d", &i);
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
        if(gameFormNum==0)
        {
            printf("先添加学校？");
            return;
        }
        for (j = 0; j<schoolFormNum; j++) {
            printf("%d:%s\n", j, schoolName[j].name);
        }
        scanf("%d", &i);
        if (i > j) {
            NoneAvoid();
            return;
        }
        strcpy(tmpForm.gameName, gameName[i].name);
        printf("名字\n");
        char t[100];
        gets(t);
        memset(t,0,sizeof(t));
        gets(t);
        strcpy(tmpForm.authName,t);
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
        strcpy(gameForm[FormNum].gameName, tmpForm.gameName);
        strcpy(gameForm[FormNum].schoolName, tmpForm.schoolName);
        strcpy(gameForm[FormNum].authName, tmpForm.authName);
        gameForm[FormNum].rank = tmpForm.rank;
        gameForm[FormNum].score = tmpForm.score;
        FormNum += 1;
    }


}

void Sort() {
    int sum[schoolFormNum];
    memset(sum, 0, sizeof(sum));
    int Syntmp[schoolFormNum];
    memset(Syntmp, 0, sizeof(Syntmp));
    for(int i=0;i<schoolFormNum;i++)
    {
        Syntmp[i]=i;
    }
    for (int i = 0; i<FormNum; i++) {
        int j=0;
        for(j=0;j<schoolFormNum;j++)
            if(!strcmp(gameForm[i].schoolName,schoolName[j].name))
                sum[j]+=gameForm[i].score;
    }
    //int len = (int) sizeof(sum) / sizeof(*sum);
    bubble_sort(sum, schoolFormNum,Syntmp);
    for (int i = 0; i < schoolFormNum; i++)
        printf("第%d的是%s总分是%d \n",i+1,schoolName[Syntmp[i]].name, sum[i]);
}

void Change()
{
    printf("选择比赛\n");
    int j;
    for (j = 0; j<gameFormNum; j++) {
        printf("%d:%s\n", j, gameName[j].name);
    }
    int i = 0;
    scanf("%d", &i);
    if (i > j) {
        NoneAvoid();
        return;
    }
    char tmp[100]="";
    strcpy(tmp,gameName[i].name);

    printf("选择名次\n");
    scanf("%d", &i);
    char tmp1[100];
    char tmp2[100];
    printf("修改学校名为：\n");
    scanf("%s", tmp1);
    printf("修改选手名为：\n");
    scanf("%s", tmp2);
    int flag=0;
    for (j = 0; j<FormNum; j++)
    {
        if((!strcmp(tmp,gameForm[j].gameName))&&i==gameForm[j].rank)
        {
            strcpy(tmp1,gameForm[j].schoolName);
            strcpy(tmp2,gameForm[j].authName);
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("失败\n");
    } else
    {
        printf("成功\n");
    }

/*
    printf("存在以下项目可修改\n");
    for (j = 0; j<FormNum; j++) {

        if(!strcmp(tmp,gameForm[j].gameName)) {

            printf("%d:%s %d\n", j, gameForm[j].gameName,gameForm[j].rank);

        }
    }
    scanf("%d", &i);*/


}

void Save() {

    //保存学校

    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    FILE *fp4;
    FILE *fp5;

    char filename1[] = "./SQL/School/schoolName.txt"; //文件名
    char StrLine[1024];             //每行最大读取的字符数
    fp1 = fopen(filename1,"w+");
    for(int i=0;i<schoolFormNum;i++)
    {
        strcpy(StrLine,schoolName[i].name);
        fprintf(fp1,"%s\n",StrLine);
    }
    fclose(fp1);                     //关闭文件

    //加载比赛
    strcpy(filename1,"./SQL/Game/gameName.txt");
    char filename2[]="./SQL/Game/gameType.txt";

    fp1 = fopen(filename1,"w+");
    fp2 = fopen(filename2,"w+");
    for(int i=0;i<gameFormNum;i++)
    {
        strcpy(StrLine,gameName[i].name);
        fprintf(fp1,"%s\n",StrLine);
        itoa(gameName[i].type, StrLine, 10);
        fprintf(fp2,"%c\n",StrLine[0]);
    }

    fclose(fp1);
    fclose(fp2);


    //加载主数据
    strcpy(filename1,"./SQL/Form/authName.txt");
    strcpy(filename2,"./SQL/Form/gameName.txt");
    char filename3[]="./SQL/Form/schoolName.txt";
    char filename4[]="./SQL/Form/rank.txt";
    char filename5[]="./SQL/Form/score.txt";
    fp1 = fopen(filename1,"w+");
    fp2 = fopen(filename2,"w+");
    fp3 = fopen(filename3,"w+");
    fp4 = fopen(filename4,"w+");
    fp5 = fopen(filename5,"w+");

    for(int i=0;i<FormNum;i++)
    {
        strcpy(StrLine,gameForm[i].authName);
        fprintf(fp1,"%s\n",StrLine);
        strcpy(StrLine,gameForm[i].gameName);
        fprintf(fp2,"%s",StrLine);
        strcpy(StrLine,gameForm[i].schoolName);
        fprintf(fp3,"%s",StrLine);
        itoa(gameForm[i].rank, StrLine, 10);
        fprintf(fp4,"%c\n",StrLine[0]);
        itoa(gameForm[i].score, StrLine, 10);
        fprintf(fp5,"%c\n",StrLine[0]);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);


}

void AddSchool() {
    printf("学校名称?\n");
    char i[100] = "";
    gets(i);
    gets(i);
    if (i == NULL) {
        NoneAvoid();
        return;
    }
    int j;
    for (j = 0; j<schoolFormNum; j++) {
        if (schoolName[j].name == i) {
            printf("已存在\n");
            return;
        }
    }
    strcpy(schoolName[j].name, i);
    schoolFormNum+=1;
    printf("已添加\n");
}

void AddGame() {
    printf("输入比赛名称\n");
    char i[100] = "";
    gets(i);
    gets(i);
    if (i == NULL) {
        NoneAvoid();
        return;
    }
    int j;
    for (j = 0; j<gameFormNum; j++) {
        if (gameName[j].name == i) {
            printf("已存在\n");
            return;
        }
    }
    strcpy(gameName[j] .name, i);
    printf("输入比赛积分类型\n");
    gets(i);
    if (strcmp(i, "1") == 0)
        gameName[j].type = 0;
    else
        gameName[j].type = 1;

    gameFormNum++;

    printf("已添加\n");
}

#endif //CDAILY_FUNCTION_H
