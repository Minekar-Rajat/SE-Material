#include<iostream>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
using namespace std;

void dda(float x1,float y1,float x2,float y2);

int main()
{
	float x1,y1,x2,y2;
	int gd=DELETE,gm;
	initgraph(&gd,&gm,"c:\\tcplus\\bgi");
	cleardevice();
	
	cout<<"\n\n\t======== DDA Line Algorithm ==========";
	cout<<"\n\n\tEnter 1st Point ";
	cout<<"\n\n\tX1	:	";
	cin>>x1;
	cout<<"\n\n\tY1	:	";
	cin>>y1;
	cout<<"\n\n\tEnter 2nd Point ";
	cout<<"\n\n\tX2	:	";
	cin>>x2;
	cout<<"\n\n\tY2	:	";
	cin>>y2;
	dda(x1,y1,x2,y2);
	cout<<"\n\n\tThank You-----";
	getch();
	closegraph();	


return 0;	
}


void dda(float x1,float y1,float x2,float y2)
{
	
	float dx,dy,steps,xinc,yinc,x,y;
	int i;
	
	dx = x2 - x1;
	dy = y2 - y1;
	
	if(abs(dx)>=abs(dy))
	{
		steps = dx;
	}
	else
	{
		steps = dy;
	}
	
	xinc = dx/steps;
	yinc = dy/steps;
	
	x=x1;
	y=y1;
	
	putpixel(x,y,WHITE);
	
	for(i = 1;i<steps;i++)
	{
		
		x = x + xinc;
		y = y + yinc;
		
		putpixel(x,y,WHITE);
		
	}
	
}


