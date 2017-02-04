// Program to perform 2D transformations- reflection and shear for a house 

#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define PI 3.142
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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
       //Reflection about x=300
      line(300,120,300,400); 
     line(600-x1,y1,600-x2,y2);   
   }
}

void shear(int x1,int y1,int x2,int y2,int choice)
{
 if(choice==1)
   {
      //X shear
    line(x1+tan(PI/6)*(y1),y1,x2+tan(PI/6)*(y2),y2);
   }
   else if(choice==2)
   {
       //Y shear
      line(x1,y1-tan(PI/6)*x1,x2,y2-tan(PI/6)*x2);
     line(600-x1,y1,600-x2,y2);   
   }  
}


int main() {
   int gd = DETECT, gm,choice;
   printf("Enter the axis 1.X axis 2.Y axis");
   scanf("%d",&choice);
   initgraph(&gd, &gm, "X:\\TC\\BGI");
   
   //Draw the house
   bresLine(150,200,250,200);
   bresLine(150,200,150,300);
   bresLine(150,300,250,300);
   bresLine(250,200,250,300); 
   line(200,150,150,200);
   line(200,150,250,200);
   line(190,300,190,260);
   line(210,260,190,260);
   line(210,260,210,300);
   line(160,230,160,250);
   line(160,250,180,250);
   line(160,230,180,230);
   line(180,230,180,250);
   line(220,230,240,230);
   line(240,230,240,250);
   line(240,250,220,250);
   line(220,250,220,230);

  //Reflection about the chosen axis
   reflect(150,200,250,200,choice);
   reflect(150,200,150,300,choice);
   reflect(150,300,250,300,choice);
   reflect(250,200,250,300,choice); 
   reflect(200,150,150,200,choice);
   reflect(200,150,250,200,choice);
   reflect(190,300,190,260,choice);
   reflect(210,260,190,260,choice);
   reflect(210,260,210,300,choice);
   reflect(160,230,160,250,choice);
   reflect(160,250,180,250,choice);
   reflect(160,230,180,230,choice);
   reflect(180,230,180,250,choice);
   reflect(220,230,240,230,choice);
   reflect(240,230,240,250,choice);
   reflect(240,250,220,250,choice);
   reflect(220,250,220,230,choice);
   
  //Shear about the chosen axis
   shear(150,200,250,200,choice);
   shear(150,200,150,300,choice);
   shear(150,300,250,300,choice);
   shear(250,200,250,300,choice); 
   shear(200,150,150,200,choice);
   shear(200,150,250,200,choice);
   shear(190,300,190,260,choice);
   shear(210,260,190,260,choice);
   shear(210,260,210,300,choice);
   shear(160,230,160,250,choice);
   shear(160,250,180,250,choice);
   shear(160,230,180,230,choice);
   shear(180,230,180,250,choice);
   shear(220,230,240,230,choice);
   shear(240,230,240,250,choice);
   shear(240,250,220,250,choice);
   shear(220,250,220,230,choice);

   getch();
   closegraph();
   return 0;
}