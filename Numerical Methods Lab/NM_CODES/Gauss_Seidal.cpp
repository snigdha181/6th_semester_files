#include <bits/stdc++.h>
using namespace std;
int main()
{
    const int n=3;
    double a[n][n]= {{2,-1,0},{-1,2,-1},{0,-1,2}};
    double b[n]= {7,1,1} ;
    double x[n]= {0,0,0} ;
    double y[n];
    int m=0, i=0,j=0;
    cout << "\nEnter the number of iterations :";
    cin >> m;
    while (m>0)
    {
        for (i=0; i < n; i++)
        {
            y[i] = (b[i]/a[i][i]);
            for (j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                y[i] = y[i]- ((a[i][j] / a[i][i]) * x[j]);
                x[i] = y[i];
            }
            cout<<"x"<<i+1<<" = "<<y[i]<<"\t";
        }
        cout << "\n";
        m--;
    }
    cout<<"\nApproximate solution is: ";
    for (int i=0; i < n; ++i)
    {
        cout <<"\nx"<<i+1<<"= "<<static_cast<int> (round (x[i]));
    }
    return 0;
}
