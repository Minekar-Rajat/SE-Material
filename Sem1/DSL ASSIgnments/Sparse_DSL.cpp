#include<iostream>
using namespace std;
#define MAX 50

class sparse
{
	int row,col,k;
	int m[10][10];
	int sp[MAX][3];
	int ftrans[MAX][3];
	public:
		
		void insert()
		{
			
			cout<<"\n\tEnter size of matrix \n\tRow : ";
			cin>>this->row;
			cout<<"\n\tCol : ";
			cin>>this->col;
			
			cout<<"\n\tEnter the elements \n";
			for(int i=0;i<this->row;i++)
			{
			   for(int j=0;j<this->col;j++)
		 	  {
		   	  	 cout<<"\n\t element M"<<i<<j<<" : ";
		      	 cin>>this->m[i][j];

	      	  }
			}
		
		}
		void display()
		{
			cout<<"\n\n\tMatrix is : ";
			cout<<"\n\n\t";
			for(int i=0;i<this->row;i++)
			{
				for(int j=0;j<this->col;j++)
				{
					cout<<this->m[i][j]<<"\t";
				}
				cout<<"\n\t";
			}
		}
		void makesparse()
		{
			int p,q;
			k=1;
			sp[0][0]=row;
			sp[0][1]=col;
			sp[0][2]=0;
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
					if(m[i][j]!=0)
					{
						sp[k][0]=i;
						sp[k][1]=j;
						sp[k][2]=m[i][j];
						sp[0][2]++;
						k++;
					}
				}
			}
		
		
			cout<<"\n\n\tSparse matrix of given matrix is : ";
			cout<<"\n\n\t";
			cout<<"\n\trow\tcol\ttotal";
			cout<<"\n\t";
			cout<<sp[0][0]<<"\t"<<sp[0][1]<<"\t"<<sp[0][2]<<"\t\n\t------------------\n\t";
			for(p=1;p<k;p++)
			{
				for(q=0;q<3;q++)
				{
					cout<<sp[p][q]<<"\t";
				}
				cout<<"\n\t";
			}
			
	
		}
		
		void fasttranspose()
		{
			int *total,*index;
			
			total=new int[col];
		 	index=new int[col];
 			for(int i=0;i<col;i++)
 			{
	 			total[i]=0;
			}
 			for(int i=1;i<=sp[0][2];i++)
 			{
	 			//count
				row=sp[i][1];
 				total[row]++;
 			}
 			index[0]=1;
 			for(int i=1;i<col;i++)
 			{
 				index[i]=index[i-1]+total[i-1];
			}
	 		
		 	ftrans[0][0]=sp[0][1];
		 	ftrans[0][1]=sp[0][0];
		 	ftrans[0][2]=sp[0][2];
	 		int r,c,v,i,ind;
 			for(int i=1;i<=sp[0][2];i++)
 			{
			 	r=sp[i][1];
 				c=sp[i][0];
 				v=sp[i][2];
 				ind=index[r];
 				ftrans[ind][0]=r;
 				ftrans[ind][1]=c;
 				ftrans[ind][2]=v;
 				index[r]++;
 		
 			}
 			
 			cout<<"\n\n\tFast transpose is : ";
			cout<<"\n\n\t";
			cout<<"\n\trow\tcol\ttotal";
			cout<<"\n\t";
			cout<<ftrans[0][0]<<"\t"<<ftrans[0][1]<<"\t"<<ftrans[0][2]<<"\t\n\t------------------\n\t";
			for(int p=1;p<k;p++)
			{
				for(int q=0;q<3;q++)
				{
					cout<<ftrans[p][q]<<"\t";
				}
				cout<<"\n\t";
			}
 		
		}
		
		void add(sparse &s1,sparse &s2)
		{
			if(s1.row==s2.row && s1.col==s2.col)
			{
				this->row=s1.row;
				this->col=s1.col;
				for(int i=0;i<s1.row;i++)
				{
					for(int j=0;j<s1.col;j++)
					{
						this->m[i][j]=(s1.m[i][j]+s2.m[i][j]);
					}
				}
				cout<<"\n\n\tAddition of matrices : ";
				this->display();
			}
			else
			{
				cout<<"\n\tAddition Cannot be Performed ";
			}
		}
		
		
		
};


int main()
{
	sparse s1,s2,s3;
	
	
	int ch;

	do
	{
		  cout<<"\n\n\t 0.exit             ";
		  cout<<"\n\t 1.Sparse Matrix      ";
	      cout<<"\n\t 2.fast transpose     ";
		  cout<<"\n\t 3.Addition           ";
		  cout<<"\n\n\t Enter your choice  : ";
		  cin>>ch;

		  switch(ch)
		  {
		  	case 1 :
		  			s1.insert();
					s1.display();
		  			s1.makesparse();
		  			break;
			case 2 : 
		  			s1.insert();
					s1.makesparse();
					s1.fasttranspose();
		  			break;
		  	case 3 :
		  			cout<<"\n\tEnter two matrices :\n\t";
		  			s1.insert();
		  			s2.insert();
		  			s1.display();
		  			s2.display();
		  			s3.add(s1,s2);
					break;

			default:
					if(ch!=0)
					{
						cout<<"\n\n\tInvalid Input";
					}				
		  }
	}while(ch!=0);
		  			
return 0;		  		
}
