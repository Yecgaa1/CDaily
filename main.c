#include <stdio.h>
#include <mem.h>

//
// Created by yao on 2020/12/22
int main() {
    int i = 0, j = 0;
    //scanf("%d %d",&i,&j);
    FILE *fp1;
    char filename1[] = "./Form.txt"; //文件名
    fp1 = fopen(filename1, "r");
    char StrLine[1024];
    memset(StrLine, 0, sizeof(StrLine));
    fgets(StrLine, 1024, fp1);
    i = (int) (StrLine[0] - '0');
    j = (int) (StrLine[2] - '0');

    double A[i][j + j];
    memset(A, 0, sizeof(A));
    int i1 = 0;

    while (i1 < i) {
        memset(StrLine, 0, sizeof(StrLine));
        fgets(StrLine, 1024, fp1);
        int j1 = 0;//当前读到的列
        while (j1 < j) {
            A[i1][j1] = (int) (StrLine[j1 * 2] - '0');
            j1+=1;
        }
        i1 += 1;

    }
    i1=0;
    while(i1<i) {
        A[i1][j + i1] = 1;
        i1+=1;
    }
    i1=1;
    int j1=0;
    int t=0;
    if (A[])
    for(;j1<j;j1++)
    {

    }
    return 0;
}



