#include<iostream>
using namespace std;

int main()
{
    int n,f,i,hit=0,miss=0;
    
    cout<<"Enter No of Frames in Main Memory: ";
    cin>>f;

    cout<<"Enter Total no of reference strings: ";
    cin>>n;

    int rs[n], mm[f], last[f];

    cout<<"Enter the Reference strings: ";
    for(i=0;i<n;i++)
        cin>>rs[i];

    // initialize memory and last used
    for(i=0;i<f;i++)
    {
        mm[i] = -1;
        last[i] = -1;
    }

    for(int count=0; count<n; count++)
    {
        int element = rs[count];
        int found = 0;

        // check hit
        for(i=0;i<f;i++)
        {
            if(mm[i]==element)
            {
                hit++;
                last[i] = count; // update recent use
                found = 1;
                break;
            }
        }

        if(found==0)
        {
            miss++;

            // check empty frame
            int empty = -1;
            for(i=0;i<f;i++)
            {
                if(mm[i]==-1)
                {
                    empty = i;
                    break;
                }
            }

            if(empty != -1)
            {
                mm[empty] = element;
                last[empty] = count;
            }
            else
            {
                // find least recently used
                int min = last[0], pos = 0;
                for(i=1;i<f;i++)
                {
                    if(last[i] < min)
                    {
                        min = last[i];
                        pos = i;
                    }
                }

                mm[pos] = element;
                last[pos] = count;
            }
        }
    }

    float hit_ratio = (float)hit/n*100;
    float miss_ratio = (float)miss/n*100;

    cout<<"\nHit Ratio="<<hit_ratio<<"%";
    cout<<"\nMiss Ratio="<<miss_ratio<<"%";

    return 0;
}
