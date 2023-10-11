%{
#include<stdio.h>
int cwc=0;
%}

%%
[A-Z]+[ \t\n] {printf("%s\n",yytext);cwc++;}
. ;
%%

int main()
{
 printf("Enter the text: ");
 yylex();
 printf("\nNumber of capital words are: %d",cwc);
}

int yywrap()
{ 
 return 1;
}
