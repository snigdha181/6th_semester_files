
%{
#include<stdio.h>
int sc=0, wc=0, lc=0, cc=0;
%}

%%
[\n] {lc++; cc=cc+yyleng;}
[' '\t] {sc++; cc=cc+yyleng;}
[A-Za-z]+ {wc++; cc=cc+yyleng;}
%%

int main()
{
  printf("Enter a string: ");
  yylex();
  printf("The number of lines: %d\n",lc);
  printf("The number of spaces: %d\n",sc);
  printf("The number of words: %d\n",wc);
  printf("The number of characters: %d\n",cc);
}

int yywrap()
{
  return 1;
}
