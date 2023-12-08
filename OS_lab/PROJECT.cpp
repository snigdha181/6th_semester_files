#include <bits/stdc++.h>
using namespace std;
int main()
{
    string inputFileName = "INPUT.txt";
    ifstream input_file(inputFileName);
    string outputFileName = "OUTPUT.txt";
    ofstream output_file(outputFileName);
    ifstream outputile("OUTPUT.txt");
    if (!outputile.is_open())
    {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    vector<int> p, arv, bt, pr;
    int id, arrival_time, burst_time, priority;
    string process_name, header;
    vector<string> prcs;
    getline(input_file, header);
    int n = 0;
    while (input_file >> id >> process_name >> burst_time >> arrival_time >> priority)
    {
        n++;
        p.push_back(id);
        prcs.push_back(process_name);
        bt.push_back(burst_time);
        arv.push_back(arrival_time);
        pr.push_back(priority);
    }
    vector<int> comp(n, 0);
    vector<int> wt(n, 0);
    vector<int> tat(n, 0);
    vector<int> completion_time(n, 0);
    vector<int> remaining_bt(bt.begin(), bt.end());
    int choice, time_quantum, idx, t;
    do
    {
        cout << "\t\t**********************************************\n";
        cout << "\t\t||\t\tProcess Scheduling          ||\n";
        cout << "\t\t**********************************************\n";
        cout << "\t\t|    1. First Come First Serve Scheduling    |\n";
        cout << "\t\t|    2. Shortest Job First Scheduling        |\n";
        cout << "\t\t|    3. Priority Scheduling                  |\n";
        cout << "\t\t|    4. Round Robin Scheduling               |\n";
        cout << "\t\t|    5. Display Output File                  |\n";
        cout << "\t\t|    6. Exit                                 |\n";
        cout << "\t\t**********************************************\n\n";
        cout << "\t\tEnter your choice: ";
        cin >> choice;
        cout << "\n\n";
        double avgwt, avgtat;
        switch (choice)
        {
         case 1: // First Come First Serve Scheduling
        {
            // Save results to output file
            output_file << "\n\t\t\t\t**  First Come First Serve Scheduling  **\n\n";
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
            output_file << "Process\t  Arrival_Time\t   Burst_Time\t  Compile_Time\t  Waiting_Time\t  Turnaround_Time\t  Working\n";
            for (int i = 0; i < n; i++)
            {
                output_file << prcs[i] << "\t\t" << arv[i] << "\t\t" << bt[i] << "\t\t" << comp[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t";
                for (int j = 0; j < bt[i]; j++)
                {
                    output_file << "*";
                }
                output_file << endl;
            }

            avgwt = (double)accumulate(wt.begin(), wt.end(), 0) / n;
            avgtat = (double)accumulate(tat.begin(), tat.end(), 0) / n;
            output_file << "\nAverage Waiting time: " << avgwt << "\n";
            output_file << "Average Turnaround time: " << avgtat << "\n\n";

            // Display results to console
            system("CLS");
            cout << "\n\t\t\t\t**  First Come First Serve Scheduling  **\n\n";
            cout << "Process\t  Arrival_Time\t   Burst_Time\t  Compile_Time\t  Waiting_Time\t  Turnaround_Time\t  Working\n";
            for (int i = 0; i < n; i++)
            {
                cout << prcs[i] << "\t\t" << arv[i] << "\t\t" << bt[i] << "\t\t" << comp[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t";
                for (int j = 0; j < bt[i]; j++)
                {
                    cout << "*";
                }
                cout << endl;
            }

            cout << "\nAverage Waiting time: " << avgwt << "\n";
            cout << "Average Turnaround time: " << avgtat << "\n\n";
        }
        break;

        case 2: // Shortest Job First Scheduling
        {
            // Save results to output file
            output_file << "\n\t\t\t\t**  Shortest Job First Scheduling  **\n\n";
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
            output_file << "Process\t  Arrival_Time\t   Burst_Time\t  Compile_Time\t  Waiting_Time\t  Turnaround_Time\t  Working\n";
            for (int i = 0; i < n; i++)
            {
                output_file << prcs[i] << "\t\t" << arv[i] << "\t\t" << bt[i] << "\t\t" << comp[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t";
                for (int j = 0; j < bt[i]; j++)
                {
                    output_file << "*";
                }
                output_file << endl;
            }

            avgwt = (double)accumulate(wt.begin(), wt.end(), 0) / n;
            avgtat = (double)accumulate(tat.begin(), tat.end(), 0) / n;
            output_file << "\nAverage Waiting time: " << avgwt << "\n";
            output_file << "Average Turnaround time: " << avgtat << "\n\n";

            // Display results to console
            system("CLS");
            cout << "\n\t\t\t\t**  Shortest Job First Scheduling  **\n\n";
            cout << "Process\t  Arrival_Time\t   Burst_Time\t  Compile_Time\t  Waiting_Time\t  Turnaround_Time\t  Working\n";
            for (int i = 0; i < n; i++)
            {
                cout << prcs[i] << "\t\t" << arv[i] << "\t\t" << bt[i] << "\t\t" << comp[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t";
                for (int j = 0; j < bt[i]; j++)
                {
                    cout << "*";
                }
                cout << endl;
            }

            cout << "\nAverage Waiting time: " << avgwt << "\n";
            cout << "Average Turnaround time: " << avgtat << "\n\n";
        }
        break;

        case 3: // Priority Scheduling
        {
            // Save results to output file
            output_file << "\n\t\t\t\t\t**  Priority Scheduling  **\n\n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1 - i; j++)
                {
                    if (pr[j] > pr[j + 1])
                    {
                        swap(arv[j], arv[j + 1]);
                        swap(bt[j], bt[j + 1]);
                        swap(prcs[j], prcs[j + 1]);
                        swap(p[j], p[j + 1]);
                        swap(pr[j], pr[j + 1]);
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
            output_file << "Process\t  Arrival_Time\t   Burst_Time\t  Compile_Time\t  Waiting_Time\t  Turnaround_Time\t  Working\n";
            for (int i = 0; i < n; i++)
            {
                output_file << prcs[i] << "\t\t" << arv[i] << "\t\t" << bt[i] << "\t\t" << comp[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t";
                for (int j = 0; j < bt[i]; j++)
                {
                    output_file << "*";
                }
                output_file << endl;
            }

            avgwt = (double)accumulate(wt.begin(), wt.end(), 0) / n;
            avgtat = (double)accumulate(tat.begin(), tat.end(), 0) / n;
            output_file << "\nAverage Waiting time: " << avgwt << "\n";
            output_file << "Average Turnaround time: " << avgtat << "\n\n";

            // Display results to console
            system("CLS");
            cout << "\n\t\t\t\t\t**  Priority Scheduling  **\n\n";
            cout << "Process\t  Arrival_Time\t   Burst_Time\t  Compile_Time\t  Waiting_Time\t  Turnaround_Time\t  Working\n";
            for (int i = 0; i < n; i++)
            {
                cout << prcs[i] << "\t\t" << arv[i] << "\t\t" << bt[i] << "\t\t" << comp[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t";
                for (int j = 0; j < bt[i]; j++)
                {
                    cout << "*";
                }
                cout << endl;
            }

            cout << "\nAverage Waiting time: " << avgwt << "\n";
            cout << "Average Turnaround time: " << avgtat << "\n\n";
        }
        break;

        case 4: // Round Robin Scheduling
        {
            output_file << "\n\t\t\t\t\t**  Round Robin Scheduling  **\n\n";
            if (n == 0)
            {
                cout << "No processes to schedule.\n\n";
                break;
            }

            cout << "Enter the time quantum for Round Robin Scheduling: ";
            cin >> time_quantum;

            t = 0;
            idx = 0;

            std::ostringstream workingProcessStream;
            workingProcessStream << "\nWorking Process";

            while (true)
            {
                bool done = true;

                for (int i = 0; i < n; i++)
                {
                    if (remaining_bt[i] > 0)
                    {
                        done = false;

                        int quantum = min(time_quantum, remaining_bt[i]);
                        remaining_bt[i] -= quantum;
                        workingProcessStream << "\nFor " << prcs[i] << " - " << quantum << "\t\t";
                        t += quantum;
                        wt[i] += (t - bt[i] - arv[i]);
                        tat[i] += (t - arv[i]);
                        completion_time[i] = t;
                    }
                }
                if (done)
                    break;
            }
            workingProcessStream << endl;
            output_file << workingProcessStream.str();
            output_file << "Process\t  Arrival_Time\t   Burst_Time\t  Completion_Time\tWaiting_Time\tTurnaround_Time\n";
            for (int i = 0; i < n; i++)
            {
                comp[i] = tat[i] + arv[i];
                tat[i]=completion_time[i]-arv[i];
                wt[i]=tat[i]-bt[i];
                output_file << prcs[i] << "\t\t" << arv[i] << "\t\t" << bt[i] << "\t\t" << completion_time[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t";
                output_file << endl;
            }
            avgwt = (double)accumulate(wt.begin(), wt.end(), 0) / n;
            avgtat = (double)accumulate(tat.begin(), tat.end(), 0) / n;
            output_file << "\nAverage Waiting time: " << avgwt << "\n";
            output_file << "Average Turnaround time: " << avgtat << "\n\n";

            // Display results to console
            system("CLS");
            cout << "\n\t\t\t\t\t**  Round Robin Scheduling  **\n\n";
            cout << workingProcessStream.str() << endl;
            cout << "Process\t  Arrival_Time\t   Burst_Time\t  Completion_Time\tWaiting_Time\tTurnaround_Time\n";
            for (int i = 0; i < n; i++)
            {
                cout << prcs[i] << "\t\t" << arv[i] << "\t\t" << bt[i] << "\t\t" << completion_time[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t";
                cout << endl;
            }
            cout << "\nAverage Waiting time: " << avgwt << "\n";
            cout << "Average Turnaround time: " << avgtat << "\n\n";
        }
        break;

        case 5:
        {
            system("CLS");
            cout << "Contents of OUTPUT.txt:\n";

            ifstream outputFileDisplay("OUTPUT.txt");
            if (!outputFileDisplay.is_open())
            {
                cerr << "Error: Unable to open output file for display." << endl;
                break;
            }
            string line;
            while (getline(outputFileDisplay, line))
            {
                cout << line << endl;
            }
            outputFileDisplay.close();
        }
        break;

        case 6: // Exit
        {
            system("CLS");
            cout << "Exiting the scheduling program...!\nThank You -_-\n";
        }
        break;

        default:
            cout << "Invalid choice.!!!\n Please enter a valid option.\n\n";
            break;
        }
    } while (choice != 6);
    output_file.close();
    return 0;
}
