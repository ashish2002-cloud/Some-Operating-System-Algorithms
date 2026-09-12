//Deadlock Avoidance using Bankers Alogrithm
#include<iostream>
using namespace std;
int main()
{
	int p,r,sum=0;
	cout<<"Enter Number of processes"<<endl;
	cin>>p;
	cout<<"Enter Number of Resources"<<endl;
	cin>>r;
	int c_allocated[p][r],r_need[p][r],total_instances[r],remaining[p][r],available[r],seq[p];
	for(int i=0;i<r;i++)
	{
		cout<<"Enter total instances of Resource"<<i+1<<endl;
		cin>>total_instances[i];
	}
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			cout<<"Enter current allocated for process"<<i+1<<"and resource"<<j+1<<endl;
			cin>>c_allocated[i][j];
			cout<<"Enter total need of process"<<i+1<<"and resource"<<j+1;
			cin>>r_need[i][j];
		}
	}
	//calculation of remaining need
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			remaining[i][j]=r_need[i][j]-c_allocated[i][j];
		}
	}
	//calculation of current available
	for(int i=0;i<r;i++)
	{
		sum=0;
		for(int j=0;j<p;j++)
		{
			sum+=c_allocated[j][i];
		}
		available[i]=total_instances[i]-sum;
	}
	//actual computation of deadlock detection
	int completed=0;
	bool finished[p]={false};
	int x=0;
	while(completed<p)
	{
		bool found=false;
		for(int i=0;i<p;i++)
		{
			int count=0;
			for(int j=0;j<r;j++)
			{
				if(finished[i]==false && remaining[i][j]<=available[j])
				{
					count++;
				}
				if(count==r && finished[i]==false)
				{
					finished[i]=true;
					found=true;
					
					for(int k=0;k<r;k++)
					{
						available[k]+=c_allocated[i][k];
						remaining[i][k]=0;
					}
					completed++;
					seq[x]=i;
					x++;
			}
			}
			
		}
		if(found==false)
		{
			cout<<"Deadlock Occoured";
			break;
		}
			
	}
	for(int i=0;i<p;i++)
			{
				cout<<"Sequence of execution is ="<<seq[i]<<" ";
			}
	return 0;
}
