#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE  256

struct element {
    char *name;
    struct element *next;
};

struct element *tail;

void init_queue (void);
void enqueue (char *name);
int dequeue (char *name);
void print_queue (void);
void error (char *msg);

void init_queue (void)
{
    tail = NULL;
}

void enqueue (char *name)
{
    struct element *ptr;
    char *cp;

    if ((ptr = (struct element *) malloc (sizeof (struct element))) == NULL)
        error ("malloc");
    if ((cp = (char *) malloc (strlen (name) + 1)) == NULL)
        error ("malloc");

    strcpy (cp, name);
    ptr -> name = cp;

    if (tail == NULL) {
        ptr -> next = ptr;
    }
    else
    {
        ptr -> next = tail -> next;
        tail -> next = ptr;
    }
    tail = ptr;
}

int dequeue (char *name) 
{
    struct element *ptr;
    char *cp;

    if (!tail) {
        fprintf (stderr, "Queue is empty\n");
        return -1;
    }
    // obter a head
    ptr = tail -> next;
    cp = ptr -> name;

    if (ptr == tail)
        tail = NULL;
    else
        tail -> next = ptr -> next;
    free (ptr);
    strcpy (name, cp);
    free (cp);
    return 0;
}

void print_queue (void)
{

    struct element *ptr, *head;

    if (!tail) {
        fprintf (stderr, "Queue is empty\n");
        return;
    }

    head = ptr = tail -> next;
    int i = 1;

    do {
        printf ("%s ", ptr -> name);
        ptr = ptr -> next;
        i++;
    } while (ptr != head);
}

void error (char *msg)
{
    perror (msg);
    exit (1);
}