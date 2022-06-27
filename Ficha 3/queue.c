#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "fatal.h"


#define MinQueueSize ( 5 )

struct QueueRecord{
    int Capacity;
    int Front;
    int Rear;
    ElementType *Array;
};


int size( Queue Q ){
}

int successor( int i, Queue Q ){
    if(i == Q->Capacity-1){
        return 0;
    }
    else{
        return i+1;
    }
}



Queue CreateQueue( int MaxElements ){
    Queue Q;

    if( MaxElements < MinQueueSize )
        Error( "Queue size is too small" );

    Q = malloc( sizeof( struct QueueRecord ) );
    if( Q == NULL )
        FatalError( "Out of space!!!" );

    Q->Array = malloc( sizeof( ElementType ) * MaxElements );
    if( Q->Array == NULL )
        FatalError( "Out of space!!!" );

    Q->Capacity = MaxElements;
    MakeEmptyQueue( Q );

    return Q;
}


void DisposeQueue( Queue Q ){
    if( Q != NULL ){
        free( Q->Array );
        free( Q );
    }
}


bool IsEmptyQueue( Queue Q ){
    return Q->Front == Q->Rear;
}


bool IsFullQueue( Queue Q ){
    return size(Q) == Q->Capacity-1;
}


void MakeEmptyQueue( Queue Q ){
}


void Enqueue( ElementType X, Queue Q ){
}


ElementType Front( Queue Q ){
    return Front;
}


ElementType Dequeue( Queue Q ){
    return Rear;
}
