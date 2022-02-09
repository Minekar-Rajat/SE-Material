//============================================================================
// Name        : Assignment3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class student
{
	float num[20];
	int n;

public:

	void insert()
	{
		cout<<"\n\tEnter the number of students\n\t";
		cin>>n;
		num[n];
		cout<<"\n\n\tEnter the percentage \n\t";
		for(int i=0;i<n;i++)
		{
			cout<<"\n";
			cin>>num[i];
		}
		cout<<"\n\tEntered array is : \n\n\t";
		for(int i=0;i<n;i++)
		{
		    cout<<num[i]<<"\t";
		}

	}

	void bubblesort()
	{
		float temp;
		for(int i=n-1;i>=1;i--)
		{
			for(int j=0;j<i;j++)
			{
				if(num[j]>num[j+1])
				{
					temp=num[j];
					num[j]=num[j+1];
					num[j+1]=temp;

				}
			}
		}

	}




	void selectionsort()
	{
		float temp;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(num[i]>num[j])
				{
					temp=num[j];
					num[j]=num[i];
					num[i]=temp;
				}
			}
		}


	}


	void display()
	{
		cout<<"\n\t";
		for(int i=0;i<n;i++)
		{
			cout<<num[i]<<"\t";
		}
	}

	void topfive()
	{
		cout<<"\n\tTop five students are : \n\t";
		for(int i=0;i<5;i++)
		{
			cout<<num[i]<<"\t";
		}
	}

};

int main()
{
	int ch;

	student s;
	s.insert();


	do
	{
		  cout<<"\n\n\t 0.exit             ";
	      cout<<"\n\t 1.Bubble sort        ";
		  cout<<"\n\t 2.Selection sort     ";
		  cout<<"\n\t 3.Display list       ";
		  cout<<"\n\t 4.Top Five           ";
		  cout<<"\n\n\t Enter your choice  ";
		  cin>>ch;

		  switch(ch)
		  {

			 case 1 :
					  s.bubblesort();
					  break;

			case 2 :
					  s.selectionsort();
					  break;

			case 3 :
					  s.display();
					  break;

			case 4 :
					  s.selectionsort();
				      s.topfive();
				      break;
		  }



	}while(ch!=0);





	return 0;
}
