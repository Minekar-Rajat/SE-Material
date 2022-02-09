#include<iostream>
#include<stack>
#include<string.h>
using namespace std;


int get_prior(char ch)
{
	if(ch=='*' || ch=='/')
		return 1;
	return 0;
}

int main()
{
	char s[100];
	char ans[100];
	stack<char>st;
	char x;
	int k,p=0,flag=0; 
	int ch;
	int pr_ex;
	int pr_st;

	k=0;
	cout<<"\n\n\tEnter String	: ";
	cin.getline(s,99);
	
	
	
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' )
		{
			if(st.empty())
			{
				st.push(s[i]);
				
			}
			else
			{
				while(!st.empty())
				{
					pr_ex=get_prior(s[i]);
					x=st.top();
					st.pop();
					pr_st=get_prior(x);
					if(pr_st>=pr_ex)
					{
						ans[k]=x;
						k++;
					}
					else
					{
						flag=1;
						break;
					}
				}
				if(flag==1)
				{
					st.push(x);
					flag=0;
				}
				st.push(s[i]);
			}
			
			
			
			
		}
		else if(s[i]!='+' || s[i]!='-' || s[i]!='*' || s[i]!='/')
		{
			ans[k]=s[i];
			k++;
		}
		
		
	}
	while(!st.empty())
	{
		x=st.top();
		st.pop();
		ans[k]=x;
		k++;
	}
	
	
	cout<<"\n\n\tInfix To Postfix Conversion	:	";
	for(int i=0;i<=k;i++)
	{
		cout<<ans[i-1];
	
	}
	
	


return 0;	

}

