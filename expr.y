%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(char *msg);
%}

%token NUM ID;
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
S   :   E   {printf("Valid\n");}
    ;
E   :   E '+' E
    |   E '-' E
    |   E '*' E
    |   E '/' E
    |   '(' E ')'
    |   ID 
    |   NUM
    ;
%%
void yyerror(char *msg){
    printf("Exist");
}

void main(){
    printf("Enter expresion");
    yyparse();
}