//
// Created by 星星 on 2020/10/17.
//
#include <stdio.h>
#include <string.h>
#include <time.h>
struct Time
{
    int hour;
    int min;
    int sec;
};


struct Time getTime(void);
void Draw_Line(int a,int b,int c,int d);
void Draw_Circle(int a,int b,int c);
float sin(float a);
float cos(float a);
void main()
{
    struct Time a;
    struct Time tmp=getTime();
    Draw_Circle(64,64,60);
    Draw_Line(64,64,64,64);
    while(1)
    {
        a=getTime();
        //可以模拟出秒钟在走一半时，分钟应该走一格的一半，但精度并不够，不考虑
        if(tmp.sec!=a.sec)
        {
            tmp.sec=a.sec;
            //update
            int x=sin(6.0*tmp.sec)*60;
            int y=cos(6.0*tmp.sec)*60;
            Draw_Line(60,60,60+x,60+y);
            if(tmp.min==a.min)
                break;
            tmp.min=a.min;
            x=sin(6.0*tmp.min)*45;
            y=cos(6.0*tmp.min)*45;
            Draw_Line(60,60,60+x,60+y);
            tmp.hour=a.hour;
            x=sin(15.0*tmp.hour+0.25*tmp.min)*30;
            y=cos(15.0*tmp.hour+0.25*tmp.min)*30;
            Draw_Line(60,60,60+x,60+y);
            //delay_ms(500);
        }
    }
}
