#include "stackar.h"
#include "fatal.h"
#include <stdlib.h>

#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )

struct StackRecord{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

Stack CreateStack( int MaxElements){
    Stack S;

    if(MaxElements < MinStackSize){
        Error("Stack size is too small");
    }

    S = malloc(sizeof(struct StackRecord));

    if(S->Array == NULL){
        FatalError("Out of space");
    }

    S->Capacity = MaxElements;
    MakeEmpty(S);

    return S;
    
}

void DisposeStack (Stack S){
    if(S!= NULL){
        free(S->Array);
        free(S);
    }
}

int isEmpty(Stack S){
    return S->TopOfStack=EmptyTOS;
}

int isFull(Stack S){
    return S->TopOfStack == S->Capacity-1;
}

void MakeEmpty(Stack S){
    S->TopOfStack=EmptyTOS;
}

void Push(ElementType X, Stack S){
    if(isFull(S)){
        Error("Full Stack");
    }
    S->Array[++ S->TopOfStack] = X;
}

ElementType Top(Stack S){
    if(!isEmpty(S)){
        return S->Array[S->TopOfStack];
    Error("Empty Stack");
    return 0;
    }
}

ElementType Pop(Stack S){
    if(!isEmpty(S)){
        return S->Array[S->TopOfStack--];
    }
    Error("Empty Stack");
    return 0;
}