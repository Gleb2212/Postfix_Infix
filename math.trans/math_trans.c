#include "math_trans.h"

void transformation(char **str) {
    struct Elem *stack = NULL;
    for (int i = 0; i < strlen(*str); i++) {
        int priority = sign((*str)[i]);
        if (priority == 0) {
            char a[2] = {(*str)[i], '\0'};
            push(&stack, a);
        } else {
            char arr[100] = {0};
            arr[0] = '(';
            strcat(arr, pop(&stack));
            arr[strlen(arr)] = (*str)[i];
            strcat(arr, pop(&stack));
            arr[strlen(arr)] = ')';
            push(&stack, arr);
        }
    }
    free(*str);
    *str = (char *) calloc(strlen(stack->arr) + 1, sizeof(char));
    strcat(*str, stack->arr);
    free(stack);
}

int sign(char a) {
    switch (a) {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        default:
            return 0;
    }
}

char *getStr() {
    char *ptr = (char *) malloc(1);
    char buf[81];
    int n, len = 0;
    *ptr = '\0';
    do {
        n = scanf("%80[^\n]", buf);

        if (n == 0)

            scanf("%*c");

        else {

            len += strlen(buf);
            ptr = (char *) realloc(ptr, len + 1);
            strcat(ptr, buf);

        }
    } while (n > 0);
    return ptr;
}

void push(struct Elem **stack, char *value) {
    struct Elem *ptr = (struct Elem *) calloc(1, sizeof(struct Elem));
    if (*stack != NULL)
        ptr->next = *stack;
    *stack = ptr;
    strcat(ptr->arr, value);
}

char *pop(struct Elem **stack) {
    char arr[100] = {0};
    strcat(arr, (*stack)->arr);
    struct Elem *it = *stack;
    *stack = (*stack)->next;
    free(it);
    return arr;
}

int getInt() {
    int a;
    int n;
    do {
        n = scanf_s("%d", &a, sizeof(int));
        scanf_s("%*c", 0);
    } while (n == 0);
    return a;
}