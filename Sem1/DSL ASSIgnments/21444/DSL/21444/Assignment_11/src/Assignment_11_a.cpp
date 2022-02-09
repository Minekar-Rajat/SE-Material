//============================================================================
// Name        : assignment4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class student
{

	int roll[20];
	int n=0;

public :
		 void insert();
	 	 void display();
		 void linear(int);
		 void sentinal(int);
		 void bubblesort();



};


void student::insert()
{

	int x;
    cout<<"\n\n\t*****************************";
    cout<<"\n\t      Training Program       ";
    cout<<"\n\t-----------------------------";
    cout<<"\n\n\tAttendence :     ";

    cout<<"\n\n\tEnter roll numbers ";
    cout<<"\n\tEnter 0 to stop \n\n\t";

	for(int i=(-1);i<n;i++)
	{
		cout<<"\n\t";
		cin>>x;
		if(x!=0)
		{
		   roll[i+1]=x;
		   n++;
		}
		else
		{
			break;
		}
	}



}


void student::bubblesort()
{
	int temp;
	for(int i=n-1;i>=1;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(roll[j]>roll[j+1])
            {
            	temp=roll[j];
            	roll[j]=roll[j+1];
            	roll[j+1]=temp;

            }
		}
    }

}

void student::linear(int x)
{
	int i=0;
	while(i<n && roll[i]<x)
	{
		i++;
	}
	if(roll[i]==x)
	{
		cout<<"\n\tStudent : "<<roll[i]<<" was present";
	}
	else
	{
		cout<<"\n\tThis student was not present";
	}




}

void student::sentinal(int x)
{
	int i=0;
	roll[n]=x;
	while(i<n &&roll[i]<x)
	{
		i++;
	}
	if(roll[i]==x)
	{
		cout<<"\n\tStudent : "<<roll[i]<<" was present";
	}
	if(roll[i+1]==x)
	{
		cout<<"\n\tThis student was not present";
	}





}

void student::display()
{
	cout<<"\n\n\tThe Sorted List is  :  ";
	for(int i=0;i<n;i++)
	{
		cout<<roll[i]<<"\t";
	}



}



int main()
{
	int ch;
	int x;

	student s;
	s.insert();


	do
	{
				cout<<"\n\n\t 0.exit             ";
				cout<<"\n\t 1.Linear search      ";
				cout<<"\n\t 2.Sentinel search    ";
				cout<<"\n\t 3.Display list       ";
				cout<<"\n\n\t Enter your choice  ";
				cin>>ch;

				switch(ch)
				{

				   case 1 :
					        cout<<"\n\tEnter roll no to search \n\t";
					        cin>>x;
					        s.bubblesort();
					        s.linear(x);
					        break;

				   case 2 :
					        cout<<"\n\tEnter roll no to search \n\t";
					   		cin>>x;
					   		s.bubblesort();
					        s.sentinal(x);
					        break;

				   case 3 :
					        s.display();
					        break;

				}

	}while(ch!=0);


   return 0;
}
