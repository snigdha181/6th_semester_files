#include<stdio.h>
//function used is x^3-2x-5
double func(double x)
{
    return x*x*x - 2*x -5;
}
double e=0.01;
double x0;
void bisection(double x1,double x2)
{
    if(func(x1) * func(x2) >= 0)
    {
        printf("Incorrect x1 and x2");
        return;
    }
    x0 = x1;
    while ((x2-x1) >= e)
    {
        x0 = (x1+x2)/2;
        if (func(x0) == 0.0){
            printf("Root = %lf\n",x0);
            break;
        }
        else if (func(x0)*func(x1) < 0){
                printf("Root = %lf\n",x0);
                x2 = x0;
        }
        else{
                printf("Root = %lf\n",x0);
                x1 = x0;
        }
    }
}
int main()
{
    double x1,x2;
    x1=2;
    x2=3;
    printf("The function used is x^3-2x-5\n");
    printf("x1 = %lf\n",x1);
    printf("x2 = %lf\n",x2);
    bisection(x1,x2);
    printf("\n");
    printf("Accurate Root calculated is = %lf\n",x0);
    return 0;
}
