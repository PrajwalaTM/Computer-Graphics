//Program to generate a curve through N+1 control points using Bezier or B Spline Curve.

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

void draw_beizer_curve(int x[],int y[],int n)
{
	int fact[n+1],i;
	fact[0]=1;
	for(i=1;i<=n;i++)
		fact[i]=i*fact[i-1];
	double x1,y1;
	double t;
	for (t = 0.0; t < 1.0; t += 0.0005)
	{
		x1=0;y1=0;
		for(i=0;i<=n;i++)
		{
			x1=x1+(fact[n]/(fact[n-i]*fact[i]))*(pow(t,i))*pow(1-t,n-i)*x[i];
			y1=y1+(fact[n]/(fact[n-i]*fact[i]))*(pow(t,i))*pow(1-t,n-i)*y[i];
		}
		putpixel((int)x1,(int)y1,WHITE);
	}
}
int main()
{
	int gd = DETECT, gm,n;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	int x[n],y[n],i;
	printf("Enter the x and y co-ordinates of the control points\n");
	for(i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
	initgraph (&gd, &gm, NULL);
	draw_beizer_curve(x,y,n);
	getch();
	closegraph();
	return 0;
}
