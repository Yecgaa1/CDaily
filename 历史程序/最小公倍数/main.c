//
// Created by yao on 2020/12/22.
//
#include<stdio.h>
int min(int a,int b)
{
    int tmp=0;
    if(a>b)
        tmp=a;
    else
        tmp=b;
    while(tmp%a==0&&tmp%b==0)
        tmp++;
    return tmp;
}
int max(int a,int b)
{
    int tmp=0;
    if(a>b)
        tmp=b;
    else
        tmp=a;
    while(a%tmp==0&&b%tmp==0)
        tmp--;
    return tmp;
}
int main()
{
    int a=0,b=0;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("%d",min(a,b));
    printf("%d",max(a,b));
    return 0;
}