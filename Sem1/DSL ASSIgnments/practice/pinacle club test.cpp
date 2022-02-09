#include<iostream>
using namespace std;

class node
{
	char *name;
	string role;
	int prn;
	public : 
		node(char *nm='\0',char *r='\0',int p=0)
		{
			strcpy(name,nm);
			strcpy(role,r);
			prn=p;
		}
		
};

class pinacle
{
	node *head;
	public :
		void create();
		void show();
		void addbypos(int );
		void deletebypos(int );
		int count();
		void showrev1()
		{
			showrev(head);
		}
		void showrev();
		void copylist();
		void findposbyprn();		
};


int main()
{
	pinacle d1,d2;
	int ch,prn,pos;
	int flag1=0,x,c,flag2=0;
	
	cout<<"\n\n\t*******************	PINACLE CLUB *******************\n\n";
	
	do
	{
		cout<<"\n\n\t0.Exit		\
				\n\t1.create divisions	\
				\n\t2.Display division 1	\
				\n\t3.Display division 2	\
				\n\t4.Add Member 			\
				\n\t5.Add President		\
				\n\t6.Add Secretary	\
				\n\t7.Delete Member 	\
				\n\t8.Delete President	\
				\n\t9.Delete Secretary	\
				\n\t10.Display Reverse  \
				\n\t11.Total Number of Members	\
				\n\t12.Concatenate list			";
				
		cout<<"\n\n\tEnter your choice		:	";
		cin>>ch;
		
		switch(ch)
		{
			case 1 :
				if(flag1==0  || flag2==0)
				{
					cout<<"\n\tEnter data For which division :	";
					cin>>x;
					if(x==1 && flag1==0)
					{
						d1.create();
						flag1=1;
					}
					else if(x==2 && flag2==0)
					{
						d2.create();
						flag2=1;
					}
					else if(x==1 && flag1!=0)
					{
						cout<<"\n\tDivision 1 is already created ";
					}
					else if(x==2 && flag2!=0)
					{
						cout<<"\n\tDivision 2 is already created ";
					}	
					else
					{
						cout<<"\n\n\tWRONG INPUT ";
					}
					
				}
				else
				{
					cout<<"\n\tDivisions are already created";
				}
				break;
				
				
			case 2 :
				cout<<"\n\n\t******************* PINACLE CLUB *******************\n\n";
				cout<<"\n\t=================== Division  1  ===================\n\n";
				d1.show();
				break;
				
				
			case 3 :
				cout<<"\n\n\t******************* PINACLE CLUB *******************\n\n";
				cout<<"\n\t=================== Division  2  ===================\n\n";
				d2.show();
				break;	
				
				
			case 4 :
					cout<<"\n\tAdd Member For which division :	";
					cin>>x;
					if(x==1)
					{
						c=d1.count();
						d1.addbypos(c-1);
					}
					else if(c==2)
					{
						c=d2.count();
						d1.addbypos(c-1);
					}
					break;
					
					
			case 5 :
					cout<<"\n\tAdd President For which division :	";
					cin>>x;
					if(x==1)
					{
						c=d1.count();
						d1.addbypos(1);
					}
					else if(c==2)
					{
						c=d2.count();
						d1.addbypos(1);
					}
					else
					{
						cout<<"\n\n\tWrong input"
					}
					break;
				
			case 6 :
					cout<<"\n\tAdd Secretary For which division :	";
					cin>>x;
					if(x==1)
					{
						c=d1.count();
						d1.addbypos(c);
					}
					else if(c==2)
					{
						c=d2.count();
						d1.addbypos(c);
					}
					else
					{
						cout<<"\n\n\tWrong input ";
					}
					break;	
					
					
			case 7 :
				cout<<"\n\n\tEnter PRN Number	:	";
				cin>>prn;
				cout<<"\n\tDelete Member For which division :	";
				cin>>x;
				if(x==1)
				{
					pos=d1.findposbyprn(prn);
					d1.deletebypos(pos);
				}
				else if(x==2)
				{
					pos=d2.findposbyprn(prn);
					d2.deletebypos(pos);
				}
				else
				{
					cout<<"\n\n\tWrong input ";
				}
				break;
		
			case 8 :
				cout<<"\n\tDelete President For which division :	";
				cin>>x;
				if(x==1)
				{
					d1.deletebypos(1);
				}
				else if(x==2)
				{
					d2.deletebypos(1);
				}
				else
				{
					cout<<"\n\n\tWrong input ";
				}
				break;
				
				
			case 9 :
				cout<<"\n\tDelete Secretary For which division :	";
				cin>>x;
				if(x==1)
				{
					c=d1.count();
					d1.deletebypos(c);
				}
				else if(x==2)
				{
					c=d2.count();
					d2.deletebypos(c);
				}
				else
				{
					cout<<"\n\n\tWrong input ";
				}
				break;
				
				
			case 10 :
				cout<<"\n\tDisplay Reverse For which division :	";
				cin>>x;
				if(x==1)
				{
					cout<<"\n\n\t******************* PINACLE CLUB *******************\n\n";
					cout<<"\n\t=================== Division  1  ===================\n\n";
					d1.showrev1();
				}
				else if(x==2)
				{
					cout<<"\n\n\t******************* PINACLE CLUB *******************\n\n";
					cout<<"\n\t=================== Division  2  ===================\n\n";	
					d2.showrev1();
				}
				else
				{
					cout<<"\n\n\tWrong input ";
				}
				break;
				
				
			case 11 :
				cout<<"\n\tFind For which division :	";
				cin>>x;
				if(x==1)
				{
					c=d1.count();
					cout<<"\n\n\tTotal Numbers of Members  :	"<<c;
				}
				else if(x==2)
				{
					c=d2.count();
					cout<<"\n\n\tTotal Numbers of Members  :	"<<c;
				}
				else
				{
					cout<<"\n\n\tWrong input ";
				}
				break;
				
				
			default :
				if(ch!=0)
				{
					cout<<"\n\tInvalid Input";
				}			
					
		}
		
	}while(ch!=0);
	
	
	
	
	
	
	
	
	
	
	return 0;
}
