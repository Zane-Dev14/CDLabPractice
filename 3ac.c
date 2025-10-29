quickly modify this code to make it work for inputs like a=b+c , not postfix

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// A stack to hold strings (operands and temporary variables)
char stack[100][10];
int top = -1;

void push(const char *str) {
    strcpy(stack[++top], str);
}

// Pop copies the top string into 'result' and removes it
void pop(char *result) {
    strcpy(result, stack[top--]);
}

int main() {
    char postfix[100];
    char op1[10], op2[10], temp_var[10], operand_str[2];
    
    // 3) Init temp counter
    int temp_counter = 1;

    printf("Enter a postfix expression (e.g., ab+c*): ");
    
    // 1) Read I/P expression (assuming postfix)
    scanf("%s", postfix);
    
    printf("\n--- Generated 3-Address Code ---\n");

    // 4) Scan the postfix expression
    for (int i = 0; postfix[i] != '\0'; i++) {
        char symbol = postfix[i];

        // 4.1) If symbol is an operand
        if (isalnum(symbol)) {
            // Push to stack
            operand_str[0] = symbol;
            operand_str[1] = '\0';
            push(operand_str);
        }
        // 4.2) If symbol is an operator
        else if (strchr("+-*/", symbol)) {
            // (1) Pop top 2 elements
            pop(op2);
            pop(op1);
            
            // (2) Generate 3AC
            // Create a new temp variable name
            sprintf(temp_var, "t%d", temp_counter++);
            printf("%s = %s %c %s\n", temp_var, op1, symbol, op2);
            
            // (3) Push the new temp var to stack
            push(temp_var);
        }
    }
    
    // 6) The final temp var on the stack contains result
    printf("----------------------------------\n");
    printf("Final result is in: %s\n", stack[top]);
    
    return 0;
}