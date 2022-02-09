//============================================================================
// Name        : Assignment_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
int i,j,k,n,high,low;
int sum=0,cnt=0,cntr=0;
int previous=0,mrks=0;
float avg;
int ch;

class student
{
	int roll;

public:
	int marks;
	char x;
	void rollcalls()
	{
		roll=i+1;
	}

	void getmarks()
	{
		cout<<"\n\tThe student of roll no :"<<roll<<" is present or absent(p/a)\n\t";
		cin>>x;

		if(x=='p'||x=='P')
		{
		    cout<<"\tEnter the marks of student : "<<roll<<"\n\t";
		    cin>>marks;
		    cout<<"\n";
		}
		else if(x=='a'||x=='A')
		{
			marks=0;
		}
		else
		{
			cout<<"\n\tWrong input";
		}


	}

	void total()
	{
		if(x=='p'||x=='P')
		{
			sum=sum+marks;
			cnt++;
		}

	}

	void absentlist()
	{
		if(x=='a'||x=='A')
		{
			cout<<"\n\t"<<roll;
		}

	}

	void display()
	{
		cout<<"\n\t student  : "<<roll<<"  "<<marks;
	}

};

int main()
{


	cout<<"\n\tEnter the number of students\n\t";
	cin>>n;
	student s[n];


    for(i=0;i<n;i++)
	{
    	s[i].rollcalls();

	}


	for(i=0;i<n;i++)
	{
		s[i].getmarks();
		s[i].total();

	}

	do
	{
	   cout<<"\n\n\t 0.exit                ";
	   cout<<"\n\t 1.display marks       ";
	   cout<<"\n\t 2.average marks       ";
	   cout<<"\n\t 3.highest and lowest  ";
	   cout<<"\n\t 4.mostly scored marks ";
	   cout<<"\n\t 5.absent students     ";
	   cout<<"\n\n\t Enter your choice     ";
	   cin>>ch;

	   switch(ch)
	   {

	   case 1 :
		   for(i=0;i<n;i++)
	       {
		     s[i].display();

	       }

		   break;

	   case 2 :

		   cout<<"\n\tNumber of students present are : "<<cnt;
		   for(i=0;i<n;i++)
		   	{
		   		s[i].total();

		   	}
           avg=sum/cnt;

           cout<<"\n\n\tAverage marks scored by students : "<<avg<<"\n\n\t";
           break;

	   case 3 :

            high=s[0].marks;
            low=s[0].marks;
            for(i=0;i<n;i++)
            {
    	       if(high<s[i].marks)
    	       {
    		     high=s[i].marks;
    	       }
    	       if(s[i].x=='p'||s[i].x=='P')
    	       {
    	         if(low>=s[i].marks)
    	         {
    		       low=s[i].marks;
    	         }
    	       }

            }

            cout<<"\n\tThe highest score is :"<<high<<"\n\t";
            cout<<"\n\tThe lowest score is  :"<<low<<"\n\t";
            break;

	   case 4 :


               for(i=0;i<n;i++)
               {
    	          for(j=1;j<n;j++)
    	          {
    	        	  cntr=0;
    		        if(s[i].marks==s[j].marks)
    		        {
    			      cntr++;

    		          if(previous<cntr)
    		          {
    			        mrks=s[j].marks;
    			        previous=cntr;
    		          }
    		          cntr=0;
    		        }
    	          }
               }
                cout<<"\n\tStudents scored marks :"<<mrks;
                break;

	   case 5 :
                cout<<"\n\tThe list of students who were absent :\n\t";
                for(i=0;i<n;i++)
    	        {
    	          s[i].absentlist();
    	        }
                break;

	   }
	}while(ch!=0);

return 0;
}


