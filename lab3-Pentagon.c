#include <stdio.h>
#include <stdlib.h>
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


void bresLine(int x1,int y1,int x2,int y2)
{
    float m=(float)(y2-y1)/(x2-x1);
    int p;
    int dx=(x2-x1);
    int dy=(y2-y1);
    int x=x1;
    int y=y1;

    if (!dx) 
	{ //vertical line special case
        if (dy > 0) 
        {
            y= y1;  
            do 
            putpixel(x1, y++, WHITE);
            while (y <= y2);
            return;
        } 
        else 
        {
            y= y2;
            do 
            putpixel(x1, y++, WHITE);
            while (y <= y1);
            return;
        }
    }
  
    if (!dy) 
    { //horizontal line special case
        if (dx > 0) 
        {
            x= x1;
            do 
            putpixel(x, y1, WHITE);
            while (++x <= x2);
            return;
        } 
        else 
        {
            x= x2; 
            do 
            putpixel(x, y1, WHITE);
            while (++x <= x1);
            return;
        }
    }

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

int main() {
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,r,s,tx,ty,an;r=50;
	s=2;an=90;
	x1=100+r*cos(0*PI/180);
	y1=100+r*sin(0*PI/180);
    x2=100+r*cos(72*PI/180);
    y2=100+r*sin(72*PI/180);
    x3=100+r*cos(144*PI/180);
    y3=100+r*sin(144*PI/180);
    x4=100+r*cos(216*PI/180);
    y4=100+r*sin(216*PI/180);
    x5=100+r*cos(288*PI/180);
    y5=100+r*sin(288*PI/180);
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x4,y4);
	line(x4,y4,x5,y5);
	line(x5,y5,x1,y1);
	//bresLine(200,200,250,200);
	//Scaling
	line(x1*s,y1*s,x2*s,y2*s);
	line(x2*s,y2*s,x3*s,y3*s);
	line(x3*s,y3*s,x4*s,y4*s);
	line(x4*s,y4*s,x5*s,y5*s);
	line(x5*s,y5*s,x1*s,y1*s);
	//Translation
    tx=20;
    ty=30;
	x1=100+r*cos(0*PI/180+an)+tx;
	y1=100+r*sin(0*PI/180+an)+ty;
    x2=100+r*cos(72*PI/180+an)+tx;
    y2=100+r*sin(72*PI/180+an)+ty;
    x3=100+r*cos(144*PI/180+an)+tx;
    y3=100+r*sin(144*PI/180+an)+ty;
    x4=100+r*cos(216*PI/180+an)+tx;
    y4=100+r*sin(216*PI/180+an)+ty;
    x5=100+r*cos(288*PI/180+an)+tx;
    y5=100+r*sin(288*PI/180+an)+ty;
    line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x4,y4);
	line(x4,y4,x5,y5);
	line(x5,y5,x1,y1);
	getch();
	closegraph();
	return 0;
}