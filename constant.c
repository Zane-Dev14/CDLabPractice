//a=3+5
//b=a+3
//c=b*2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct { char var; int val;}tab[10]; 
int n=0;
int getVal(char var){
    if(isdigit(var)){return var-'0';}
    for(int i=0;i<n;i++){
        if (tab[i].var==var){ return tab[i].val; }
    }printf("Eror, coudlnt find"); return -1;
}
void main(){
    char input[100];
    int statements;
    printf("\nEnter number of statements");
    scanf("%d",&statements);
    for(int k=0;k<statements;k++){
        printf("\nEnter statement %d: \n",k+1);
        scanf("%s",input);
        char lhs=input[0];
        char op1=input[2];
        char op=input[3];
        char op2=input[4];
        int arg1=getVal(op1);
        int arg2=getVal(op2);
        int res=0;
        switch(op){
            case '+': res=arg1+arg2;break;
            case '-': res=arg1-arg2;break;
            case '*': res=arg1*arg2;break;
            case '/': res=arg1/arg2;break;
        }
        tab[n].var=lhs;
        tab[n++].val=res;
        printf("%c = %d",lhs,res);
    }
}