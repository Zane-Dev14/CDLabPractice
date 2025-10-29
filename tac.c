#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tempCount=0;

void newTemp(char *temp){
    sprintf(temp,"t%d",++tempCount);
}

int precedence(char op){
    switch(op){
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        default: return 0;
    }
}   

void generateTAC(char exp[]){
    int top=-1; int k=0;
    char opStack[100],post[100];

    for(int i=0;exp[i];i++){
        char c=exp[i];
        if(isalnum(c)){
            post[k++]=c;}
        else if(c=='('){
            opStack[++top]=c;
        }else if(c==')'){
            while(opStack[top] !='('){
                post[k++]=opStack[top--];
            }
            top--;
        }else{
            while(top!=-1 && precedence(opStack[top])>=precedence(c)){
                post[k++]=opStack[top--];
            }
            opStack[++top]=c;
        }
    }
    while(top!=-1){
        post[k++]=opStack[top--];
    }
    post[k]='\0';

    char tempStack[100][10]; int tacTop=-1;
    for(int i=0;i<k;i++){
        char c=post[i];
        if(isalnum(c)){
            char operand[2] = {c,'\0'};
            strcpy(tempStack[++tacTop],operand);
        }else{
            char op1[10],op2[10];
            strcpy(op1,tempStack[tacTop--]);
            strcpy(op2,tempStack[tacTop--]);           
            char res[10];
            newTemp(res);
            printf("\n %s = %s %c %s \n",res,op2,c,op1);    
            strcpy(tempStack[++tacTop],res);           
        }

    }
}


int main(){
    char exp[100];
    printf("Enter an expression: ");
    scanf("%s", exp);

    printf("\nThree Address Code:\n");
    generateTAC(exp);
	
    return 0;
}