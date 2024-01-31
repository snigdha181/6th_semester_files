#include<bits/stdc++.h>
#define f(x) x*x*x - 2*x -5
using namespace std;
int main()
{
    float x1,x2,x0=0,tmp,e=0.001;
    int iteration=0;
    do
    {
        cout<<"Enter two initial guesses: ";
        cin>>x1>>x2;
        if(f(x1)*f(x2)>=0)
            cout<<"\n Invalid Guesses\n\nPlease Guesses Again: ";
    }
    while(f(x1)*f(x2)>0);
    do
    {
        iteration++;
        tmp=x0;
        x0=(x1+x2)/2;
        if(f(x0)==0.0)
        {
            cout<<"\nRoot = "<<x0;
            break;
        }
        else if(f(x1)*f(x0)<0)
        {
            cout<<"\nRoot = "<<x0;
            x2=x0;
        }
        else
        {
            cout<<"\nRoot = "<<x0;
            x1=x0;
        }
        cout<<"\tIteration = "<<iteration;
    }
    while(fabs(tmp-x0)>e);
    cout<<"\n\nAccurate root is : "<<x0;
   return 0;
}
