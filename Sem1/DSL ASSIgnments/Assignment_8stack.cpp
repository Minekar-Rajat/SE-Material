//============================================================================
// Name        : Assignment_8stack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include<string.h>
using namespace std;
#define MAX 15

class class_stack
{

public:
		int top1;
		char data[MAX];
		class_stack()
		{
			top1=-1;
		}
		void push(char x)
		{
			
			if(!full())
			{
				top1++;
				//strcpy(data[top1],x);
				data[top1]=x;
			}
			else
			{
				cout<<"\n\tStack is Full";
			}
		}
		int full()
		{
			if(top1==MAX-1)
			{
				return 1;
			}
			return 0;
		}
		char pop()
		{
			char x;
			if(!empty())
			{
				//strcpy(x,data[top1]);
				x=data[top1];
				top1--;
				return x;
			}
			else
			{
				cout<<"\n\tStack is Empty";
				return '\0';
			}
		}
		int empty()
		{
			if(top1==-1)
			{
				return 1;
			}
			return 0;
		}
		char top()
		{
			if(top1!=-1)
			{
				return data[top1];
			}
			else
			{
				return '\0';
			}
		}
		
};

int main()
{
		int i=0;
		char x;
		//stack<char>a;
		class_stack obj;
		char s[50];
		cout<<"\n\n\tEnter String \n\t";
		cin.getline(s,49);

		while(s[i]!='\0')
		{
			//if(strcmp(s[i],'{')==0 || strcmp(s[i],'[')==0 || strcmp(s[i],'(')==0)
//			if(s[i]=='{' || s[i]=='[' || s[i]=='(' )
//			{
//				//push(s[i]);
//				obj.push(s[i]);
//			}
			if(s[i]='{')
			{
				obj.push(s[i]);
			}
			if(s[i]='[')
			{
				obj.push(s[i]);
			}
			if(s[i]='(')
			{
				obj.push(s[i]);
			}
			i++;
			
		}
		i=0;
		while(s[i]!='\0')
		{
		
			if(s[i]=='}' || s[i]==']' || s[i]==')' )
			{
				if(!obj.empty())
				{
				//if(strcmp(s[i],'}')==0)
					if(s[i]=='}')
					{
						//if(strxmp(obj.top(),'{')==0)
						
						if(obj.top()=='{')
						{
							x=obj.pop();
						}
						else
						{
							break;
						}
					}
					//else if(strcmp(s[i],']')==0)
					else if(s[i]==']')
					{
						//if(strcmp(obj.top(),'[')==0)
						if(obj.top()=='[')
						{
							x=obj.pop();
	
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
						if(obj.top()=='(')
						{
							x=obj.pop();	

						}
						else
						{
							break;
						}
					}

				}


			}
			i++;
		}
		
		if(obj.top1==-1)
		{
			cout<<"\n\n\tParentesized String  ";

		}
		else
		{
			cout<<"\n\n\tNot Parentesized  ";
		}







	return 0;
}
