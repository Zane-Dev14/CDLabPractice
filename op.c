#include <stdio.h>
#include <string.h>

#define MAX 50

char stack[MAX], input[MAX];
int top=-1;
int i=0;

void print(){
    printf("\nStack: ");
    for(int j=0;j<=top;j++){
        printf(" %c ",stack[j]);
    }
    printf("\nInput : ");
    for( int j= i;input[j];j++){
        printf("%c",input[j]);
    }
}

char prec[8][8] = {
//   +   -   *   /   (   )   i   $
    {'>','>','<','<','<','>','<','>'}, // +
    {'>','>','<','<','<','>','<','>'}, // -
    {'>','>','>','>','<','>','<','>'}, // *
    {'>','>','>','>','<','>','<','>'}, // /
    {'<','<','<','<','<','=','<',' '}, // (
    {'>','>','>','>',' ','>',' ','>'}, // )
    {'>','>','>','>',' ','>',' ','>'}, // i
    {'<','<','<','<','<',' ','<','='}  // $
};

int getIndex(char c){
    switch(c){
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case '(': return 4;
        case ')': return 5;
        case 'i': return 6;
        case '$': return 7;
    }
    return -1;
}

int main(){
    printf("Enter expression ending with $: ");
    scanf("%s", input);

    stack[++top]='$';

    while(1){
        char a = stack[top];
        char b = input[i];
        if(a=='$' && b=='$'){
            printf("Accepted\n");
            break;
        }
        char rel = prec[getIndex(a)][getIndex(b)];
    if(rel == '<' || rel == '='){ 
        // printf("\nTop Of Stack  and  input : %c & %c ",stack[top],b);
        printf("\nShifting.\n");
        stack[++top] = b;  // Shift operation: Push the current character onto the stack.
        print();
        i++;               // Move to the next character in the input.
    }
    else if (rel == '>') {
        // printf("\nTop Of Stack  and  input : %c & %c ",stack[top],b);

    // Keep reducing until we find a '<' relation
    while (1) {
        printf("\nReducing.\n");
        char a1 = stack[top - 1];

        char a2 = stack[top];
        if (prec[getIndex(a1)][getIndex(a2)] == '<')
            break; // stop reducing
        top--; // pop the top
        print();

        // printf("\nTop Of Stack  %c ",stack[top]);

    }
    top--; // finally reduce one handle
        // printf("\nTop Of Stack  %c ",stack[top]);
        print();


}

    else { 
        printf("Error\n");  // Error condition: Invalid operation found.
        break;
    }
    }
    return 0;
}
