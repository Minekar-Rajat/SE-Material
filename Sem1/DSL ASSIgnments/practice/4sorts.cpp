#include<iostream>
using namespace std;

void selection(int *arr,int n)
{
	int min_idx,temp;
	for(int i=0;i<n-1;i++)
	{
		min_idx=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min_idx])
			{
				min_idx=j;
			}
		}
		temp=arr[min_idx];
		arr[min_idx]=arr[i];
		arr[i]=temp;
	}
	
	
}

void bubble(int *arr,int n)
{
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
}

void insertion(int *arr,int n)
{
	int temp,i,j;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=0;j--)
		{
			if(arr[j]>temp)
			{
				arr[j+1]=arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j+1]=temp;
	}
}

int main()
{
	int arr[10]={10,50,45,60,20,15,30,70,25,90};
	int num[10]={10,50,45,60,20,15,30,70,25,90};
	int Arr[10]={10,20,30,40,50,60,70,80,90,100};
	selection(arr,10);
	
	cout<<"\n\n\tSelection : \n\t";
	for(int i=0;i<10;i++)
	{
		cout<<"\t"<<arr[i];
	}
	
	bubble(num,10);
	
	cout<<"\n\n\tBubble : \n\t";
	for(int i=0;i<10;i++)
	{
		cout<<"\t"<<num[i];
	}
	
	
	
	
	insertion(Arr,10);
	
	cout<<"\n\n\tInsetion : \n\t";
	for(int i=0;i<10;i++)
	{
		cout<<"\t"<<Arr[i];
	}
}
