#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>
#define f(x) x*x-3*x+2
#define g(x) 2*x-3

using namespace std;
int main()
{
	 float x0, x1, f0, f1, g0, e;
	 int iter = 1, n;
	 cout<<"Enter initial guess: ";
	 cin>>x0;
	 cout<<"Enter tolerable error: ";
	 cin>>e;
	 cout<<"Enter maximum iteration: ";
	 cin>>n;

	 do
	 {
		  g0 = g(x0);
		  f0 = f(x0);
		  if(g0 == 0.0)
		  {
			   cout<<"Mathematical Error.";
			   exit(0);
		  }
		  x1 = x0 - f0/g0;
		  cout<<"Iteration-"<< iter<<":\tRoot = "<<"\t"<< x1<< endl;
		  x0 = x1;
		  iter = iter+1;
		  if(iter > n)
		  {
			   cout<<"Not Convergent.";
			   exit(0);
		  }
		  f1 = f(x1);
	 }while(fabs(f1)>e);
	 cout<< endl<<"Approximate Root is: "<< x1;
	 return 0;
}
