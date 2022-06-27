#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.c"

bool palindrome(char * txt){
    struct Stack* stack = createStack(100);
    struct Stack* stack1 = createStack(100);
    struct Stack* stack2 = createStack(100);

    for (int i = 0; i <= strlen(txt); i++){
        push(stack, txt[i]);
        push(stack1, txt[i]);
    }
    printf("\n");

    for (int i = 0; i <= strlen(txt); i++){
        char c = pop(stack);
        push(stack2, c);
    }

    if (stack1 == stack2)
    {
        return true;
    } else{
        return false;
    }
    
}

int main(){
    char * t = "oio";
    char * y = "Zero";
    printf("\n%d\n", palindrome(t));
}