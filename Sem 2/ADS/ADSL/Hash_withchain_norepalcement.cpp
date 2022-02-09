#include<iostream>
using namespace std;

//f(x) = x % n

int main()
{
	int *arr,*occupied,*chain;
	int n,x,flag=0,cnt=0,found=0;
	int i,j,k;
	
	cout<<"\n\n\tEnter Size of Array	:	";
	cin>>n;
	
	arr=new int[n];
	occupied=new int[n];
	chain=new int[n];
	
	for(i=0;i<n;i++)
	{
		occupied[i]=0;
		arr[i]=0;
		chain[i]=-1;
	}
	
	
	
	while(cnt<n)
	{
		cout<<"\n\n\tEnter Element	or -1	:	";
		cin>>x;
		if(x==-1)
		{
			break;
		}
		i=(x%n);
		
		if(occupied[i]==0)
		{
			arr[i]=x;
			occupied[i]=1;
			cnt++;
			flag=1;
		}
		else
		{
			if(i!=(arr[i]%n) && occupied[i]==1)
			{
				j=(i+1)%n;
				while(j!=i)
				{
					if((arr[j]%n)==i && occupied[i]==1)
					{
						found=1;
						i=j;
						break;
					}
					j=(j+1)%n;
				}
				if(found==0)
				{
					j=(i+1)%n;
					while(j!=i)
					{
						if(occupied[j]==0)
						{
							arr[j]=x;
							occupied[j]=1;
							cnt++;
							//chain[i]=j;
							flag=1;
							break;
						}
						
						j=(j+1)%n;
					}
				}
			}
			
			
			
		
				
			if(chain[i]==-1)
			{
				j=(i+1)%n;
				while(j!=i)
				{
					if(occupied[j]==0)
					{
						arr[j]=x;
						occupied[j]=1;
						cnt++;
						chain[i]=j;
						flag=1;
						break;
					}
					
					j=(j+1)%n;
				}
			}
			else
			{				
				
				
				j=i;
				while(chain[j]!=-1)
				{
					j=chain[j];
				}
				k=(j+1)%n;
				
				while(k!=j)
				{
					
					if(occupied[k]==0)
					{
						arr[k]=x;
						occupied[k]=1;
						cnt++;
						chain[j]=k;
						flag=1;
						break;
					}
					
					k=(k+1)%n;
				}	
			}
	
		
			
			
			
			
		}
		
	}
	
	
	cout<<"\n\n\tIndex\tarray \toccupied \tchain";
	
	for(i=0;i<n;i++)
	{
		cout<<"\n\n\t"<<i<<"\t"<<arr[i]<<"\t"<<occupied[i]<<"\t\t"<<chain[i];
	}
	
	
	
	
	return 0;	
}
