#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,r;
// Read the input from file
    ifstream input("inp.txt");
    input>>n>>r;
    if (!input)
    {
        cout << "File not found!" << endl;
        return 1;
    }
// Read the maximum matrix
    int max[n][r];
    cout<<"\nAllocated: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            input >> max[i][j];
            if (j == r - 1)
            {
                cout << max[i][j] << endl;
            }
            else
            {
                cout << max[i][j] << " ";
            }
        }
    }
// Read the allocation matrix
    cout<<"\nRequest: \n";
    int allocation[n][r];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            input >> allocation[i][j];
            if (j == r - 1)
            {
                cout << allocation[i][j] << endl;
            }
            else
            {
                cout << allocation[i][j] << " ";
            }
        }
    }
// Read the need matrix
    int need[n][r];
    cout<<"\nNeed:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
            if (j == r - 1)
            {
                cout << need[i][j] << endl;
            }
            else
            {
                cout << need[i][j] << " ";
            }
        }
    }
// Check if the system is in a safe state
    bool safe = true;
    int available[n][r];
    cout<<"\nAvailable:\n";
    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<r; j++)
        {
            available[i][j] = max[0][i];
            if (j == r - 1)
            {
                cout << available[i][j] << endl;
            }
            else
            {
                cout << available[i][j] << " ";
            }
        }
    }
// Initialize the finished set
    set<int> finished;
// Initialize the running set
    set<int> running;
    running.insert(0);
// Iterate over all processes
    for (int i = 1; i < n; i++)
    {
// Check if the process can be allocated resources**
        for (int j = 0; j < r; j++)
        {
            if (need[i][j] > available[i][j])
            {
                safe = false;
                break;
            }
        }
// If the process can be allocated resources, add it to the running set**
        if (safe)
        {
            running.insert(i);
        }
// Update the available resources**
        for (int j = 0; j < r; j++)
        {
            available[i][j] -= need[i][j];
        }
// If the running set is empty, the system is not in a safe state**
        if (running.empty())
        {
            safe = false;
            break;
        }
    }
// Print the result
    if (safe)
    {
        cout << "\nThe system is in a safe state." << endl;
    }
    else
    {
        cout << "\nThe system is not in a safe state." << endl;
    }

    return 0;
}
