#include<list>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main()
{
	int ch;
	string x;
	list<string>l1;
	list<string>::iterator p;
	cout<<"\n\n\t*******************	Stack	*******************\n\n";
	do
	{
		cout<<"	\n\n\n\t1.Push	\
				\n\t2.Pop		\
				\n\t3.Show top	\
				\n\t4.Show Stack\
				\n\t5.Sort		\
				\n\t0.Exit		";
				cout<<"\n\tEnter your choice	:	";
				cin>>ch;
				switch(ch)
				{
					case 1:
						cout<<"\n\tEnter element to push	:	";
						cin>>x;
						l1.push_front(x);
						break;
						
					case 2:
						if(!l1.empty())
						{
							cout<<"\n\n\tPoped Element	:	"<<l1.front();
							l1.pop_front();
						}
						else
						{
							cout<<"\n\tStack is empty";
						}
						break;
					
					case 3:
						if(l1.empty())
						{
							cout<<"\n\tStack is empty";
						}
						else
						{
							cout<<"\n\n\tTop Element	:	"<<l1.front();
						}
						break;
						
					case 4:
						cout<<"\n\n\tStack	:	\n";
						if(l1.empty())
						{
							cout<<"\n\tStack is Empty ";
						}
						else
						{
							for(p=l1.begin();p!=l1.end();p++)
							{
								cout<<"\n\t\t	"<<*p;
							}	
						}
						break;
						
					case 5:
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
