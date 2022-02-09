//============================================================================
// Name        : Assignment_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class matrix
{
	int row,column;
    int m[10][10];
public:



	matrix insert()
	{
		matrix temp;
		cout<<"\n\tEnter size of matrix \n";
		cin>>temp.row>>temp.column;

		cout<<"\n\tEnter the elements \n";
		for(int i=0;i<temp.row;i++)
		{
		   for(int j=0;j<temp.column;j++)
		   {
		      cout<<"\n\t";
		      cin>>temp.m[i][j];

	       }
		}

		cout<<"\n\n\tEntered matrix is : ";
		cout<<"\n\n\t";

		for(int i=0;i<temp.row;i++)
		{
			for(int j=0;j<temp.column;j++)
			{
				cout<<temp.m[i][j]<<"\t";
			}
			cout<<"\n\t";
		}

		return temp;

	}

	void sparse()
	{
		int count=0,cnt=0;
		for(int i=0;i<this->row;i++)
		{
			for(int j=0;j<this->column;j++)
			{
				cnt++;
				if(this->m[i][j]==0)
				{
					count++;
				}


			}
		}

		if(count>(cnt/2))
		{
			cout<<"\n\tGiven matrix is sparse matrix";
		}
		else
		{
			cout<<"\n\tGiven matrix is not sparse matrix";
		}

	}

	void transpose()
	{




		    matrix temp;

			for(int i=0;i<this->row;i++)
			{
				for(int j=0;j<this->column;j++)
				{
					temp.m[i][j]=this->m[j][i];

				}
			}
			cout<<"\n\tTranspose matrix is : \n\n\t";
			for(int i=0;i<this->row;i++)
			{
				for(int j=0;j<this->column;j++)
				{
					cout<<temp.m[i][j]<<"\t";
				}
				cout<<"\n\t";
			}

    }

	void add(matrix &obj,matrix &ob)
	{

		if(ob.row==obj.row && ob.column==obj.column)
		{
			matrix temp;
			for(int i=0;i<ob.row;i++)
			{
				for(int j=0;j<ob.column;j++)
				{
					temp.m[i][j]=(ob.m[i][j])+(obj.m[i][j]);
				}
			}

			cout<<"\n\tAddition is : ";
			cout<<"\n\n\t";


			for(int i=0;i<ob.row;i++)
			{
				for(int j=0;j<ob.column;j++)
				{
					cout<<temp.m[i][j]<<"\t";
				}
				cout<<"\n\t";
			}


		}
		else
		{
			cout<<"\n\tAddition can't be performed";
		}

	}






};


int main()
{
	int ch;

	matrix m,m1,m2,m3;
	m1=m.insert();

	do
	{
		  cout<<"\n\n\t 0.exit             ";
	      cout<<"\n\t 1.transpose          ";
		  cout<<"\n\t 2.Sparse             ";
		  cout<<"\n\t 3.Addition           ";
		  cout<<"\n\n\t Enter your choice  ";
		  cin>>ch;

		  switch(ch)
		  {

			  case 1 :
			 		   m1.transpose();
			 		   break;

			  case 2 :
			 		    cout<<"\n\tSparse : ";
			 		    m1.sparse();
			 		    break;

			  case 3 :
				        cout<<"\n\n\tEnter two matrices : \n\t";
				        cout<<"\n\n\tFor 1st :  \n\t";
			 			m3=m.insert();
			 			 cout<<"\n\n\tFor 2nd :  \n\t";
			 			m2=m.insert();
			 			m.add(m2,m3);
			 		    break;
			 }



	}while(ch!=0);





	return 0;
}
