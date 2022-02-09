//============================================================================
// Name        : Assignment_02.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class complex
{
	int real,img;

public :

	complex()
		{
			real=0;
			img=0;
		}

	complex(int r=0,int i=0)
	{
		real=r;
		img=i;
	}

	complex operator+(&complex obj)
	{
		complex temp;
		temp.real=this->real+obj.real;
		temp.img=this->img+obj.img;

		return temp;

	}

	void operator<<(&complex p)
	{
		if(img<0)
		{
			cout<<"\n\tComplex no is : "<<real<<img<<"i";

		}
		if(img>0)
		{
			cout<<"\n\tComplex no is : "<<real<<"+"<<img<<"i";
		}
	}



};



int main()
{
	complex c1(5,3);
	cout<<c1;





	return 0;
}
