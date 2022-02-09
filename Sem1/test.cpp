#include<iostream>
using namespace std;

int main()
{
	int req;
	float avl,curr;
	cin>>req>>avl;
	//cout<<"\n\t"<<req<<avl;
	if(req< (avl-0.5))
	{
		if(req%5==0)
		{
			curr=avl-0.5-req;
			cout<<"\n"<<curr;
		}
		else
		{
			curr=avl;
			cout<<"\n"<<curr;
		}
	}
	else
	{
		curr=avl;
		cout<<"\n"<<curr;
	}
	
	return 0;
}
