/* Program to perform reflection and shear on a 3D house */
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#define PI 3.14159

void reflect(int x1,int y1,int x2,int y2, int choice)
{
   
   if(choice==1)
   {
       //Reflection about y=310
    line(130,310,270,310);
    line(x1,620-y1,x2,620-y2);
   }
   else if(choice==2)
   {
       //Reflection about x=350
      line(350,120,350,400); 
     line(700-x1,y1,700-x2,y2);   
   }
}

void shear(int x1,int y1,int x2,int y2,int choice,float angle)
{
 if(choice==1)
   {
      //X shear
    line(x1+tan(angle)*(y1),y1,x2+tan(angle)*(y2),y2);
   }
   else if(choice==2)
   {
       //Y shear
      line(x1,y1-tan(angle)*x1,x2,y2-tan(angle)*x2);
     //line(600-x1,y1,600-x2,y2);   
   }  
}


int main() {
	int gd=DETECT,gm,choice,angle;
	//initgraph(&gd,&gm,NULL);
  printf("Enter the axis 1.X axis 2.Y axis");
   scanf("%d",&choice);
   printf("Enter the angle of shear in degrees\n");
   scanf("%d",&angle);
  initgraph(&gd, &gm, "X:\\TC\\BGI");
	float x[8],y[8],a,b,d,p,rx,ry;
  d=100;int i;
  p=d/1.414;

  if(choice==1){
  	a=100;b=285;
  }
  else
  {
  	a=100;b=400;
  }
  x[0]=a;
  y[0]=b;
  x[1]=d+a;
  y[1]=0+b;
  x[2]=0+a;
  y[2]=b-d;
  x[3]=d+a;
  y[3]=b-d;
  x[4]=p+a;
  y[4]=b-p;
  x[5]=d+p+a;
  y[5]=b-p;
  x[6]=p+a;
  y[6]=b-p-d;
  x[7]=d+p+a;
  y[7]=b-p-d;
  
  //Cube
  line(x[0],y[0],x[1],y[1]);
  line(x[1],y[1],x[3],y[3]);
  line(x[2],y[2],x[3],y[3]);
  line(x[2],y[2],x[6],y[6]); 
  line(x[6],y[6],x[7],y[7]);
  line(x[3],y[3],x[7],y[7]);
  line(x[5],y[5],x[7],y[7]);
  line(x[1],y[1],x[5],y[5]);
  line(x[0],y[0],x[2],y[2]); 
  line(x[4],y[4],x[5],y[5]);
  line(x[4],y[4],x[6],y[6]);
  line(x[0],y[0],x[4],y[4]);   
  
  //Rooftop
  //rx=p+a+10;ry=30;
  //line(rx,ry,x[2],y[2]);
  //line(rx,ry,x[3],y[3]);
  //line(rx,ry,x[7],y[7]);
  //line(rx,ry,x[6],y[6]);
  float rx1=a+d*cos(PI/3),ry1=b-d-d*sin(PI/3),rx2,ry2;
  rx2=p+a+d*cos(PI/3);ry2=b-d-p-d*sin(PI/3);
 line(rx1,ry1,x[2],y[2]);
  line(rx1,ry1,x[3],y[3]);
  line(rx2,ry2,x[7],y[7]);
  line(rx2,ry2,x[6],y[6]);
  line(rx1,ry1,rx2,ry2);
  
  //reflection 
  reflect(x[0],y[0],x[1],y[1],choice);
  reflect(x[1],y[1],x[3],y[3],choice);
  reflect(x[2],y[2],x[3],y[3],choice);
  reflect(x[2],y[2],x[6],y[6],choice); 
  reflect(x[6],y[6],x[7],y[7],choice);
  reflect(x[3],y[3],x[7],y[7],choice);
  reflect(x[5],y[5],x[7],y[7],choice);
  reflect(x[1],y[1],x[5],y[5],choice);
  reflect(x[0],y[0],x[2],y[2],choice); 
  reflect(x[4],y[4],x[5],y[5],choice);
  reflect(x[4],y[4],x[6],y[6],choice);
  reflect(x[0],y[0],x[4],y[4],choice); 

  reflect(rx1,ry1,x[2],y[2],choice);
  reflect(rx1,ry1,x[3],y[3],choice);
  reflect(rx2,ry2,x[7],y[7],choice);
  reflect(rx2,ry2,x[6],y[6],choice);
  reflect(rx1,ry1,rx2,ry2,choice); 
  getch(); 
  cleardevice();
  //shear
  float rad=(PI/180)*angle;
 shear(x[0],y[0],x[1],y[1],choice,rad);
  shear(x[1],y[1],x[3],y[3],choice,rad);
  shear(x[2],y[2],x[3],y[3],choice,rad);
  shear(x[2],y[2],x[6],y[6],choice,rad); 
  shear(x[6],y[6],x[7],y[7],choice,rad);
  shear(x[3],y[3],x[7],y[7],choice,rad);
  shear(x[3],y[3],x[7],y[7],choice,rad);
  shear(x[5],y[5],x[7],y[7],choice,rad);
  shear(x[1],y[1],x[5],y[5],choice,rad);
  shear(x[0],y[0],x[2],y[2],choice,rad); 
  shear(x[4],y[4],x[5],y[5],choice,rad);
  shear(x[4],y[4],x[6],y[6],choice,rad);
  shear(x[0],y[0],x[4],y[4],choice,rad); 

  shear(rx1,ry1,x[2],y[2],choice,rad);
  shear(rx1,ry1,x[3],y[3],choice,rad);
  shear(rx2,ry2,x[7],y[7],choice,rad);
  shear(rx2,ry2,x[6],y[6],choice,rad);
  shear(rx1,ry1,rx2,ry2,choice,rad); 
  getch();
  closegraph();
  return 0;
}
