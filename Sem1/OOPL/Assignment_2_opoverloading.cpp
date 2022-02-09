//============================================================================
// Name        : Assignment_2_opoverloading.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class complex
{
	float real,img;

public :

	friend istream & operator >>(istream&in,complex &obj);
	friend ostream & operator <<(ostream&out,complex &obj);

	complex()
		{
			real=0;
			img=0;
		}

	complex(float r,float i)
	{
		real=r;
		img=i;
	}

	complex operator+(complex &obj)
	{
		complex temp;
		temp.real=this->real+obj.real;
		temp.img=this->img+obj.img;

		return temp;

	}
	complex operator-(complex &obj)
		{
			complex temp;
			temp.real=this->real-obj.real;
			temp.img=this->img-obj.img;

			return temp;

		}

	complex operator*(complex &obj)
	{
		complex temp;
		temp.real=(this->real*obj.real)-(this->img*obj.img);
		temp.img=(this->img*obj.real)+(this->real*obj.img);
		return temp;

	}





};

ostream & operator <<(ostream&out,complex &obj)
	{
		//out<<"\n";
		if(obj.img<0)
		{
			out<<obj.real<<obj.img<<"i";

		}
		if(obj.img>=0)
		{
			out<<obj.real<<"+"<<obj.img<<"i";
		}

		return out;
	}

istream & operator >>(istream&in,complex &obj)
	{
		float r,i;
		cout<<"\n\tEnter the real part         :\t";
		in>>r;
		cout<<"\n\tEnter the imaginary part    :\t";
		in>>i;
		obj.real=r;
		obj.img=i;

		return in;
	}




int main()
{
	//complex out,in;
	complex c1,c2,ans;
	int ch;

	cout<<"\n\tEnter two complex numbers  :  \n\t";
	cin>>c1;
	cout<<"\n\t";
	cin>>c2;

		do
		{

			cout<<"\n\n\tEnter Operation to be performed  :";
			cout<<"\n\n\t  0.Exit                  ";
			cout<<"\n\t  1.Addition            ";
			cout<<"\n\t  2.Subtraction           ";
			cout<<"\n\t  3.Multiplication        ";
			cout<<"\n\t  4.Display both          ";
			cout<<"\n\n\t  Enter your choice     :";
			cin>>ch;

			switch(ch)
			{

			case 1:
				        ans=c1+c2;
				        cout<<"\n\t Addition is  : ";
				        cout<<ans;
				        cout<<"\n\t";
				        break;

			case 2:
						ans=c1-c2;
						cout<<"\n\t Subtraction is  : ";
						cout<<ans;
						cout<<"\n\t";
						break;

			case 3:
						ans=c1*c2;
						cout<<"\n\t Multiplication is  : ";
						cout<<ans;
						cout<<"\n\t";
						break;

			case 4:
				 	 	cout<<"\n\tComplex no is : "<<c1;
				        cout<<"\n\tComplex no is : "<<c2;
				        cout<<"\n\t";
				        break;






			}


		}
		while(ch!=0);

	return 0;
}

