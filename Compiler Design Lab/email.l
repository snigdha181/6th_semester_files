%{
#include<stdio.h>
int flag=0;
%}

%%
^[a-zA-Z0-9_.]+@[a-z]+".com"|".in" flag=1;
%%

int main()
{
printf("Enter a email address: ");
yylex();
if(flag==1)
{printf("Valid Email.");}
else
{printf("Invalid Email.");}
return 0;
}

int yywrap()
{
return 1;
}
