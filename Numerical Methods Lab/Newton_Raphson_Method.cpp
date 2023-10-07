#include <iostream>
#include <math.h>
using namespace std;
float f(float x)
{
     return  x*x - 3*x + 2 ;
}
float d(float x)
{
     return  2*x - 3 ;
}
int main()
{   float x0,iteration=0,x1,e=0.0001;
    cout<<"Enter the initial guess: ";
    cin>>x1;
    do
    {   iteration++;
        x1=x0-(f(x0)/d(x0));
        cout<<"\nIteration\tRoot\n"<<"    "<<iteration<<"\t\t"<<x1;
        cout<<endl;
        x0=x1;
        cout<<endl;
    }while(abs(f(x1))>e);
    cout<<"\nThe Approximate Root is : "<<x1;
   return 0;
}
