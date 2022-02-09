//============================================================================
// Name        : assignment_quad.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================




#include<iostream>
#include<math.h>
using namespace std;

class quadratic
{
	float a,b,c;
	//float x;

	public:

	friend istream & operator >>(istream&in,quadratic &obj);
	friend ostream & operator <<(ostream&out,quadratic &obj);

	quadratic()
	{
			a=b=c=0;
	}
	quadratic(float x,float y,float z)
	{
		a=x;
		b=y;
		c=z;
	}


	quadratic operator+(quadratic &obj)
	{
		quadratic temp;
		temp.a=this->a+obj.a;
		temp.b=this->b+obj.b;
		temp.c=this->c+obj.c;

		return temp;
	}


	float eval(float var)
	{
		float y;
		y=(a*var*var)+(b*var)+c;

		return y;
	}



	void solution()
	{
		float var,sol;
		int count=0;
		var=((b*b)-(4*a*c));
		if(var<0)
		{
			cout<<"\n\tNo Solution Exist";
		}
		else if(var==0)
		{
			sol=-b;
			sol/=(2*a);
			cout<<"\n\tOnly one Solution Exist\n";
			cout<<"\n\tSolution is : "<<sol;
		}
		else if(var>0)
		{
			var=sqrt(var);
			sol=(-b)+var;
			sol=sol/(2*a);
			cout<<"\n\n\tSolution is :	"<<sol;
			sol=(-b)-var;
			sol=sol/(2*a);
			cout<<"\n\n\tSolution is :	"<<sol;
		}
		else
		{
			cout<<"\n\tSomething Went Wrong";
		}







//		for(int i=0;i<1000000 ;i++)
//		{
//
//			var=(obj.a*(i*i))+(obj.b*i)+obj.c;
//			if(var==0)
//			{
//					cout<<"\n\tSolution is : "<<i;
//					count++;
//			}
//			if(count>2)
//			{
//				break;
//			}
//
//		}
	}

	void sol()
	{
		float var;
		int count=0;
		for(int i=0;i<1000000 ;i++)
		{

			var=(a*(i*i))+(b*i)+c;
			if(var==0)
			{
					cout<<"\n\tSolution is : "<<i;
					count++;
			}
			if(count>2)
			{
				break;
			}

		}

	}



};


ostream & operator <<(ostream&out,quadratic &obj)
{
	if(obj.b>=0)
	{
		if(obj.c>=0)
		{
			out<<obj.a<<"x^2"<<"+"<<obj.b<<"x"<<"+"<<obj.c;
		}
		else
		{
			out<<obj.a<<"x^2"<<"+"<<obj.b<<"x"<<obj.c;
		}
	}
	else
	{
		if(obj.c>=0)
		{
			out<<obj.a<<"x^2"<<obj.b<<"x"<<"+"<<obj.c;
		}
		else
		{
			out<<obj.a<<"x^2"<<obj.b<<"x"<<obj.c;
		}
	}

	return out;

}


istream & operator >>(istream&in,quadratic &obj)
{
		cout<<"\n\t";
		cin>>obj.a;


		cout<<"\n\t";
		cin>>obj.b;

		cout<<"\n\t";
		cin>>obj.c;

		if(obj.a==0)
		{
			cout<<"\n\tIt is not a quadratic Expression \n\t";
		}

		return in;
}




int main()
{
	int ch;
	float y,n;
	quadratic q1,q2,ans;



	do
	{

		cout<<"\n\t";
		cout<<"\n\t 0.Exit \
		\n\t 1.Addition \
		\n\t 2.Solution of expression \
		\n\t 3.Value for given x ";
		cout<<"\n\n\tEnter your Choice \n\t";
		cin>>ch;


		switch(ch)
		{
			case 1 :
				cout<<"\n\tEnter the coefficients for 1st quadratic equation";
				cin>>q1;
				cout<<"\n\tQuadratic Equation is :";
				cout<<q1;
				cout<<"\n\n\tEnter the coefficients for 2nd quadratic equation";
				cin>>q2;
				cout<<"\n\tQuadratic Equation is :";
				cout<<q2;
	
				ans=q1+q2;
				cout<<"\n\tAddition is  :  "<<ans;
				break;

			case 2 :
				cout<<"\n\tEnter the coefficients for 1st quadratic equation";
				cin>>q1;
				q1.solution();
				break;

			case 3 :
				cout<<"\n\tEnter the coefficients for quadratic equation";
				cin>>q1;
				cout<<"\n\tEnter number for which value is to be determined : \n\t";
				cin>>n;
				y=q1.eval(n);
				cout<<"\n\tValue for given no is  :  "<<y;
				break;
	
			default :
				cout<<"\n\t\tExit";

		}
	}
	while(ch!=0);


	return 0;
}







