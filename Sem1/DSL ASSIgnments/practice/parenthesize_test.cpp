//============================================================================
// Name        : Assignment_8stack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stack>
#include<string.h>
using namespace std;


int main()
{
		stack<char>st;
		cout<<st.empty();
		int i=0;
		char x;
		char s[50];
		cout<<"\n\n\tEnter String \n\t";
		cin.getline(s,49);

		for(i=0;i<strlen(s);i++)
		{

			if(s[i]=='{')
			{
				st.push(s[i]);
			}
			else if(s[i]=='[')
			{
				st.push(s[i]);
			}
			else if(s[i]=='(')
			{
				st.push(s[i]);
			}
			
			
		}
		
		
		for(i=0;i<strlen(s);i++)
		{
		
			if(s[i]=='}' || s[i]==']' || s[i]==')' )
			{
				if(!st.empty())
				{
					if(s[i]=='}')
					{
						if(st.top()=='{')
						{
							st.pop();
						}
						else
						{
							break;
						}
					}
					
					else if(s[i]==']')
					{
						
						if(st.top()=='[')
						{
							st.pop();
	
						}
						else
						{
							break;
						}
					}
					//else if(strcmp(s[i],')')==0)
					else if(s[i]==')')
					{
						//if(strcmp(obj.top(),'(')==0)
						if(st.top()=='(')
						{
							st.pop();	

						}
						else
						{
							break;
						}
					}

				}


			}
			
		}
		
//		while(!st.empty())
//		{
//			cout<<"\n\t"<<st.top();
//			st.pop();
//			
//		}
		
		if(st.empty())
		{
			
			cout<<"\n\n\tParentesized String  ";

		}
		else
		{
			cout<<"\n\n\tNot Parentesized  ";
		}







	return 0;
}
