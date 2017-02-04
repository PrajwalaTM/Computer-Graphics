//Program to draw a stick man riding a cycle using basic 2D transformations such as 
//translation, rotation and scaling.
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

void semipixel(int xc, int yc, int x, int y,int color)
{
	putpixel(xc+x,yc+y,color);
	putpixel(xc+y,yc+x,color);
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

void drawsemicircle(int xc,int yc,int r, int color)
{
	int x = 0;
    int y = r;
    int p = 1-r;
    semipixel(xc,yc,x,y,color);
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
        semipixel(xc,yc,x,y,color);
    }
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


void drawcycle(int i,int s)
{
    //The cycle wheels
    drawcircle(200+i,300,50,WHITE);
    drawcircle(500+i,300,50,WHITE);
    //The spokes of wheel1
    //bresLine(200+i,250,200+i,350);    
    //int p=(i*10)/60,j;
    //for (j =p ; j <= 360 ; j=j+60)
    //{
    //a=a*cos(PI/3)-b*sin(PI/3);
    //b=a*sin(PI/3)+b*cos(PI/3);
    //c=c*cos(PI/3)-d*sin(PI/3);
    //d=c*sin(PI/3)+d*cos(PI/3);
    //a=a+1;
    //c=c+1;
    //line(a,b,c,d);

    //line((200)*cos(PI/3)+i-300*sin(PI/3),(200)*sin(PI/3)+i+300*cos(PI/3),(200+50*sin(PI/3))*cos(PI/3)+i-(300-50*cos(PI/3))*sin(PI/3),(300-50*cos(PI/3))*cos(PI/3)+(200+50*sin(PI/3))*sin(PI/3)+i);
    //bresLine(200+i,300,200+i-50*sin(j*PI/4),300+50*cos(j*PI/4));
    //bresLine(200+i,300,200+i-50*sin(j*PI/4),300-50*cos(j*PI/4));
    //bresLine(200+i,300,200+i+50*sin(j*PI/4),300+50*cos(j*PI/4));
    
    //cleardevice();
    //}
    //bresLine(150+i,300,250+i,300);
    int p=(i*10)%60,j;
    for(j=p;j<=360;j+=60)
    {
        line(200+50*cos(j*PI/180)+i,300+50*sin(j*PI/180),200-50*cos(j*PI/180)+i,300-50*sin(j*PI/180));
    }
    //small circle wheel1
    drawcircle(200+i,300,10,WHITE);
    //pedal circle
    drawcircle(350+i,300,20,WHITE);
    bresLine(350+i,250,350+i,350);
    bresLine(320+i,250,350+i,250);
    bresLine(350+i,350,380+i,350);
    //The spokes of wheel2
    //bresLine(500+i,250,500+i,350);
    //bresLine(500+i,300,500+i+50*sin(PI/4),300-50*cos(PI/4));
    //bresLine(500+i,300,500+i-50*sin(PI/4),300+50*cos(PI/4));
    //bresLine(500+i,300,500+i-50*sin(PI/4),300-50*cos(PI/4));
    //bresLine(500+i,300,500+i+50*sin(PI/4),300+50*cos(PI/4));
    //bresLine(450+i,300,550+i,300);
    for(j=p;j<=360;j+=60)
    {
        line(500+50*cos(j*PI/180)+i,300+50*sin(j*PI/180),500-50*cos(j*PI/180)+i,300-50*sin(j*PI/180));
    }
    //cycle chain
    bresLine(200+i,300,350+i,300);
    line(200+i,290,350+i,280);
    bresLine(200+i,310,350+i,320);
    //cycle handle
    bresLine(500+i-150*sin(PI/18),300-150*cos(PI/18),500+i,300);
    drawsemicircle(475+i-150*sin(PI/18),300-150*cos(PI/18),25,WHITE);
    //triangle
    line(350+i,300,500+i-75*sin(PI/18),300-75*cos(PI/18));
    line(200+i,300,200+i+75*sin(PI/18),300-75*cos(PI/18));
    line(200+i+75*sin(PI/18),300-75*cos(PI/18),500+i-75*sin(PI/18),300-75*cos(PI/18));
    line(200+i+75*sin(PI/18),300-75*cos(PI/18),350+i,300);
    int x=200+75*sin(PI/18);
    int y=300-75*cos(PI/18);
    //stickman on cycle
    //setcolor(4);
    line((x+i)*s,y*s,((x)+i+120*sin(PI/6))*s,((y)-120*cos(PI/6))*s);
    drawcircle(((x)+i+160*sin(PI/6))*s,((y)-160*cos(PI/6))*s,40,WHITE);
    line((x+i+50*sin(PI/6))*s,(y-50*cos(PI/6))*s,(480+i-150*sin(PI/18))*s,(320-150*cos(PI/18))*s);
    line((x+i+50*sin(PI/6))*s,(y-50*cos(PI/6))*s,(480+i-150*sin(PI/18))*s,(280-150*cos(PI/18))*s);
    line((x+i)*s,y*s,(340+i)*s,250*s);
    line((x+i)*s,y*s,(360+i)*s,350*s);

}

int main() {
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int i,dist=50,s=1;
    for (i = 0; i <= dist; ++i)
    {
        drawcycle(i,s);
        if(i!=dist)
        cleardevice();
        delay(10);   
    }
	getch();
	closegraph();
	return 0;
}