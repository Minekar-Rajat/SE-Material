//============================================================================
// Name        : Assignment_8stack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#include<stack>
using namespace std;


int main()
{
		int i;
		stack<char>a;
		string s;
		cout<<"\n\n\tEnter String \n\t";
		cin>>s;

		for(i=0;i<s.length();i++)
		{
			if(s[i]=='{' || s[i]=='[' || s[i]=='(')
			{
				a.push(s[i]);

			}

			if(!a.empty())
			{
				if(s[i]=='}')
				{
					if(a.top()=='{')
					{
						a.pop();
					}
					else
					{
						break;
					}
				}
				else if(s[i]==']')
				{
					if(a.top()=='[')
					{
						a.pop();

					}
					else
					{
						break;
					}
				}
				else if(s[i]==')')
				{
					if(a.top()=='(')
					{
						a.pop();

					}
					else
					{
						break;
					}
				}

			}


		}
		if(a.empty())
		{
			cout<<"\n\n\tYes  ";

		}
		else
		{
			cout<<"\n\n\tNo  ";
		}







	return 0;
}
