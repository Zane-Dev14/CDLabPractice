    #include <stdio.h>
    #include <string.h>

    #define MAX 50

    char stack[MAX], input[MAX];
    int top=-1;

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
        int i=0;
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
            stack[++top] = b;  // Shift operation: Push the current character onto the stack.
            i++;               // Move to the next character in the input.
        }
        else if (rel == '>') {
        // Keep reducing until we find a '<' relation
        while (1) {
            char a1 = stack[top - 1];
            char a2 = stack[top];
            if (prec[getIndex(a1)][getIndex(a2)] == '<')
                break; // stop reducing
            top--; // pop the top
        }
        top--; // finally reduce one handle
    }

        else { 
            printf("Error\n");  // Error condition: Invalid operation found.
            break;
        }
        }
        return 0;
    }
