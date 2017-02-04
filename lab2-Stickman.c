// Program to draw a stick man using Bresenham’s line drawing and 
// mid-point circle drawing algorithm.

#include <stdio.h>
#include <graphics.h>
#include <math.h>
#define PI 3.14159

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void pixel(int xc, int yc, int x, int y,int color)
{
     putpixel(xc+x,yc+y,color);
         putpixel(xc+y,yc+x,color);
         putpixel(xc-y,yc+x,color);
         putpixel(xc-x,yc+y,color);
         putpixel(xc-x,yc-y,color);
         putpixel(xc-y,yc-x,color);
         putpixel(xc+y,yc-x,color);
         putpixel(xc+x,yc-y,color);
}

void drawcircle(int xc, int yc, int r, int color)
{
    int x = 0;
    int y = r;
    int p = 1-r;
    pixel(xc,yc,x,y,color);
    while(x<y)
    {
        if(p<0)
        {
            x = x + 1;
            p = p + 2*x + 1;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + (2*x) -(2*y) +1;
        }
        pixel(xc,yc,x,y,color);
    }
}

void bresLine(int x1,int y1,int x2,int y2)
{
    float m=(float)(y2-y1)/(x2-x1);
    int p;
  
    if(abs(m)<=1)
    {
        if(x1>x2)
        {
            swap(&x1,&x2);
            swap(&y1,&y2);
        }
        if(m>=0)
        {
            p=2*(y2-y1)-(x2-x1);
            putpixel(x1,y1,WHITE);
            while(x1<=x2)
            {
                x1++;
                if(p<=0)
                    p+=2*(y2-y1);
                else
                {
                    y1++;
                    p+=2*((y2-y1)-(x2-x1));
                }
                putpixel(x1,y1,WHITE);
            }
        }

        else
        {
            p=2*(y1-y2)+(x2-x1);
            putpixel(x1,y1,WHITE);
            while(x1<=x2)
            {
                x1++;
                if(p<=0)
                    p+=2*(y1-y2);
                else
                {
                    y1--;
                    p+=2*((y1-y2)+(x2-x1));
                }
                putpixel(x1,y1,WHITE);
            }
        }
    }
     else
    {
        if(y1>y2)
        {
            swap(&x1,&x2);
            swap(&y1,&y2);
        }
        if(m>=0)
        {
            p=2*(x2-x1)-(y2-y1);
            putpixel(x1,y1,WHITE);
            while(y1<=y2)
            {
                y1++;
                if(p<=0)
                    p+=2*(x2-x1);
                else
                {
                    x1++;
                    p+=2*((x2-x1)-(y2-y1));
                }
                putpixel(x1,y1,WHITE);
            }
        }

        else
        {
            p=2*(x1-x2)+(y2-y1);
            putpixel(x1,y1,WHITE);
            while(y1<=y2)
            {
                y1++;
                if(p<=0)
                    p+=2*(x1-x2);
                else
                {
                    x1--;
                    p+=2*((x1-x2)+(y2-y1));
                }
                putpixel(x1,y1,WHITE);
            }
        }
    }
}

float fcircle(float x,float y,int rad)
{    return x*x + y*y - rad*rad; }
  
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int i;
    /*bresLine(200,200,200+100*cos(PI/4),200+100*sin(PI/4));
    bresLine(200,200,200-100*cos(PI/4),200-100*sin(PI/4));
    bresLine(200,200,200-100*cos(PI/4),200+100*sin(PI/4));
    bresLine(200,200,200+100*cos(PI/4),200-100*sin(PI/4));
    for( i = 200; i <=300;i++)
        putpixel(200,i,WHITE);
    for( i = 200; i >=100;i--)
        putpixel(200,i,WHITE);
   
    drawcircle(200+100*cos(PI/4),200+100*sin(PI/4),20,WHITE);
    drawcircle(200-100*cos(PI/4),200-100*sin(PI/4),20,WHITE);
    drawcircle(200-100*cos(PI/4),200+100*sin(PI/4),20,WHITE);
    drawcircle(200+100*cos(PI/4),200-100*sin(PI/4),20,WHITE);
    drawcircle(201,300,20,WHITE);
    drawcircle(200,100,20,WHITE);
  */
    drawcircle(100,100,50,WHITE);
    drawcircle(125,90,5,WHITE);
    drawcircle(75,90,5,WHITE);
    bresLine(90,110,110,110);   
    for( i = 150; i <=350;i++)
        putpixel(100,i,WHITE);
    bresLine(100,200,100+50*cos(PI/4),200+50*sin(PI/4));
    bresLine(100,200,100-50*cos(PI/4),200+50*sin(PI/4));
    bresLine(100,350,100+50*cos(PI/4),350+50*sin(PI/4));
    bresLine(100,350,100-50*cos(PI/4),350+50*sin(PI/4));
    delay(10000);
  
    closegraph();
    return 0;
}