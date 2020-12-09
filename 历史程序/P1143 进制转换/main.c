#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
char b[10];
int main() {

    int a,num=0,j=0,c;
    scanf("%d",&a);
    getchar();
    gets(b);
    scanf("%d",&c);
    for(int i=strlen(b);i>0;i--)
    {
        if(isalpha(b[i-1]))
            num+=(b[i-1]-'0'-7)*pow(a,j);
        else
            num+=(b[i-1]-'0')*pow(a,j);
        j++;
    }
    //printf("%d",num);
    for(int i=0;i<100;i++)
    {
        if(num%c>9)
            b[i]=(num%c+55);
        else
            b[i]=num%c;
        num/=c;
        if(num==0)
            break;
    }
    //char d[]="Hello";
    //printf("%s\n", b);
    for(int i=0; i<8;i++)
    {
        printf("%c",b[i]);
    }
    return 0;

}
