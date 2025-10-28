#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const char *input;

void match(char token){
    if (token==*input){
        input++;
    }else{
        exit(0);
    }
}
void E();
void E_prime();
void T();
void T_prime();
void F();

void E(){
    printf("\nE->TE'");
    T();
    E_prime();
}

void E_prime(){
    printf("\nE'->+TE' | -TE' | Null");
    if (*input=='+' || *input =='-'){
        if(*input=='+'){
            printf("\nE'->+TE'");
            match('+');
            T();
            E_prime();
        }else if (*input=='-'){
            printf("\nE'->-TE'");
            match('-');
            T();
            E_prime();
        }else{
            printf("\nE'->NULL");
        }
    }
}
void T(){
    printf("\nT->FT'");
    F();
    T_prime();
}
void T_prime(){
    printf("\nT'->+FT' | -FT' | Null");
    if (*input=='*' || *input =='/'){
        if(*input=='*'){
            printf("\nT'->*FT'");
            match('*');
            F();
            T_prime();
        }else if (*input=='/'){
            printf("\nT'->/FT'");
            match('/');
            F();
            T_prime();
        }else{
            printf("\nT'->NULL");
        }
    }
}
void F(){
    printf("\nF->NUM | ID | (E)");
    if (islower(*input)){
        printf("\nF->id");
        input++;
    }else if(*input=='('){
        match('(');
        E();
        match(')');
    }else if (isdigit(*input)){
        printf("\nF->number");
        input++;
    }
}

void main(){
    char temp[100];
    printf("Enter your statement: ");
    scanf("%s",temp);
    input=temp;
    E();

    if(*input=='\0'){
        printf("\nSuccesful!");
    }else{
        printf("Invalid.");
    }
}