#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;

int main()
{
	int ch,x;
	queue<int>q;
	queue<int>temp;
	cout<<"\n\n\t*******************	Queue	*******************\n\n";
	do
	{
		cout<<"	\n\n\n\t1.Enqueue	\
				\n\t2.Dequeue		\
				\n\t3.Show Front	\
				\n\t4.Show Rear		\
				\n\t5.Show Queue	\
				\n\t6.Size			\
				\n\t0.Exit			";
				cout<<"\n\tEnter your choice	:	";
				cin>>ch;
				switch(ch)
				{
					case 1:
						cout<<"\n\tEnter element to enqueue	:	";
						cin>>x;
						q.push(x);
						break;
						
					case 2:
						if(!q.empty())
						{
							cout<<"\n\n\tDequeued Element	:	"<<q.front();
							q.pop();
						}
						else
						{
							cout<<"\n\tQueue is empty";
						}
						break;
					
					case 3:
						if(q.empty())
						{
							cout<<"\n\tQueue is empty";
						}
						else
						{
							cout<<"\n\n\tFront Element	:	"<<q.front();
						}
						break;
					
					case 4:
						if(q.empty())
						{
							cout<<"\n\tQueue is empty";
						}
						else
						{
							cout<<"\n\n\tRear Element	:	"<<q.back();
						}
						break;	
					case 5:
						cout<<"\n\n\tQueue	:	\n";
						if(q.empty())
						{
							cout<<"\n\tQueue is Empty ";
						}
						else
						{
							cout<<"\n\n";
							temp=q;
							while(!temp.empty())
							{
								cout<<"\t"<<temp.front();
								temp.pop();	
							}	
						}
						break;
						
					case 6:
						cout<<"\n\tSize is	:	"<<q.size();
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

