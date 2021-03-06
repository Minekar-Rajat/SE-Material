

//============================================================================
// Name        : Assignment_13.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class student
{
	float marks[100];
	int n;

	public :
	  int insert();
	  int parts(int low,int up);
	  void quicksort(int low,int up);
	  void display();

};

int student::insert()
{
	cout<<"\n\tEnter no of students";
	cin>>n;
	//marks[n];
	cout<<"\n\tEnter percentage\n\t";
	for(int i=0;i<n;i++)
	{
		cin>>marks[i];
		cout<<"\n\t";
	}
	cout<<"\n\tEntered data is : \n\t";
	for(int i=0;i<n;i++)
	{
		cout<<marks[i]<<"  ";
	}
	return n;
}

void student::quicksort(int low,int up)
{
	int k;

	if(low<up)
	{
		k=this->parts(low,up);
		this->quicksort(low,k-1);
		this->quicksort(k+1,up);
	}
}

int student::parts(int low,int up)
{
	float pivot,temp;
	int p,q;
	pivot=marks[low];
	p=low+1;
	q=up;

	do
	{
		while(marks[p]<pivot && p<n)
		{
			p++;
		}
		while(marks[q]>pivot)
		{
			q--;
		}
		if(p<q)
		{
			temp=marks[q];
			marks[q]=marks[p];
			marks[p]=temp;
		}
	}while(p<q);
	temp=marks[q];
	marks[q]=marks[low];
	marks[low]=temp;

	return q;
}

void student::display()
{

	cout<<"\n\n\tSorted data is : \n\n\t";
	for(int i=0;i<n;i++)
	{
		cout<<marks[i]<<"\t";
	}
}


int main()
{
	int n;
	student s;
	n=s.insert();
	s.quicksort(0,n-1);

	s.display();

	return 0;

}
