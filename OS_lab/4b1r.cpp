#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int main() {
    ifstream file_("processes.txt");
    vector<int> p;
    vector<int> a;
    vector<int> b;
    int tempProcess;
    int tempArrivalTime;
    int tempBurstTime;
    if (file_.is_open()) {
        while (file_ >> tempProcess >> tempArrivalTime >> tempBurstTime) {
            p.push_back(tempProcess);
            a.push_back(tempArrivalTime);
            b.push_back(tempBurstTime);
        }
        file_.close();
    } else {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }
    int n = p.size();  // Number of processes
    if (n == 0) {
        cerr << "No processes found in the input file." << endl;
        return 1;
    }
    // Sorting processes by arrival time and burst time (SJF)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j] || (a[i] == a[j] && b[i] > b[j])) {
                swap(p[i], p[j]);
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
        }
    }
    vector<int> c(n);  // Completion time
    vector<int> tat(n);  // Turnaround time
    vector<int> wt(n);   // Waiting time
    int tt = 0;
    int t_tat = 0;
    int t_wt = 0;
    cout << "Process\tArrival_time\tBurst_time\tTurnaround_time\tWaiting_time" << endl;
    for (int i = 0; i < n; i++) {
        c[i] = max(tt, a[i]) + b[i];
        tat[i] = c[i] - a[i];
        wt[i] = tat[i] - b[i];
        tt = c[i];
        t_tat += tat[i];
        t_wt += wt[i];
        cout << "P" << p[i] << "\t\t" << a[i] << "\t\t" << b[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
    }
    float avg_tat = static_cast<float>(t_tat) / n;
    float avg_wt = static_cast<float>(t_wt) / n;
    cout << "Avg tat: " << avg_tat << endl;
    cout << "Avg waiting time: " << avg_wt << endl;
    return 0;
}
