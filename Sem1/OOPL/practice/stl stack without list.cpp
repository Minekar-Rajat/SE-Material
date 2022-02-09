#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int ch,x;
	stack<int>s;
	stack<int>temp;
	cout<<"\n\n\t*******************	Stack	*******************\n\n";
	do
	{
		cout<<"	\n\n\n\t1.Push	\
				\n\t2.Pop		\
				\n\t3.Show top	\
				\n\t4.Show Stack\
				\n\t0.Exit		";
				cout<<"\n\tEnter your choice	:	";
				cin>>ch;
				switch(ch)
				{
					case 1:
						cout<<"\n\tEnter element to push	:	";
						cin>>x;
						s.push(x);
						break;
						
					case 2:
						if(!s.empty())
						{
							cout<<"\n\n\tPoped Element	:	"<<s.top();
							s.pop();
						}
						else
						{
							cout<<"\n\tStack is empty";
						}
						break;
					
					case 3:
						if(s.empty())
						{
							cout<<"\n\tStack is empty";
						}
						else
						{
							cout<<"\n\n\tTop Element	:	"<<s.top();
						}
						break;
						
					case 4:
						cout<<"\n\n\tStack	:	\n";
						if(s.empty())
						{
							cout<<"\n\tStack is Empty ";
						}
						else
						{
							temp=s;
							while(!temp.empty())
							{
								cout<<"\n\t"<<temp.top();
								temp.pop();
							}		
						}
						break;
						
//					case 5:
//						cout<<"\n\tSize is	:	";
//						break;	
						
					default:
						if(ch!=0)
						{
							cout<<"\n\tInvalid Input";
						}						
							
				}
	}while(ch!=0);
	
	return 0;
}
