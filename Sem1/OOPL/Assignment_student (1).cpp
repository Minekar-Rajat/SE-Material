//============================================================================
// Name        : Assignment3_quadratic.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;




class student
{
	char name[20]={'\0'};
	int roll=0;
	char div[10]={'\0'};
	int dd=0;
	int mm=0;
	int yy=2019;
	char blood[10]={'0'};
	char address[100]={'\0'};
	int mobile[15]={0};;
	int licence[20];

public :


	void display()
	{
		cout<<"\n\n\tInformation of student is :  \n\n\t";
		cout<<"\n\n\tName        :  "<<name;
		cout<<"\n\n\tRoll no     :  "<<roll;
		cout<<"\n\n\tDivision    :  "<<div;
		cout<<"\n\n\tDOB         :  "<<dd<<"-"<<mm<<"-"<<yy;
		cout<<"\n\n\tBlood group :  "<<blood;
		cout<<"\n\n\tAddress     :  "<<address;
		cout<<"\n\n\tMobile no   :  "<<mobile;
		cout<<"\n\n\tLicence no  :  "<<licence;


	}

	void getdata()
	{
		cout<<"\n\n\tEnter student's data    :  ";
		cout<<"\n\n\tEnter name              :  ";
		cin.getline(name,19);
		cout<<"\n\n\tEnter Roll number       :  ";
		cin>>roll;
		cout<<"\n\n\tEnter division          :  ";
		cin.getline(div,9);
		cout<<"\n\n\tDate of birth(dd/mm/yy) :  ";
		cin>>dd>>mm>>yy;
		cout<<"\n\n\tEnter blood group       :  ";
		cin.getline(blood,9);
		cout<<"\n\n\tAddress                 :  ";
		cin.getline(address,99);
		cout<<"\n\n\tMobile number           :  ";
		for(int i=0;i<9;i++)
		{
			cin>>mobile[i];
		}
		cout<<"\n\n\tLicence number          :  ";
		for(int i=0;i<9;i++)
		{
			cin>>licence[i];
		}


		cout<<"\n\n\n\t";


	}








};



int main()
{


	student s;
	s.getdata();
	s.display();


return 0;
}
