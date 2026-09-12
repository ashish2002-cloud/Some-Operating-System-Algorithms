//Implimenting FIFO
#include<iostream>
using namespace std;
int main()
{
	int n,f,hit=0,miss=0;
	cout<<"Enter the Total numbers in reference string";
	cin>>n;
	cout<<"Enter Total no of Frames in Main Memory";
	cin>>f;
	int rs[n],main_memory[f]={-1},mmp=0;
	cout<<"Enter the reference string";
	for(int i=0;i<n;i++)
	{
		cin>>rs[i];
	}
	for(int i=0;i<n;i++)
	{
		int x=0;
		for(int j=0;j<f;j++)
		{
			if(rs[i]==main_memory[j])
			{
				hit+=1;
				x=1;
				break;
			}
		}
		if(x==0)
		{
			main_memory[mmp]=rs[i];
			mmp+=1;
			if(mmp>=f)
			{
				mmp=0;
			}
			miss+=1;
		}
	}
	float hit_ratio=(float)hit/n *100;
	float miss_ratio=(float)miss/n *100;
	cout<<endl<<"Hit Ratio is ="<<hit_ratio<<"%";
	cout<<endl<<"Miss Ratio is ="<<miss_ratio<<"%";
	return 0;
}
