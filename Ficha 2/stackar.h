typedef int ElementType;

#ifndef _Stack_h
#define _Stack_h

struct StackRecord;
typedef struct StackRecord *Stack;

Stack CreateStack( int MaxElements );
void DisposeStack( Stack S );

int isEmpty( Stack S );
int isFull( Stack S );
void MakeEmpty( Stack S );

void Push( ElementType X, Stack S);
ElementType Top( Stack S);
ElementType Pop( Stack S);

#endif