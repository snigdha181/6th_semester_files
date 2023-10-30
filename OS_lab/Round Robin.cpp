#include<iostream>
using namespace std;

int main()
{
    int n, timeQuantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum: ";
    cin >> timeQuantum;

    int burst_time[n], remaining_time[n];
    int current_process = 0;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter the burst time of process " << i + 1 << ": ";
        cin >> burst_time[i];
        remaining_time[i] = burst_time[i];
    }

    int time = 0;
    float total_waiting_time = 0;

    while(true)
    {
        if (remaining_time[current_process] <= timeQuantum)
        {
            time += remaining_time[current_process];
            total_waiting_time += time - burst_time[current_process];
            remaining_time[current_process] = 0;
        }
        else
        {
            time += timeQuantum;
            remaining_time[current_process] -= timeQuantum;
        }

        int next_process = (current_process + 1) % n;
        bool all_processes_done = true;

        for (int i = 0; i < n; i++)
        {
            if (remaining_time[i] > 0)
            {
                all_processes_done = false;
                break;
            }
        }

        if (all_processes_done)
            break;

        while (next_process != current_process)
        {
            if (remaining_time[next_process] > 0)
            {
                current_process = next_process;
                break;
            }
            next_process = (next_process + 1) % n;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Waiting time for process " << i + 1 << ": " << time - burst_time[i] << endl;
    }

    cout << "Average waiting time: " << total_waiting_time / n << endl;
    return 0;
}
