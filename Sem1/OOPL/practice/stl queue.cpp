#include<iostream>
#include<list>
#include<stdlib.h>
using namespace std;

int main()
{
	int ch,x;
	list<int>l1;
	list<int>::iterator p;
	cout<<"\n\n\t*******************	Queue	*******************\n\n";
	do
	{
		cout<<"	\n\n\n\t1.Enqueue	\
				\n\t2.Dequeue		\
				\n\t3.Show Front	\
				\n\t4.Show Rear		\
				\n\t5.Show Queue	\
				\n\t6.Sort			\
				\n\t0.Exit			";
				cout<<"\n\tEnter your choice	:	";
				cin>>ch;
				switch(ch)
				{
					case 1:
						cout<<"\n\tEnter element to enqueue	:	";
						cin>>x;
						l1.push_back(x);
						break;
						
					case 2:
						if(!l1.empty())
						{
							cout<<"\n\n\tDequeued Element	:	"<<l1.front();
							l1.pop_front();
						}
						else
						{
							cout<<"\n\tQueue is empty";
						}
						break;
					
					case 3:
						if(l1.empty())
						{
							cout<<"\n\tQueue is empty";
						}
						else
						{
							cout<<"\n\n\tFront Element	:	"<<l1.front();
						}
						break;
					
					case 4:
						if(l1.empty())
						{
							cout<<"\n\tQueue is empty";
						}
						else
						{
							cout<<"\n\n\tRear Element	:	"<<l1.back();
						}
						break;	
					case 5:
						cout<<"\n\n\tQueue	:	\n";
						if(l1.empty())
						{
							cout<<"\n\tQueue is Empty ";
						}
						else
						{
							cout<<"\n\n";
							for(p=l1.begin();p!=l1.end();p++)
							{
								cout<<"\t	"<<*p;
							}	
						}
						break;
						
					case 6:
						l1.sort();
						break;	
						
					default:
						if(ch!=0)
						{
							cout<<"\n\tInvalid Input";
						}						
							
				}
	}while(ch!=0);
	
	return 0;
}

