#include<iostream>
using namespace std;

//f(x) = x % n

int main()
{
	int *arr,*occupied;
	int n,x,flag=0;
	int i,j;
	
	cout<<"\n\n\tEnter Size of Array	:	";
	cin>>n;
	
	arr=new int[n];
	occupied=new int[n];
	
	for(i=0;i<n;i++)
	{
		occupied[i]=0;
		arr[i]=0;
	}
	
	
	
	for(int k=0;k<n;k++)
	{
		cout<<"\n\n\tEnter Element	or -1	:	";
		cin>>x;
		if(x==-1)
		{
			break;
		}
		i=(x%n);
		
		
		
		if(occupied[i]==0)
		{
			arr[i]=x;
			occupied[i]=1;
			flag=1;
		}
		else
		{
			j=(i+1)%n;
			while(j!=i)
			{
				if(occupied[j]==0)
				{
					arr[j]=x;
					occupied[j]=1;
					flag=1;
					break;
				}
				
				
				j=(j+1)%n;
			}
		}
		if(flag==0)
		{
			cout<<"\n\n\tArray is Full !!!";
			break;
		}
	}
	
	
	for(i=0;i<n;i++)
	{
		cout<<"\n\n\t"<<arr[i]<<"\t\t"<<occupied[i];
	}
	
	
	
	
	return 0;	
}
