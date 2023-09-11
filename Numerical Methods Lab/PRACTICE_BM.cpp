#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
    return x*x*x - 2*x - 5;
}
int main()
{
    float x1,x2,x0=0,tmp,e=0.001;
    int iteration=0;
    do
    {
        printf("Enter two initial guesses: ");
        scanf("%f %f",&x1,&x2);
        if(f(x1)*f(x2)>=0)
            printf("\n Invalid Guesses\n\nPlease Guesses Again: ");
    }
    while(f(x1)*f(x2)>0);
    do
    {
        iteration++;
        tmp=x0;
        x0=(x1+x2)/2;
        if(f(x0)==0.0)
        {
            printf("\nRoot = %.4f",x0);
            break;
        }
        else if(f(x1)*f(x0)<0)
        {
            printf("\nRoot = %.4f",x0);
            x2=x0;
        }
        else
        {
            printf("\nRoot = %.4f",x0);
            x1=x0;
        }
        printf("\n Iteration = %d",iteration);
    }
    while(fabs(tmp-x0)>e);
    printf("\n\nAccurate root is : %.4f",x0);
    getch();
}

