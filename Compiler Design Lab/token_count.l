%{
#include<stdio.h>
int tc=0;

%}

%%
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"for"|"if"|"goto"|"float"|"int"|"long"|"register"|"return"|"signed"|"static"|"sizeof"|"short"|"struct"|"switch"|"typedef"|"union"|"void"|"while"|"volatile"|"unsigned" {tc++;}
[a-z|A-Z|_][a-z|A-Z|0-9|_]* {tc++;}
"("|")"|"{"|"}"|"["|"]"|","|";" {tc++;}
"+"|"-"|"*"|"/"|"%"|"++"|"--"|"=="|"!="|"<"|">"|"<="|">="|"&&"|"||"|"!"|"&"|"|"|"+="|"-="|"*="|"/="|"%="|"^"|"~"|">>"|"<<"|"?" {tc++;}
[0-9]+ {tc++;}
[0-9]+"."[0-9]+ {tc++;}
"$"|"_" {tc++;}
%%

int main() 
{
  printf("Enter the text: ");
  yylex();
  printf("The number of token: %d\n",tc);
}

int yywrap()
{
  return -1;
}
