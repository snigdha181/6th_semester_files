#include <bits/stdc++.h>
#define f(x) (pow(x, 3) - 2 * x - 5)
using namespace std;
int main()
{
    double e = 0.01, x0, x1=2, x2=3;
    if (f(x1) * f(x2) >= 0)
    {
        cout << "Incorrect x1 and x2" << endl;
        return 1;
    }
    x0 = x1;
    while ((x2 - x1) >= e)
    {
        x0 = (x1 + x2) / 2;
        if (f(x0) == 0.0)
        {
            cout << "Root = " << x0 << endl;
            break;
        }
        else if (f(x0) * f(x1) < 0)
        {
            cout << "Root = " << x0 << endl;
            x2 = x0;
        }
        else
        {
            cout << "Root = " << x0 << endl;
            x1 = x0;
        }
    }
    cout << endl;
    cout << "Accurate Root is = " << x0 << endl;
    return 0;
}
