#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    string name;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turn_around_time;
};

bool compareArrivalTime(const Process &a, const Process &b) {
    return a.arrival_time < b.arrival_time;
}

int main() {
    vector<Process> processes;
    ifstream inputFile("processes.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the file 'processes.txt'." << endl;
        return 1;
    }

    string line;
    getline(inputFile, line);  // Read and discard the header line
    while (getline(inputFile, line)) {
        istringstream iss(line);
        Process process;
        iss >> process.id >> process.name >> process.burst_time >> process.arrival_time;
        processes.push_back(process);
    }

    inputFile.close();

    int n = processes.size();
    int current_time = 0;

    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), compareArrivalTime);

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turn_around_time = processes[i].waiting_time + processes[i].burst_time;
        current_time += processes[i].burst_time;
    }

    // Output the chart with information
    cout << "Process\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << processes[i].name << "\t" << processes[i].waiting_time << "\t\t"
             << processes[i].turn_around_time << endl;
    }

    return 0;
}
