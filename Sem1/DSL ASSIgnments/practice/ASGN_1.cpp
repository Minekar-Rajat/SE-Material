#include<iostream>
using namespace std;

int cnt1=0;
int cnt2=0;


class student 
{
	int roll;
	float marks;
	char x;
	

	public :
		
		student(int r=0,float m=0,char y='a')
		{
			roll=r;
			marks=m;
			x=y;
		}
		void getmarks()
		{
			cout<<"\n\tStudent : Roll : "<<roll<<" was present or absent(p/a)";
			cin>>x;
			if(x=='p')
			{
				cout<<"\n\tEnter Marks of Student "<<roll<<" : ";
				cin>>marks;
				cout<<endl;
				cnt1++;
			}
			else if(x=='a')
			{
				marks=0;
			}
			else
			{
				cout<<"\n\t\tWrong Input";
			}
		}
		void display()
		{
			cout<<"\n\tStudent : "<<roll<<" : "<<marks;
		}
		void absentlist()
		{
			if(x=='a' || x=='A')
			{
				cout<<"\n\n\t\t"<<roll;
			}
		}
		
		float return_marks()
		{
			return marks;
		}
		void rollcall(int i)
		{
			roll=i;
			
		}
		int is_present()
		{
			if(x=='p')
			{
				return 1;
			}
			return 0;
		}
};


int main()
{
	
	int n,ch,choice,cntr,previous=0;
	float sum=0;
	float avg,high,low,mrks;
	
	
	
	cout<<"\n\tEnter Numbers of Students : ";
	cin>>n;	
	
	student s[n];
	
	for(int i=1;i<=n;i++)
	{
		s[i-1].rollcall(i);
	}
	
	cout<<"\n\tENTER DATA	:	\n";
	for(int i=0;i<n;i++)
	{
		
		s[i].getmarks();
		sum+=s[i].return_marks();
	}
	
	do
	{
		cout<<"\n\n\t0.Exit		\
				\n\t1.Display Marks 	\
				\n\t2.Average Marks		\
				\n\t3.Highest & Lowest	\
				\n\t4.Mostly Scored Marks	\
				\n\t5.Absent Students	";
		cout<<"\n\n\tEnter Your Choice  : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1 :
					cout<<"\n\n\t******** STUDENTS ********\n";
					for(int i=0;i<n;i++)
					{
						s[i].display();
					}
					break;
					
			case 2 :
					cout<<"\n\tNumber of Present Student : "<<cnt1;
					avg=sum/cnt1;
					cout<<"\n\n\tAverage marks scored by students :	 "<<avg;
					break;
					
			case 3 :
					high=s[0].return_marks();
					low=s[0].return_marks();
					for(int i=1;i<n;i++)
					{
						if(s[i].return_marks()>high)
						{
							high=s[i].return_marks();
						}
						else if(s[i].return_marks()<low && s[i].is_present()!=0)
						{
							low=s[i].return_marks();
						}
					}
					cout<<"\n\n\t\tHighest Marks : "<<high;
					cout<<"\n\n\t\tLowest  Marks : "<<low;
					break;
					
			case 4 :
					for(int i=0;i<n;i++)
					{
						for(int j=1;j<n;j++)
						{
							cntr=0;
							if(s[i].return_marks()==s[j].return_marks())
							{
								cntr++;
								if(previous<cntr)
								{
									mrks=s[j].return_marks();
    			        			previous=cntr;
								}
								cntr=0;
							}
						}
					}
					
					cout<<"\n\n\tMostly Scored Marks : "<<mrks;
					break;
					
					
					
					
					
			case 5 :
            	    cout<<"\n\tThe list of students who were absent :\n\t";
            	    for(int i=0;i<n;i++)
    	    	    {
    	    	      s[i].absentlist();
    	    	    }
            	    break;
					
					
			default :
					if(ch!=0)
					{
						cout<<"\n\tWrong Input";
					}
		}
		
		
		
	}while(ch!=0);

}


