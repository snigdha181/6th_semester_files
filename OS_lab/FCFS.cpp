#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of process: ";
    cin>>n;
    int bt[n],art[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the burst time of process"<<i+1<<": ";
        cin>>bt[i];
        cout<<"Enter the arrival time of process"<<i+1<<": ";
        cin>>art[i];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(art[i]>art[j])
            {
                int temp=art[i];
                art[i]=art[j];
                art[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    }
    int wt=0,tt=0;
    cout<<"Process\t\t Waiting time\n";
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<"\t\t"<<wt<<endl;
        wt=wt+bt[i];
        tt=tt+wt;
    }
    cout<<"Average waiting time : "<<(tt-wt)/float(n);
    return 0;
}
