%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(char *msg);
%}
%token NUM
%left '+' '-'
%left '*' '/'
%left '(' ')'
 
%%
S   :   E    {printf("Result: %d",$1);}
    ;  
E   :   E '+' E {$$=$1+$3;}
    |   E '-' E {$$=$1-$3;}
    |   E '*' E {$$=$1*$3;}
    |   E '/' E {$$=$1/$3;}
    |   '(' E ')' {$$=$2;}
    |   NUM {$$=$1;}
    ;
    
%%
void yyerror(char *msg){
    printf("exit");
}
void main(){
    printf("Enter expression: ");
    yyparse();
}