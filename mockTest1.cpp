#include"mainwindow.h"
using namespace std;


void MainWindow::bresenham(int x1,int y1,int x2,int y2)
{
	int dx,dy,x,y,P,i=0;
	
	dx = abs(x2 - x1);
	dy = abs(y2 -y1);
	x = x1;
	y = y1;

	if(dx>=dy)
	{
		P = 2*(dy) - (dx);
		while(i<=dx)
		{
			img.setPixel(x,y,qRgb(255,255,255));
			if(P<0)
			{
				P = P + 2*dy;			
			}
			else
			{
				y = y + sign(y2 - y1);
				P = P + 2*(dy -dx);
			}
			x = x + sign(x2 -x1);
			i++;
		}	
	}
	else
	{
		P = 2*(dx) - (dy);
		while(i<=dy)
		{
			img.setPixel(x,y,qRgb(255,255,255));
			if()
			{
				P = P + 2*dx;
			}
			else
			{
				x = x + sign(x2 - x1);
				P = P + 2*(dx -dy);
			}
			y = y + sign(y2 -y1);
			i++;

		}


	}

}

int MainWindow::sign(int n)
{
	if(n<0)
	{	
		return -1;
	}
	else if(n>0)
	{
		 return 1;
	}
	else
	{
		return 0;
	}
}

void MainWindow::multiplication(int x,int y,float a1[][3],float a2[][3])
{
	float ans[x][3];
	
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<3;j++)
		{
			ans[i][j] = 0;
			for(int k=0;k<y;k++)
			{
				ans[i][j] = ans[i][j] + a1[i][k]*a2[k][j];
			}
		}
	}

	bresenham(ans[0][0],ans[0][1],ans[1][0],ans[1][1]);

}


void MainWindow::X_axis(float x1,float y1,float x2,float y2)
{
	float a1[2][3],a2[3][3];
	a1[0][0] = x1;
	a1[0][1] = y1;
	a1[0][2] = 1;
	a1[1][0] = x2;
	a1[1][1] = y2;
	a1[1][2] = 1;
	
	a2[0][0] = 1;
	a2[0][1] = 0;
	a2[0][2] = 0;
	a2[1][0] = 0;
	a2[1][1] = -1;
	a2[1][2] = 0;
	a2[2][0] = 0;
	a2[2][1] = 0;
	a2[2][2] = 1;
	
	multiplication(2,3,a1,a2);		

}


void MainWindow::Y_axis(float x1,float y1,float x2,float y2)
{
	float a1[2][3],a2[3][3];
	a1[0][0] = x1;
	a1[0][1] = y1;
	a1[0][2] = 1;
	a1[1][0] = x2;
	a1[1][1] = y2;
	a1[1][2] = 1;
	
	a2[0][0] = -1;
	a2[0][1] = 0;
	a2[0][2] = 0;
	a2[1][0] = 0;
	a2[1][1] = 1;
	a2[1][2] = 0;
	a2[2][0] = 0;
	a2[2][1] = 0;
	a2[2][2] = 1;
	
	multiplication(2,3,a1,a2);

}

void MainWindow::XY_axis(float x1,float y1,float x2,float y2)
{
	float a1[2][3],a2[3][3];
	a1[0][0] = x1;
	a1[0][1] = y1;
	a1[0][2] = 1;
	a1[1][0] = x2;
	a1[1][1] = y2;
	a1[1][2] = 1;
	
	a2[0][0] = 0;
	a2[0][1] = 1;
	a2[0][2] = 0;
	a2[1][0] = 1;
	a2[1][1] = 0;
	a2[1][2] = 0;
	a2[2][0] = 0;
	a2[2][1] = 0;
	a2[2][2] = 1;
	
	multiplication(2,3,a1,a2);
}

void MainWindow::rotate(float x1,float y1,float x2,float y2,float ax,float ay,float angle)
{
	float radian = angle/180*3.142;
	float a1[2][3],a2[3][3];
	
	a1[0][0] = x1;
	a1[0][1] = y1;
	a1[0][2] = 1;
	a1[1][0] = x2;
	a1[1][1] = y2;
	a1[1][2] = 1;
	
	a2[0][0] = 1;
	a2[0][1] = 0;
	a2[0][2] = 0;
	a2[1][0] = 0;
	a2[1][1] = 1;
	a2[1][2] = 0;
	a2[2][0] = -ax;
	a2[2][1] = -ay;
	a2[2][2] = 1;
	
	float ans[3][3] ;

	ans[0][0] = cos(radian);
	ans[0][1] = sin(radian);
	ans[0][2] = 0;
	ans[1][0] = -sin(radian);
	ans[1][1] = cos(radian);
	ans[1][2] = 0;
	ans[2][0] = 0;
	ans[2][1] = 0;
	ans[2][2] = 1;

	float a3[3][3];
	
	a3[0][0] = 1;
	a3[0][1] = 0;
	a3[0][2] = 0;
	a3[1][0] = 0;
	a3[1][1] = 1;
	a3[1][2] = 0;
	a3[2][0] = ax;
	a3[2][1] = ay;
	a3[2][2] = 1;

	multiply(a1,a2,ans,a3);

}


void MainWindow::multiply(float a1[][3],float a2[][3],float ans[][3],float a3[][3])
{
	float p[2][3],q[2][3],r[2][3];

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			p[i][j] = 0;
			for(int k=0;k<3;k++)
			{
				p[i][j] = p[i][j] + a1[i][k]*a2[k][j];
			}
		} 
	}

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			q[i][j] = 0;
			for(int k=0;k<3;k++)
			{
				q[i][j] = q[i][j] + p[i][k]*ans[k][j];
			}
		} 
	}

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			r[i][j] = 0;
			for(int k=0;k<3;k++)
			{
				r[i][j] = r[i][j] + q[i][k]*a3[k][j];
			}
		} 
	}

	bresenham(r[0][0],r[0][1],r[1][0],r[1][1]);
	

} 




