#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    // P0, P1, P2, P3, P4 are the Process names here
    int n, m, i, j, k;
    // Open the input file
    ifstream inputFile("input.txt");
    // Read the number of processes and resources
    inputFile >> n >> m;
    // Initialize the allocation, maximum, and need matrices
    int alloc[n][m];
    int max[n][m];
    int need[n][m];
    // Read the allocation matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            inputFile >> alloc[i][j];
        }
    }
    // Read the maximum matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            inputFile >> max[i][j];
        }
    }
    // Calculate the need matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    // Read the available resources
    int avail[m];
    for (i = 0; i < m; i++)
    {
        inputFile >> avail[i];
    }
    // Close the input file
    inputFile.close();
    // Initialize the flag array and the safe sequence array
    int f[n];
    int ans[n];
    int ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    // Check for safe sequence
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (int y = 0; y < m; y++)
                    {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }
    // Check if the sequence is safe
    int safe = 1;
    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            safe = 0;
            break;
        }
    }
    // Print the safe sequence or inform that no safe sequence exists
    if (safe)
    {
        cout << "Following is the SAFE Sequence" << endl;
        for (i = 0; i < n - 1; i++)
        {
            cout << " P" << ans[i] << " ->";
        }
        cout << " P" << ans[n - 1] << endl;
    }
    else
    {
        cout << "The given sequence is not safe" << endl;
    }
    return 0;
}
