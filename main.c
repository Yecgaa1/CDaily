#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
   char b[10];
   int a,num=0,j=0;
   scanf("%d",&a);
   getchar();
   gets(b);
   for(int i=strlen(b);i>=0;i++)
   {
       num+=(int)b[i]*pow(a,j);
       j++;
   }
`    printf("%d",num);
`

    return 0;
}
