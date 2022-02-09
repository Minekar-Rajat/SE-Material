//============================================================================
// Name        : assignment_emp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<string.h>
using namespace std;

class personal
{
	char name[30];
	char add[40];
	char mobile[13];
	char gen[8];
public :
		void getpersonal()
		{
			cin.ignore(1);
			cout<<"\n\n\tEnter Personal data  :  ";
			cout<<"\n\n\t Enter name       :  ";
			cin.getline(name,28);
			cin.ignore(1);
			cout<<"\n\t Enter Address    :  ";
			cin.getline(add,38);
			cin.ignore(1);
			cout<<"\n\t Enter Mobile no  :  ";
			cin.getline(mobile,12);
			cin.ignore(1);
			cout<<"\n\t Enter Gender     :  ";
			cin.getline(gen,7);
			cin.ignore(1);
		}
		void showpersonal()
		{
			cout<<"\n\n\tPersonal Data       : ";
			cout<<"\n\n\t Name       :  "<<name;
			cout<<"\n\t Address    :  "<<add;
			cout<<"\n\t Mobile no  :  "<<mobile;
			cout<<"\n\t Gender     :  "<<gen;

		}


};


class professional
{
	char Id[20];
	char email[50];
	float sal;
	char exp[200];
	char skill[200];
	public :
			void getpro()
			{
				cin.ignore(1);
				cout<<"\n\n\tEnter Professional data  :  ";
				cout<<"\n\n\t Enter ID         :  ";
				cin.getline(Id,19);
				cin.ignore(1);
				cout<<"\n\t Enter Email      :  ";
				cin.getline(email,49);
				cin.ignore(1);
				cout<<"\n\t Enter Salary     :  ";
				cin>>sal;
				cin.ignore(1);
				cout<<"\n\t Enter Experience :  ";
				cin.getline(exp,198);
				cin.ignore(1);

				cout<<"\n\t Enter Skills     :  ";
				cin.getline(skill,198);
				cin.ignore(1);
			}
			void showpro()
			{
				cout<<"\n\n\tProfessional Data       : ";
				cout<<"\n\n\t Id         :  "<<Id;
				cout<<"\n\t Email      :  "<<email;
				cout<<"\n\t Salary     :  "<<sal;
				cout<<"\n\t Experience :  "<<exp;
				cout<<"\n\t Skills     :  "<<skill;

			}


};

class academic
{
	char hsc[100];
	char college[100];
	char Degree[100];
	float hscmark;
	float cgpa;

public :
	void getAcad()
	{
		cin.ignore(1);
		cout<<"\n\n\tEnter Academic data  :  ";
		cout<<"\n\n\t Enter HSC Jr.College  :  ";
		cin.getline(hsc,99);
		cin.ignore(1);
		cout<<"\n\t Enter HSC marks       :  ";
		cin>>hscmark;
		cin.ignore(1);
		cout<<"\n\t Enter College         :  ";
		cin.getline(college,99);
		cin.ignore(1);
		cout<<"\n\t Enter Degree          :  ";
		cin.getline(Degree,99);
		cin.ignore(1);
		cout<<"\n\t Enter CGPA            :  ";
		cin>>cgpa;
		cin.ignore(1);
	}
	void showAcad()
	{
		cout<<"\n\n\tAcademic Data       : ";
		cout<<"\n\n\t HSC Jr.College :  "<<hsc;
		cout<<"\n\t HSC Marks      :  "<<hscmark;
		cout<<"\n\t College        :  "<<college;
		cout<<"\n\t Degree         :  "<<Degree;
		cout<<"\n\t CGPA           :  "<<cgpa;
	}


};


class employee :public personal,public professional,public academic
{

	public :
        	void getdata()
        	{

        		personal::getpersonal();
        		professional::getpro();
        		academic::getAcad();
        	}
        	void dispaly()
        	{
        		personal::showpersonal();
        		professional::showpro();
        		academic::showAcad();

        	}
};



int main()
{
	employee *e;
	e=new employee[100];
	int ch,ch1,m,i=0,count=0;
	 cout<<"\n\t*******************  Employee *******************\n\t";
	 cout<<"-------------------------------------------------";
	do
	{

		cout<<"\n\n\n\t 1.Enter data ";
		cout<<"\n\t 2.Display    ";
		cout<<"\n\t 3.Delete     ";
		cout<<"\n\t 0.Exit       ";

		cout<<"\n\tEnter Your choice \n\t";
		cin>>ch;

		switch(ch)
		{

			case 1 :
					do
					{
						cout<<"\n\n\tEnter data for Employee "<<i+1<<"  :  ";
						e[i].getdata();
						i++;
						count++;

						cout<<"\n\t Continue(1) Or Stop(0) \n\t";
						cin>>ch1;

					}while(ch1!=0);
					break;

			case 2 :

					cout<<"\n\n\t";
					for(int i=1;i<=count;i++)
					{
						cout<<"\n\n\tEmployee "<<i<<" :  ";
						e[i-1].dispaly();
					}
					break;


			case 3 :

					cout<<"\n\tEnter position : ";
					cin>>m;
					if(count!=0)
					{
						for(int i=m;i<=count;i++)
						{
							e[i]=e[i+1];
						}
						count--;
					}
					else
					{
						cout<<"\n\n\tNo Data Available ";
					}
					break;

			default:
					if(ch!=0)
					{
						cout<<"\n\n\tInvalid Input ";
					}
					else
					{
						delete[]e;
					}










		}

	}while(ch!=0);


	return 0;
}
