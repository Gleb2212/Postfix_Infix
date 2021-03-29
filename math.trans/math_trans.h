#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

struct Elem {
    char arr[100];
    struct Elem *next;
};

void transformation(char **);

int sign(char);

char *getStr();

void push(struct Elem **, char *);

char *pop(struct Elem **);

int getInt();
