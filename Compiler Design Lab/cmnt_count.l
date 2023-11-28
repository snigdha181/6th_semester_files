
%{
#include<stdio.h>
int nc=0;

%}

%%
"/*"[a-zA-Z0-9\n\t ]*"*/" {nc++;}
"//"[a-zA-Z0-9\t ]*"\n" {nc++;}

%%

int main() 
{
  printf("Enter a string: ");/*main function e 
  kaj korbe*/
  yylex();
  //commment count
  printf("The number of comment: %d\n",nc);
}

int yywrap()
{
  return -1;
}
