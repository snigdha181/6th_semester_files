%{
#include<stdio.h>
#include<string.h>
int operators_count=0, operands_count=0;
int valid=1, top=-1, i=0, j=0;
char operands[10][10], operators[10][10], stack[100];
%}

%%
"(" {
    top++;
    stack[top] = '(';
    }
"{" {
	top++;
	stack[top] = '{';
    }
"[" {
	top++;
	stack[top] = '[';
    }
")" {
	if(stack[top]!= '('){
		valid=0;
	}
	else{
		top--;
		operators_count=0;
		operands_count=1;
	}
}
"}" {
	if(stack[top]!= '{'){
		valid=0;
	}
	else{
		top--;
		operators_count=0;
		operands_count=1;
	}
}
"]" {
	if(stack[top]!= '['){
		valid=0;
	}
	else{
		top--;
		operators_count=0;
		operands_count=1;
	}
}
"+"|"-"|"*"|"/" {
 operators_count++;
 strcpy(operators[i],yytext);
 i++;
}
[a-zA-Z] {
 operands_count++;
 strcpy(operands[j],yytext);
 j++;
}
%%
int main()
{
  int k;
  printf("Enter the arithmtic expression: ");
  yylex();
  if (operands_count>0 && (operands_count - operators_count)!=1){
    valid=0;
}
  if (valid == 1 && top == -1) {  
        printf("\nValid Expression\n");  
        printf("Operators are: \n");
        for(k=0; k<4; k++){
          puts(operators[k]);
      }
      printf("Operands are: \n");
        for(k=0; k<4; k++){
          puts(operands[k]);
      }
    }  
    else
        printf("\nInvalid Expression\n");  
  
    return 0; 
}  
int yywrap() {
 return 1;
}
