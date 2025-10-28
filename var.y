%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *msg);
int yylex(void);
%}

%token VAR INVALID


%%
S : VAR{printf("VALID");}
  | INVALID{printf("INVALID");}
  ;
%%
void yyerror(char *msg){
    printf("Exit");
}
void main(){
    printf("Enter statement");
    yyparse();
}