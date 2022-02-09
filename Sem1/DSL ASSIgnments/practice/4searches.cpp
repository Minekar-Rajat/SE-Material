#include<iostream>
using namespace std;

void linearsearch(int * arr,int n,int x)
{
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==x)
		{
			flag=1;
		}
		
	}
	if(flag==1)
	{
		cout<<"\n\tFound";
	}
	else 
	{
		cout<<"\n\tNot found";
	}
}

void sentinal(int *arr,int n,int x)
{
	int last;
	last=arr[n-1];
	arr[n-1]=x;
	int i=0;
	while(arr[i]!=x)
	{
		i++;
	}
	arr[n-1]=last;
	if(i<n-1 || x==arr[n-1])
		cout<<"\n\tFound";
	else
		cout<<"\n\tNot Found";
			
	
	
}

int main()
{
	int arr[10]={100,10,60,80,20,50,70,30,40};
	
	
	linearsearch(arr,10,50);
	linearsearch(arr,10,500);
	cout<<"\n\n\n";
	
	sentinal(arr,10,50);
	sentinal(arr,10,500);
	
	
}
