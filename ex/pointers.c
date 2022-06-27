#include <stdio.h>
int main(){
    int i, j, *p1, *p2, **pp1, **pp2;
    i=4;
    j=5;
    p1 = &i;
    p2 = &j;
    pp1 = &p1;
    pp2 = &p2;

    printf("%p %p\n", p1, *&p1 );
}