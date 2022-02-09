`//============================================================================
// Name        : assignment_student.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;




class student
{
	char name[20];
	char roll[10];
	char div[10];
	char dob[20];
	char blood[10];
	char address[100];
	char mobile[12];
	char licence[20];
	char var;

public :

	friend void Delete(student *,int ,int );
	int display()
	{

		cout<<"\n\n\tName        :  "<<name;
		cout<<"\n\n\tRoll no     :  "<<roll;
		cout<<"\n\n\tDivision    :  "<<div;
		cout<<"\n\n\tDOB         :  "<<dob;
		cout<<"\n\n\tBlood group :  "<<blood;
		cout<<"\n\n\tAddress     :  "<<address;
		cout<<"\n\n\tMobile no   :  "<<mobile;
		cout<<"\n\n\tLicence no  :  "<<licence;

		return 1;
	}

	int getdata()
	{
		int i=0;
		cin.ignore(1);
		cout<<"\n\tEnter name              :  ";
		cin.getline(name,19);
		cout<<"\n\n\tEnter Roll number       :  ";
		cin.getline(roll,9);
		while(roll[i]!='\0')
		{
			if(roll[i]<=48 || 57<=roll[i])
			{
				cout<<"\n\tInvalid Input ";
				return 0;
			}
			i++;
		}

		//r=atoi(roll);
		//cin.ignore(1);
		cout<<"\n\tEnter division          :  ";
		cin.getline(div,9);
		cout<<"\n\n\tDate of birth(dd-mm-yy) :  ";
		cin.getline(dob,19);
		cout<<"\n\tEnter blood group       :  ";
		cin.getline(blood,9);
		cout<<"\n\n\tAddress                 :  ";
		cin.getline(address,99);
		cout<<"\n\n\tMobile number           :  ";
		cin.getline(mobile,11);
		cout<<"\n\n\tLicence number          :  ";
        cin.getline(licence,19);
		cout<<"\n\n\t";

		return 1;
	}





};

void Delete(student *s,int roll,int count)
{
	int r;
	int pos=count+1;

	for(int i=1;i<=count;i++)
	{
		r=atoi(s[i-1].roll);
		if(r==roll)
		{
			pos=i;
			break;
		}
	}
	if(pos<=count)
	{
		for(int j=pos;j<=count;j++)
		{
			s[j]=s[j+1];

		}
		count--;
	}
	else
	{
		cout<<"\n\tNo such roll number exist ";
	}
}

int main()
{
	student *s;
	int ch,ch1,flag2=0;
	int i=0,roll,flag=0;
	int count=0;
	cout<<"\n\n\t********* DATA BASE STUDENT *********\n\n\t";
	s=new student[100];

	do
	{

		cout<<"\n\n\n\t 1.Enter data ";
		cout<<"\n\t 2.Display    ";
		cout<<"\n\t 3.Delete     ";
		cout<<"\n\t 0.Exit       ";

		cout<<"\n\tEnter Your choice :";
		cin>>ch;

		switch(ch)
		{

			case 1 :
					do
					{
						cout<<"\n\n\tEnter data for student "<<i+1<<"  :  ";
						flag2=s[i].getdata();
						if(flag==1)
						{
							i++;
							count++;
						}
						cout<<"\n\t Continue(1) Or Stop(0) \n\t";
						cin>>ch1;

					}while(ch1!=0);
					break;

			case 2 :
					cout<<"\n\n\t";
					for(int i=1;i<=count;i++)
					{
						cout<<"\n\n\n\tInformation of student "<<i<<" is :  \n\n\t";
						flag=s[i-1].display();
					}
					if(flag==0)
					{
						cout<<"\n\tEnter the Data first ";
					}
					break;


			case 3 :
					if(flag==0)
					{
						cout<<"\n\n\tNo data Available to delete ";
					}
					else
					{
						cout<<"\n\tEnter Roll number : ";
						cin>>roll;
						Delete(s,roll,count);
					}

					break;

		   default :
			   	    if(ch!=0)
			   	    {
			   	    	cout<<"\n\tInvalid Input ";
			   	    }



		}

	}while(ch!=0);


	delete[]s;

return 0;
}
