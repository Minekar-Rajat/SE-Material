//============================================================================
// Name        : Ass3_Poly.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*Write a C++ program to realize polynomial equation and perform operations. Write function
To input &output polynomials represented as bmxem+ bm-1xem-1 +….. +b0xe0.  Your functions should overload the << and >> operators.
Evaluates a polynomial at given value of x
Add two polynomials.
Multiplies two polynomials.*/

#include <iostream>
using namespace std;

class term
{
	int exp;
	float coef;

public :
	term(float coef,int exp)
	{
		this->coef=coef;
		this->exp=exp;

	}
	friend class poly;

};


class poly
{
	int nterms;
	int capacity;
	term *terms;
public:
	poly()
	{
		nterms=0;
		terms=new term[10];
		capacity=10;
	}
	poly(int capacity)
	{
		nterms=0;
		terms=new term[capacity];
		this->capacity=capacity;
	}
	void read();
	void display();
	void newterm(float ,int );
	poly add(poly );
	poly multi(poly );
	float evaluate(float );


};

void poly::newterm(float coef,int exp)
{
	if(nterms==capacity)
	{
		cout<<"\n\n\tCapacity Exceed";
		capacity=capacity *2;
		term *temp=new term[capacity];
		//copy(terms,terms+nterms,temp)

	}
}



int main()
{

	return 0;
}
