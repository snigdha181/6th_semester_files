%{
#include<stdio.h>
int vc=0, cc=0;
%}

%%
[ \t\n] ;
[AEIOUaeiou] {vc++;}
[^AEIOUaeiou] {cc++;}
%%

int main()
{
 printf("Enter the text: ");
 yylex();
 printf("\nNumber of vowels: %d",vc);
 printf("\nNumber of consonents: %d",cc);
}

int yywrap()
{ 
 return 1;
}
