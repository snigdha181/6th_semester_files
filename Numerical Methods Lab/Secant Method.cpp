#include<iostream>
#include<math.h>
#include<stdlib.h>
#define f(x) x*x-4*x-10
using namespace std;
int main()
{
    float x1,x2,x3,f1,f2,f3,e;
    int i=1,n;
    cout<<"Enter initial guesses: ";
    cin>>x1>>x2;
    cout<<"Enter tolerable no: ";
    cin>>e;
    cout<<"Enter maximum iteration: ";
    cin>>n;
    do
    {
        f1=f(x1);
        f2=f(x2);
        if(f1==f2)
        {
            cout<<"\nMathematical error...!";
            exit(0);
        }
        x3=x2-f2*(x2-x1)/(f2-f1);
        f3=f(x3);
        cout<<"\nIteration-"<<i<<"\t"<<"Root: "<<x3;
        x1=x2;
        x2=x3;
        f1=f2;
        f2=f3;
        i++;
        if(i>n)
        {
            cout<<"\nNot convergent";
            exit(0);
        }
    }while(fabs(f3)>e);
    cout<<"\nApproximate root: "<<x3;
    return 0;
}
