#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char bracket_stack[100000 + 1];

void Push(char key, int *stack_top)
{
    ++(*stack_top);
    bracket_stack[*stack_top] = key;
}

char KeyPop(int *stack_top)
{
    if (*stack_top < 0) {
        fprintf(stderr, "Stack is empty\n");
        return -1;
    }
    --(*stack_top);
    return bracket_stack[*stack_top + 1];
}

int main()
{
    int stack_top = -1;
    int num = 0;
    int open_bracket_index = 0;


    while (true) {
        int bracket = getchar();
        
        ++num;  // number of brackets

        if (bracket == EOF || bracket == '\n') {
            break;
        }

        if (bracket == ']' || bracket == ')' || bracket == '}') {
            if (stack_top < 0) {  // stack is empty
                printf("%d\n", num);
                exit(EXIT_SUCCESS);
            }
                                                             // сравнение кодов символов скобок.
            if (bracket_stack[stack_top]+1 != bracket        // между скобками () разница 1
                && bracket_stack[stack_top]+2 != bracket) {  // между [] и {} - разница 2
                printf("%d\n", num);
                exit(EXIT_SUCCESS);    
            }

            KeyPop(&stack_top);
            continue;
        }

        if (bracket == '[' || bracket == '(' || bracket == '{') {
            if (stack_top < 0) {  // stack is empty
                open_bracket_index = num;
            }
            Push(bracket, &stack_top);
        }
    }

    if (stack_top < 0) {
        printf("Success\n");
    } else {
        printf("%d\n", open_bracket_index);
    }

    return EXIT_SUCCESS;
}