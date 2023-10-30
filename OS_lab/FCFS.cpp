#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of process: ";
    cin>>n;
    int burst_time[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the burst time of process - "<<i+1<<" : ";
        cin>>burst_time[i];
    }
    int waiting_time=0;
    int total_waiting_time=0;
    for(int i=0; i<n; i++)
    {
        cout<<"Waiting time for process "<<i+1<<" : "<<waiting_time<<endl;
        waiting_time= waiting_time+burst_time[i];
        total_waiting_time = total_waiting_time + waiting_time;
    }
    cout<<"Average waiting time: "<<(total_waiting_time - waiting_time)/float(n);
    return 0;
}
