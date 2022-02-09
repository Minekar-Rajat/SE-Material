//============================================================================
// Name        : Assignment_11_a.cpp
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
		 void binary(int);



};


void student::insert()
{


	int x;
	char str[100];
    cout<<"\n\n\t*****************************";
    cout<<"\n\t      Training Program       ";
    cout<<"\n\t-----------------------------";
    cout<<"\n\n\tAttendence :     ";



	for(int i=(-1);i<n;i++)
	{
		cout<<"\n\n\tEnter roll number ";
		cout<<"\n\tEnter 0 to stop \n\n\t";
		cin.getline(str,98);

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
		cout<<"\n\tStudent : "<<x<<" was not present";
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
	else
	{
		cout<<"\n\tStudent : "<<roll[i]<<" was not present";
	}





}

void student::display()
{
	cout<<"\n\n\tThe Sorted Attendance list is  :  ";
	for(int i=0;i<n;i++)
	{
		cout<<roll[i]<<"\t";
	}



}


void student::binary(int x)
{
		int low,up;
		low=0;
		up=n;
    	int mid;
    	int flag=0;
    	mid=(low+up)/2;

    	while(low<up)
    	{
    		if(roll[mid]==x)
    		{
    			flag=1;
    			break;
    		}
    		else if(x<roll[mid])
    		{
    			up=mid-1;
    		}
    		else
    		{
    			low=mid+1;
    		}
    	}
    	if(flag==1)
    	{
    		cout<<"\n\tStudent : "<<x<<" was present";
    	}
    	else
    	{
    		cout<<"\n\tStudent : "<<x<<" was not present";
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
				cout<<"\n\t 3.Binary search      ";
				cout<<"\n\t 4.Display sorted list";
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
					        cout<<"\n\tEnter roll no to search \n\t";
					        cin>>x;
					        s.bubblesort();
					        s.binary(x);
					        break;


				   case 4 :
					        s.bubblesort();
					        s.display();
					        break;

				}

	}while(ch!=0);


   return 0;
}
