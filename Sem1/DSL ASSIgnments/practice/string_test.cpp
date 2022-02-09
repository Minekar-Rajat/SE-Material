#include<iostream>
using namespace std;


int main()
{
	int cnt=0,i=0,j=0;
	char *arr1,*arr2;
	arr1=new char[10];
	arr2=new char[10];
	cout<<"\n\n\tEnter a String	1	:	";
	cin.getline(arr1,9);
	cout<<"\n\n\tEntered String 1	:	"<<arr1;
	while(arr1[i]!='\0')
	{
		cnt++;
		i++;
	}
	
	cout<<"\n\n\t\tSIZE		:	"<<cnt;
	
	cout<<"\n\n\tEnter a String	2	:	";
	cin.getline(arr2,9);
	cout<<"\n\n\tEntered String 2	:	"<<arr2;
	
//	i=0;
//	while(arr2[i]!='\0')
//	{
//		cnt++;
//		i++;
//	}
	i=0;
	while(arr1[i]!='\0')
	{
		i++;
	}
	while(arr2[j]!='\0')
	{
		arr1[i]=arr2[j];
		j++;
		i++;
		
	}
	
	cout<<"\n\n\tConcatinated String		:"<<arr1;
	

return 0;
}
