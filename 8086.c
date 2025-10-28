#include <stdio.h>
#include <string.h>

void main(){
    char icode[30][30], temp[30];
    int i=0;
    printf("Enter statements: \n");

    do{
        scanf("%s",icode[i]);
    }while(strcmp(icode[i++],"exit")!=0);
    i=0;
    while(strcmp(icode[i],"exit")!=0){
        strcpy(temp,icode[i]);
        char lhs[10],arg1[10],op,arg2[10];
        int n=sscanf(temp,"%[^=]=%[^+-/*]%c%[^+-/*]",lhs,arg1,&op,arg2);
        if (n==4){
           char asmCode[10];
           switch(op){
                case '+': strcpy(asmCode,"ADD");break;
                case '-': strcpy(asmCode,"SUB");break;
                case '*': strcpy(asmCode,"MUL");break;
                case '/': strcpy(asmCode,"DIV");break;
           } 
           printf("\nMOV %s , R%d",arg1,i);
           printf("\n%s %s, R%d",asmCode,arg2,i);
           printf("\nMOV R%d, %s",i,lhs);

        }else{
           printf("\nMOV %s , R%d",arg1,i);
           printf("\nMOV R%d, %s",i,lhs);
        }
        i++;

    }

}