#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) x*x-3*x+2
#define g(x) 2*x-3

int main()
{
    float x1,x2,f1,g0,e;
    int iteration=1,n;
    printf("Enter the initial guess: ");
    scanf("%f",&x1);
    printf("Enter the error: ");
    scanf("%f",&e);
    printf("Enter the iteration: ");
    scanf("%d",&n);
    printf("\nIteration\t\tx1\t\tf(x1)\t\tx2\t\tg(x2)\n");
    do
    {
        g0=g(x1);
        f1=f(x1);
        if(g0==0.0)
        {
            printf("Mathematical error!");
            exit(0);
        }
        x2=x1-(f1/g0);
        printf("\t%d\t\t%f\t%f\t%f\t%f\n",iteration,x1,f1,x2,g0);
        x1=x2;
        iteration++;
        if(iteration>n)
        {
            printf("Not convergent");
            exit(0);
        }
        g0=g(x2);
    }
    while(fabs(g0)>e);
    printf("\nRoot is : %f",x2);
    getch();
}
