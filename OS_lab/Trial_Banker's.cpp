#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r, c, i, j, k;
    ifstream file("inp.txt");
    file >> r >> c;

    int R[r][c], A[r][c], total_allocated = 0, resources = 12;

    cout << "\nRequired: ";
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            file >> R[i][j];
            cout << R[i][j] << "  ";
        }
    }

    cout << "\n\nAllocated: ";
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            file >> A[i][j];
            cout << A[i][j] << "  ";
        }
    }

int available[i][j];
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            total_allocated += R[i][j];

    //= resources - total_allocated;

        }
    }

cout << "\n\nAvailable: " << available[i][j];

    file.close();

    // Sorting based on Need matrix
    /*for(i = 0; i < r - 1; i++)
    {
        for(j = 0; j < r - 1 - i; j++)
        {
            if(N[j][0] > N[j + 1][0])
            {
                for(k = 0; k < c; k++)
                {
                    swap(N[j][k], N[j + 1][k]);
                    swap(R[j][k], R[j + 1][k]);
                    swap(A[j][k], A[j + 1][k]);
                }
            }
        }
    }

    cout << "\n\nSorted Need: \n";
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            cout << N[i][j] << "  ";
        }
    }

    cout << "\nSorted resources: \n";
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            cout << R[i][j] << "  ";
        }
    }

    cout << "\nSorted allocated: \n";
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            cout << A[i][j] << " ";
        }
    }*/

    bool safe = true;
    for(i = 0; i < r; i++)
    {
        for(j=0 ; j<c; j++)
        {
            if(available[i][j] > R[i][j])
            {
                safe = false;
                break;
            }
        }
    }
    if(safe)
    {
        cout << "\n\nSafe State...";
    }
    else
    {
        cout << "\n\nUnsafe State..!!!";
    }

    return 0;
}
