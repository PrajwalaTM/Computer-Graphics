/*Program for clipping a given line against a given rectangular window
Liang Barsky method.*/

#include <stdio.h>
#include <graphics.h>
#include <math.h>

double edgeLeft=200,edgeRight=500,edgeTop=100,edgeBottom=300;
double x0clip,y0clip,x1clip,y1clip;

int LiangBarsky (double x0, double y0, double x1, double y1)         
{
    
    double t0 = 0.0;    
    double t1 = 1.0;
    double xdelta = x1-x0;
    double ydelta = y1-y0;
    double p,q,r;

    for(int edge=0; edge<4; edge++) {   
        if (edge==0) {  p = -xdelta;    q = -(edgeLeft-x0);  }
        if (edge==1) {  p = xdelta;     q =  (edgeRight-x0); }
        if (edge==2) {  p = -ydelta;    q = (edgeBottom-y0);}
        if (edge==3) {  p = ydelta;     q =  -(edgeTop-y0);   }   
        r = q/p;
        if(p==0 && q<0) return 0;   

        if(p<0) {
            if(r>t1) return 0;         
            else if(r>t0) t0=r;           
        } else if(p>0) {
            if(r<t0) return 0;     
            else if(r<t1) t1=r;         
        }
    }

    x0clip = x0 + t0*xdelta;
    y0clip = y0 + t0*ydelta;
    x1clip = x0 + t1*xdelta;
    y1clip = y0 + t1*ydelta;

    return 1;
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
	rectangle(edgeLeft,edgeTop,edgeRight,edgeBottom);
	line(x0,y0,x1,y1);
	getch();
	int res=LiangBarsky(x0,y0,x1,y1);
	cleardevice();
	rectangle(edgeLeft,edgeTop,edgeRight,edgeBottom);
	if(res)
		line(x0clip,y0clip,x1clip,y1clip);
	getch();
	closegraph();
	return 0;
}        
