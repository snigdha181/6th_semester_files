#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream input_file("INPUT_ANIK.txt");
    vector<int> p, arv, bt;
    int id, arrival_time, burst_time;
    string process_name, header;
    vector<string> prcs;
    getline(input_file, header);
    int n = 0;
    while (input_file >> id >> process_name >> burst_time >> arrival_time)
    {
        n++;
        p.push_back(id);
        prcs.push_back(process_name);
        bt.push_back(burst_time);
        arv.push_back(arrival_time);
    }
    vector<int> comp(n, 0);
    vector<int> wt(n, 0);
    vector<int> tat(n, 0);
    input_file.close();
    int choice,time_quantum;
    do
    {
        cout << "1. First Come First Serve Scheduling\n";
        cout << "2. Shortest Job First Scheduling\n";
        cout << "3. Priority Scheduling\n";
        cout << "4. Round Robin Scheduling\n";
        cout << "0. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<"\n\n";
        double avgwt, avgtat;  // Declare outside the switch

        switch (choice)
        {
        case 1: // First Come First Serve Scheduling
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1 - i; j++)
                {
                    if (arv[j] > arv[j + 1])
                    {
                        swap(arv[j], arv[j + 1]);
                        swap(bt[j], bt[j + 1]);
                        swap(prcs[j], prcs[j + 1]);
                        swap(p[j], p[j + 1]);
                    }
                }
            }

            comp[0] = arv[0] + bt[0];
            tat[0] = comp[0] - arv[0];
            wt[0] = tat[0] - bt[0];
            for (int i = 1; i < n; i++)
            {
                if (arv[i] > comp[i - 1])
                    comp[i] = arv[i] + bt[i];
                else
                    comp[i] = comp[i - 1] + bt[i];
                tat[i] = comp[i] - arv[i];
                wt[i] = tat[i] - bt[i];
            }

            cout << "Process\t  Arrival_Time\t   Burst_Time\t  Compile_Time\t  Waiting_Time\t  Turnaround_Time\t  Working\n";
            for (int i = 0; i < n; i++)
            {
                cout << prcs[i] << "\t\t" << arv[i] << "\t\t" << bt[i] << "\t\t" << comp[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t";
                for(int j=0; j<bt[i]; j++)
                {
                    cout<<"*";
                }
                cout<<endl;
            }

            avgwt = (double)accumulate(wt.begin(), wt.end(), 0) / n;
            avgtat = (double)accumulate(tat.begin(), tat.end(), 0) / n;
            printf("\nAverage Waiting time: %.2lf\n", avgwt);
            printf("Average Turnaround time: %.2lf\n", avgtat);
            cout<<"\n\n";
            break;

        case 2: // Shortest Job First Scheduling
            // Sort processes based on burst time
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1 - i; j++)
                {
                    if (bt[j] > bt[j + 1])
                    {
                        swap(arv[j], arv[j + 1]);
                        swap(bt[j], bt[j + 1]);
                        swap(prcs[j], prcs[j + 1]);
                        swap(p[j], p[j + 1]);
                    }
                }
            }

            comp[0] = arv[0] + bt[0];
            tat[0] = comp[0] - arv[0];
            wt[0] = tat[0] - bt[0];

            for (int i = 1; i < n; i++)
            {
                comp[i] = comp[i - 1] + bt[i];
                tat[i] = comp[i] - arv[i];
                wt[i] = tat[i] - bt[i];
            }

           cout << "Process\t  Arrival_Time\t   Burst_Time\t  Compile_Time\t  Waiting_Time\t  Turnaround_Time\t  Working\n";
            for (int i = 0; i < n; i++)
            {
                cout << prcs[i] << "\t\t" << arv[i] << "\t\t" << bt[i] << "\t\t" << comp[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t";
                for(int j=0; j<bt[i]; j++)
                {
                    cout<<"*";
                }
                cout<<endl;
            }

            avgwt = (double)accumulate(wt.begin(), wt.end(), 0) / n;
            avgtat = (double)accumulate(tat.begin(), tat.end(), 0) / n;
            printf("Avg Waiting time: %.2lf\n", avgwt);
            printf("Avg Turnaround time: %.2lf\n", avgtat);
            cout<<"\n\n";
            break;

        case 4: // Round Robin Scheduling
            if (n == 0)
            {
                cout << "No processes to schedule.\n\n";
                break;
            }

            cout << "Enter the time quantum for Round Robin Scheduling: ";
            cin >> time_quantum;

            vector<int> remaining_bt(bt.begin(), bt.end()); // Copy burst times for tracking remaining time

            int t = 0; // Current time

            while (true)
            {
                bool done = true;

                for (int i = 0; i < n; i++)
                {
                    if (remaining_bt[i] > 0)
                    {
                        done = false;

                        if (remaining_bt[i] > time_quantum)
                        {
                            t += time_quantum;
                            remaining_bt[i] -= time_quantum;
                        }
                        else
                        {
                            t += remaining_bt[i];
                            wt[i] = t - bt[i] - arv[i];
                            tat[i] = t - arv[i];
                            remaining_bt[i] = 0;
                        }
                    }
                }

                if (done)
                    break;
            }

            cout << "Process\t  Arrival_Time\t   Burst_Time\t  Compile_Time\t  Waiting_Time\t  Turnaround_Time\t  Working\n";
            for (int i = 0; i < n; i++)
            {
                comp[i] = tat[i] + arv[i];
                cout << prcs[i] << "\t\t" << arv[i] << "\t\t" << bt[i] << "\t\t" << comp[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t";
                for(int j=0; j<bt[i]; j++)
                {
                    cout<<"*";
                }
                cout<<endl;
            }

            avgwt = (double)accumulate(wt.begin(), wt.end(), 0) / n;
            avgtat = (double)accumulate(tat.begin(), tat.end(), 0) / n;
            printf("Avg Waiting time: %.2lf\n", avgwt);
            printf("Avg Turnaround time: %.2lf\n", avgtat);
            cout << "\n\n";
            break;

        }
    }
    while (choice != 0);
    return 0;
}
