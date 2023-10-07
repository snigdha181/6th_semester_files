#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
    return x*x - x - 2;
}
int main()
{
    float x1,x2,x0=0,tmp,e=0.001;
    int iteration=0;
    do
    {
        printf("Enter initial guess: ");
        scanf("%f %f",&x1,&x2);
        if(f(x1)*f(x2)>0)
            printf("\n\nInvalid guess\n\nType new guess again: ");
    }while(f(x1)*f(x2)>0);
    do
    {
        iteration++;
        tmp=x0;
        x0=x1-(f(x1)*(x2-x1)/(f(x2)-f(x1)));
        if(f(x1)*f(x0)<0)
            x2=x0;
        else
            x1=x0;
        printf("\nRoot = %.4f\nIteration = %d\n",x0,iteration);
    }while(fabs(tmp-x0)>e);
    getch();
}
