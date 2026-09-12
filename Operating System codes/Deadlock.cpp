#include<iostream>
using namespace std;
int main()
{
	int p,r;
	cout<<"Enter the total no of processes";
	cin>>p;
	cout<<"Enter the total no of resources";
	cin>>r;
	int c_allocated[p][r],max_need[p][r],remaining_n[p][r],sequence[p],instances[r],c_available[r];
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			cout<<"Enter current allocated for process"<<i+1<<"And resources"<<j+1;
			cin>>c_allocated[i][j];
			cout<<"Enter max need for process"<<i+1<<"And resources"<<j+1;
			cin>>max_need[i][j];
		}
	}
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			remaining_n[i][j]=max_need[i][j]-c_allocated[i][j];
		}
	}
	for(int i=0;i<r;i++)
	{
		cout<<"Enter total instances for resource"<<i+1;
		cin>>instances[i];
	}
	for(int i=0;i<r;i++)
	{
		int sum=0;
		for(int j=0;j<p;j++)
		{
			sum=sum+c_allocated[j][i];
		}
		c_available[i]=instances[i]-sum;
	}
	int completed=0;
	int finished[p]={0};
	while(completed<p)
	{
		bool found=false;
		for(int i=0;i<p;i++)
		{
			int count=0;
			for(int j=0;j<r;j++)
			{
				if(finished[i]==0 && remaining_n[i][j]<=c_available[j])
				{
					count++;
				}
			}
			if(count==r)
			{
				found=true;
				completed++;
				sequence[completed-1]=i;
				for(int k=0;k<r;k++)
				{
					c_available[k]+=c_allocated[i][k];
				}
				finished[i]=1;
			}
		}
		if(found==false)
		{
			cout<<"Deadlock";
			break;
		}
	}
	int cou=0;
	for(int i=0;i<p;i++)
	{
		if(finished[i]==1)
		{
			cou++;
		}
	}
	if(cou==p)
	{
		cout<<"No Deadlock";
	}
	for(int i=0;i<p;i++)
	{
		cout<<sequence[i];
	}
	return 0;	
}
