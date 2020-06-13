#ifndef header.h
#define header.h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define  MAX 5


typedef struct Stack_t{
    int DATA[MAX];
    int top;
};


struct Stack_t stack;


int Is_empty(int top);

int Is_full(int top);

void Initialize(struct Stack_t* stack);

void push(int DATA, struct Stack_t* stack);

void pop(int *DATA, struct Stack_t* stack);

void Make_NULL(struct Stack_t* stack);

void print_stack(struct Stack_t* stack);

#endif