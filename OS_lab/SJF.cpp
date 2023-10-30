#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of process: ";
    cin>>n;
    int burst_time[n],process[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the burst time of process - "<<i+1<<" : ";
        cin>>burst_time[i];
        process[i]=i+1;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(burst_time[i]>burst_time[j])
            {
                int temp = burst_time[i];
                burst_time[i]=burst_time[j];
                burst_time[j]=temp;

                temp = process[i];
                process[i]=process[j];
                process[j]=temp;
            }
        }
    }
    int waiting_time=0;
    int total_waiting_time=0;
    for(int i=0; i<n; i++)
    {
        cout<<"Waiting time for process "<<process[i]<<" : "<<waiting_time<<endl;
        waiting_time= waiting_time+burst_time[i];
        total_waiting_time = total_waiting_time + waiting_time;
    }
    cout<<"Average waiting time: "<<(total_waiting_time - waiting_time)/float(n);
    return 0;
}
