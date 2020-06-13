#include "header.h"


int main(){
    struct Stack_t* stack;
    stack=(struct Stack_t*)malloc(sizeof(struct Stack_t));
    push(1, stack);
    push(2, stack);
    push(3, stack);
    push(4, stack);
    push(5, stack);
    print_stack(stack);
    return 0;
}



