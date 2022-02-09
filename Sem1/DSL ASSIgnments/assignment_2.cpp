//============================================================================
// Name        : assignment_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class matrix
{
	int row1,row2,column1,column2;


public:
	int m1[10][10],m2[10][10];

	void insertmat()
	{
		cout<<"\n\tEnter size of 1st matrix \n";
		cin>>row1>>column1;
		cout<<"\n\tEnter the elements \n";
		for(int i=0;i<row1;i++)
		{
			for(int j=0;j<column1;j++)
			{
			cout<<"\n\t";
			cin>>m1[i][j];

			}
		}
		cout<<"\n\n\tEnter size of 2nd matrix \n";
				cin>>row2>>column2;
				cout<<"\n\tEnter the elements \n";
				for(int i=0;i<row2;i++)
				{
					for(int j=0;j<column2;j++)
					{
					cout<<"\n\t";
					cin>>m2[i][j];

					}
				}
	}


	void add()
	{
		if(row1==row2 && column1==column2)
		{
			int temp[row1][column1];
			for(int i=0;i<row1;i++)
			{
				for(int j=0;j<column1;j++)
				{
					temp[i][j]=(m1[i][j])+(m2[i][j]);
				}
			}

			cout<<"\n\n\t";
			for(int i=0;i<row1;i++)
			{
				for(int j=0;j<column1;j++)
				{
					cout<<temp[i][j]<<"\t";
				}
				cout<<"\n\t";
			}


		}
		else
		{
			cout<<"\n\tAddition can't be performed";
		}
	}

	void sub()
		{
			if(row1==row2 && column1==column2)
			{
				int temp[row1][column1];
				for(int i=0;i<row1;i++)
				{
					for(int j=0;j<column1;j++)
					{
						temp[i][j]=(m1[i][j])-(m2[i][j]);
					}
				}

				cout<<"\n\n\t";
				for(int i=0;i<row1;i++)
				{
					for(int j=0;j<column1;j++)
					{
						cout<<temp[i][j]<<"\t";
					}
					cout<<"\n\t";
				}


			}
			else
			{
				cout<<"\n\tSubtraction can't be performed";
			}
		}

	void mul()
			{
				if(column1==row2)
				{

					int temp[row1][column1];

					for(int i=0;i<row1;i++)
					{
						for(int j=0;j<column2;j++)
						{
							temp[i][j]=0;
							for(int k=0;k<column1;k++)
							{

								temp[i][j]+=(m1[i][k])*(m2[k][j]);
							}
						}
					}

					cout<<"\n\n\t";
					for(int i=0;i<row1;i++)
					{
						for(int j=0;j<column1;j++)
						{
							cout<<temp[i][j]<<"\t";
						}
						cout<<"\n\t";
					}

				}
				else
				{
					cout<<"\n\tMultiplication can't be performed";
				}
			}


	void transpose()
	{
		int temp[row1][column1];

		for(int i=0;i<row1;i++)
		{
			for(int j=0;j<column1;j++)
			{
				temp[i][j]=m1[j][i];

			}
		}
		cout<<"\n\tTranspose matrix is : \n\n\t";
		for(int i=0;i<row1;i++)
		{
			for(int j=0;j<column1;j++)
			{
				cout<<temp[i][j]<<"\t";
			}
			cout<<"\n\t";
		}

	}
    void insert1()
    {

    	cout<<"\n\tEnter size of matrix \n";
    			cin>>row1>>column1;
    			cout<<"\n\tEnter the elements \n";
    			for(int i=0;i<row1;i++)
    			{
    				for(int j=0;j<column1;j++)
    				{
    				cout<<"\n\t";
    				cin>>m1[i][j];

    				}
    			}
    }

    void uppertriangular()
    {
        int flag=0;
    	for(int i=0;i<row1;i++)
    	{
    		for(int j=0;j<column1;j++)
    		{
    			if(i>j)
    			{
    				if(m1[i][j]==0)
    				{
    					flag=1;
    				}
    			}
    		}
    	}
    	if(flag==1)
    	{
    		cout<<"\n\n\t";
    		for(int i=0;i<row1;i++)
    		{
    			for(int j=0;j<column1;j++)
    			{
    				cout<<m1[i][j]<<"\t";
    			}
    			cout<<"\n\t";
    		}

    		cout<<"\n\n\tMatrix is Upper Triangular";
    	}
    	else
    	{
    		cout<<"\n\tMatrix is Not Upper Triangular";
    	}

    }

    void saddlepoint()
    {
    	int flag=0,flag1=0;
    	for(int i=0;i<row1;i++)
    	{
    		int var=m1[i][0],clmn_idx=0;
    		for(int j=1;j<column1;j++)
    		{
    			if(var>m1[i][j])
    			{
    				var=m1[i][j];
    			    clmn_idx=j;
    			}

    		}
    		for(int k=0;k<row1;k++)
    		{
    			if(var<m1[k][clmn_idx])
    			{
    				flag=1;
    			}
    		}
    		if(flag==0)
    		{
    		    flag1++;
    			cout<<"\n\tSaddle point is  : "<<var;
    		}

    	}
    	if(flag==1&&flag1==0)
    	 {
    	    cout<<"\n\tSaddle point does not exist";
    	 }

    }

    void sumdig()
    {
    	int sum=0;
    	for(int i=0;i<row1;i++)
    	{
    		for(int j=0;j<column1;j++)
    		{
    			if(i==j)
    			{
    				sum+=m1[i][j];
    			}
    		}
    	}
    	cout<<"\n\tSum of diagonal elements is : "<<sum;
    }

};



int main()
{
	int ch;

	matrix m;
	m.insertmat();


	do
	{
			   cout<<"\n\n\t 0.exit                   ";
			   cout<<"\n\t 1.Addition                 ";
			   cout<<"\n\t 2.Subtraction              ";
			   cout<<"\n\t 3.Multiplication           ";
			   cout<<"\n\t 4.Transpose                ";
			   cout<<"\n\t 5.Upper triangular         ";
			   cout<<"\n\t 6.Saddle point             ";
			   cout<<"\n\t 7.Sum of diagonal elements ";
			   cout<<"\n\n\t Enter your choice        ";
			   cin>>ch;

			   switch(ch)
			   {

			   case 1 :
				        cout<<"\n\tAddition is :    ";
				        m.add();
				        break;

			   case 2 :
				        cout<<"\n\tSubtraction is : ";
				        m.sub();
				        break;

			   case 3 :
				          cout<<"\n\tMultiplication is : ";
				         m.mul();
				         break;

			   case 4 :
				         m.insert1();
				         m.transpose();
				         break;



			   case 5 :
				        m.insert1();
				        m.uppertriangular();
				        break;

			   case 6 :
				        m.insert1();
				        m.saddlepoint();
				        break;

			   case 7 :
				        m.insert1();
				        m.sumdig();
				        break;



			   }

	}
	while(ch!=0);



	return 0;
}
