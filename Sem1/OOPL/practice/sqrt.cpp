#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	float x,y,a;
	int ch;
	while(1)
	{
		cout<<"\n\tEnter Number	:	";
		cin>>x;
		y=-x;
		cout<<y;
		a=sqrt(x);
		cout<<"\n\tSquareroot	:	"<<a;
		cout<<"\n\tDo it again (1/0) ?	:	";
		cin>>ch;
		if(ch==0)
			break;
	}
	
	return 0;
}
