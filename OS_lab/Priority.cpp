#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    int burst_time[n], priority[n], waiting_time=0, total_waiting_time = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the burst time of process " << i + 1 << ": ";
        cin >> burst_time[i];
        cout << "Enter the priority of process " << i + 1 << ": ";
        cin >> priority[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (priority[i] > priority[j])
            {
                int temp = burst_time[i];
                burst_time[i]=burst_time[j];
                burst_time[j]=temp;

                temp = priority[i];
                priority[i]=priority[j];
                priority[j]=temp;
            }
        }
        cout << "Waiting time for process " << i + 1 << ": " << waiting_time << endl;
        total_waiting_time += waiting_time;
        waiting_time += burst_time[i];
    }
    cout << "Average waiting time: " <<float(total_waiting_time) / n << endl;
    return 0;
}
