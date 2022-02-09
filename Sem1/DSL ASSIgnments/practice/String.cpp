#include<iostream>
using namespace std;

class str
{
	char *s;
	int n;
	
	public:
		void create()
		{
			int cnt=0;
			cout<<"\n\n\tEnter string	:	";
			cin.getline(s,50);
			while(s[i]!='\0')
			{
				cnt++;
			}
			n=cnt;
		}
		
		bool equal(str &s1,str &s2)
		{
			int flag=0;
			if(s1.n==s2.n)
			{
				for(int i=0;i<s1.n &&s1.s[i]==s2.s[i];i++)
				{
					flag=1;
				}
			}
			if(flag==1)
			{
				cout<<"\n\n\tBoth strings are equal";
				return true;
			}
			else
			{
				cout<<"\n\n\tStrings are not equal";
				return false;
			}
		}
		
		bool isempty(str &s1)
		{
			if(s1.n==0)
			{
				return true;
			}
			return false;
		}
		
		int length(str &s1)
		{
			if(s1.n==0)
			{
				cout<<"\n\n\tEmpty String";
			}
			return s1.n;
		}
		
		char* concat(str &s1,str &s2)
		{
			int k=0;
			for(int i=0;i<s1.n;i++)
			{
				s[i]=s1.s[i];
			}
			k=i;
			for(int i=0;i<s2.n;i++)
			{
				s[k]=s2.s[i];
				k++;
			}
			n=k;
			return s;
		}
		
		void copy(str &s1,str &s2)
		{
			s1.n=s2.n;
			for(int i=0;i<s2.n;i++)
			{
				s1.s[i]=s2.s[i];
			}
		}
		
		char* reverse(str &s1)
		{
			char *temp;
			int k=0;
			temp=new char[s1.n];
			for(int i=s1.n-1;i>=0;i--)
			{
				temp[k]=s1.s[i];
				k++;
			}
			return temp;
		}
		
		int frequency(char &c)
		{
			int cnt=0;
			for(int i=0;i<n;i++)
			{
				if(s[i]==c)
				{
					cnt++;
				}
			}
			return cnt;
		}
		
		bool palindrome(str &s1)
		{
			int flag=0;
			for(int i=0,j=s1.n-1;i<s1.n && j>=0;i++,j--)
			{
				if(s1.s[i]==s1.s[j])
				{
					flag=1;
				}
				else
				{
					break;
				}
			}
			if(flag==1)
			{
				return true;
			}
			return false;
		}
		
		
		char* substring(int i ,int j)
		{
			int k=0;
			char *temp;
			temp=new char[50];
			
			for(int p=0;p<j;p++)
			{
				temp[p]=s[i];
				i++;
			}
			return temp;
			
				
		}	
		
		int find(str &s1,str &t)
		{
			int idx,k=0,flag=0;
			for(int i=0;i<s1.n-t.n;i++)
			{
				k=0;
				for(int j=i;j<t.n && j<s1.n;j++)
				{
					if(s1.s[j]==t.s[k])
					{
						flag=1;
					}
					k++;
				}
				if(flag==1)
				{
					return 1;
				}
			}
			return -1;
		}
		
		
		
};
