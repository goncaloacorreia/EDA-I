#include "list.h"
#include <stdlib.h>
#include "fatal.h"
#include <stdbool.h>


struct Node{
    ElementType Element;
    Position Next;
};


List MakeEmpty( List L ){
}

bool IsEmpty( List L ){
    return L->Next == NULL;
}

bool IsLast( Position P, List L ){
    return P->Next == NULL;
}

Position Find( ElementType X, List L ){
    Position P;
    P = L -> Next;
    while(P != NULL && P->Element != X){
        P = P->Next;
    }
    return P;
}


Position FindPrevious( ElementType X, List L ) {

}


void Insert( ElementType X, List L, Position P ) {
}

void Delete( ElementType X, List L ){
    Position P;
    P=FindPrevious(X, L);
    if(IsLast(P)){
        tmp=P->Next;
        P->Next = tmp->Next;
        free(tmp);
    }
}


void DeleteList( List L ) {
    Position P;
    P = L->Next;
    L=NULL;
    while(P != NULL){
        tmp = P->Next;
        free(P);
        P=tmp;
    }
}


Position Header( List L ) {
    return L;
}


Position First( List L ) {
    return L->Next;
}


Position Advance( Position P ) {
    return P->Next;
}


ElementType Retrieve( Position P ) {
    return P->Element;
}
