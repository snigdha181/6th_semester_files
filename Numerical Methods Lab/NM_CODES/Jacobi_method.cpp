#include<bits/stdc++.h>
using namespace std;
int main()
{
    const int n = 3;
    const double A[n][3] = {{2, 1, 1},{3, 5, 2},{2, 1, 4}};
    const double b[n] = {5, 15, 8};
    double x[n] = {0};
    int p = n, q;
    cout << setprecision(4) << fixed;
    cout << "Enter the number of iterations: ";
    cin >> q;
    cout<<"\nx1\tx2\tx3\n";
    while (q--)
    {
        double y[n] = {0};
        for (int i = 0; i < p; i++)
        {
            y[i] = b[i] / A[i][i];
            for (int j = 0; j < p; j++)
            {
                if (j != i)
                    y[i] -= (A[i][j] / A[i][i]) * x[j];
            }

        }
        for (int i = 0; i < p; i++)
        {
            x[i] = y[i];
            cout <<x[i] << '\t';
        }
        cout << '\n';
    }
    cout << "\nSolution:\n";
    for (int i = 0; i < p; i++)
    {
        cout << "x" << i + 1 << " = " <<static_cast<int> (round(x[i])) << '\n';
    }
    return 0;
}
