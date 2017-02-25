/*Program for clipping a given line against a given rectangular window
using Cohen Sutherland method */
#include <stdio.h>
#include <graphics.h>
#include <math.h>
#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

float xmin=200,xmax=500,ymin=300,ymax=100;

int ComputeCode(float x,float y)
{
	int code;
	code = INSIDE;

	if(x<xmin)
		code=code | LEFT;
	else if(x>xmax)
		code=code | RIGHT;
	if(y>ymin)
		code=code | BOTTOM;
	else if(y<ymax)
		code=code | TOP;

	return code;
}

void CohenSuther(float x0,float y0,float x1,float y1)
{
	int code0 = ComputeCode(x0,y0);
	int code1 = ComputeCode(x1,y1);
	int accept=0;

	while(1)
	{
		if(!(code0 | code1))
		{
			accept=1;
			break;			
		}
		else if (code0 & code1)
		{
			accept=2;
			break;
		}
		else
		{
			float x,y;
			int codeOut = code0 ? code0 : code1;
			if (codeOut & TOP) {           // point is above the clip rectangle
				x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
				y = ymax;
			} else if (codeOut & BOTTOM) { // point is below the clip rectangle
				x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
				y = ymin;
			} else if (codeOut & RIGHT) {  // point is to the right of clip rectangle
				y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
				x = xmax;
			} else if (codeOut & LEFT) {   // point is to the left of clip rectangle
				y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
				x = xmin;
			}

			if (codeOut == code0) {
				x0 = x;
				y0 = y;
				code0 = ComputeCode(x0, y0);
			} else {
				x1 = x;
				y1 = y;
				code1 = ComputeCode(x1, y1);
			}
		}
		
	}
	
	if(accept==1)
	{
		cleardevice();
		rectangle(xmin,ymax,xmax,ymin);
		line(x0,y0,x1,y1);
	}
	else if(accept==2)
	{
		cleardevice();
		rectangle(xmin,ymax,xmax,ymin);
	}
}

int main()
{
	float x0,y0,x1,y1;
	printf("Enter the co-ordinates of the line\n");
	scanf("%f",&x0);
	scanf("%f",&y0);
	scanf("%f",&x1);
	scanf("%f",&y1);
	int gd=DETECT,gm=0;
	initgraph(&gd,&gm,"");
	rectangle(xmin,ymax,xmax,ymin);
	line(x0,y0,x1,y1);
	//rectangle(200,100,500,300);
	//line(x0,y0,x1,y1);
	getch();
	CohenSuther(x0,y0,x1,y1);
	getch();
	closegraph();

}
