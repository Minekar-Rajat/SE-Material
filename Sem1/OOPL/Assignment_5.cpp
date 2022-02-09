//============================================================================
// Name        : Assignment_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	double no1,no2,ans;
	int ch;
	cout<<"\n\t* * * * * Calculator * * * * * \n\n\t";

	do
	{

		cout<<"\n\n\t  0.Exit            ";
		cout<<"\n\t  1.Addition          ";
		cout<<"\n\t  2.Subtraction       ";
		cout<<"\n\t  3.Multiplication    ";
		cout<<"\n\t  4.Division          ";
		cout<<"\n\n\t  Enter your choice ";
		cin>>ch;

		switch(ch)
		{

		case 1:
				cout<<"\n\t  Enter two numbers\n\t";
				cin>>no1;
				cout<<"\n\t";
				cin>>no2;
				ans=no1+no2;
				cout<<"\n\t Addition is  : "<<ans;
				break;

		case 2:
					cout<<"\n\t  Enter two numbers\n\t";
					cin>>no1;
					cout<<"\n\t";
					cin>>no2;
					ans=no1-no2;
					cout<<"\n\t Subtraction is  : "<<ans;
					break;

		case 3:
					cout<<"\n\t  Enter two numbers\n\t";
					cin>>no1;
					cout<<"\n\t";
					cin>>no2;
					ans=no1*no2;
					cout<<"\n\t Multiplication is  : "<<ans;
					break;

		case 4:
					cout<<"\n\t  Enter two numbers\n\t";
					cin>>no1;
					cout<<"\n\t";
					cin>>no2;
					try
					{
						if(no2==0)
						{
							throw no2;
						}
						else
						{
							ans=no1/no2;
							cout<<"\n\t Division is  : "<<ans;
						}
					}
					catch(...)
					{
						cout<<"\n\tCan't Divide with zero 0 ";
					}
					
					break;

		default :
			       if(ch!=0)
			       {
			    	   cout<<"\n\t Wrong input ";
			       }

		}


	}
	while(ch!=0);


	cout<<"\n\n\t";


	return 0;
}
