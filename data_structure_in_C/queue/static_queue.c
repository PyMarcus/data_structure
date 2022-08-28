#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// static queue

#define LENGTH 10
int x = 0;

struct queue Q;


void add(int value)
{
    // add element to end of queue
    queue *p;
    Q.header = Q.queue[0];
    int *pointer;
    pointer = (int*) &x;
    p = &Q;
    if(*pointer < LENGTH){
        Q.queue[*pointer] = value;
        (*pointer)++;
        Q.tail = Q.queue[LENGTH - 1];
    }else{
        printf("The queue is full");
    }
}


int pop()
{
    // remove elements of the end of queue
    queue *pointer;
    pointer = &Q;
    int removed = pointer->queue[0];
    for(int i = 0; i < LENGTH - 1; i++){
        pointer->queue[i] = pointer->queue[i + 1];
    }
    return removed;
}


void print()
// show the queue
{
    for(int i = 0; i < LENGTH; i++){
        printf("%d ", Q.queue[i]);
    }
    printf("\n");
}


int clear()
{
    // clear the queue
    queue *p = &Q;
    free(p);
    p = NULL;
    Q.queue;
    for(int i = 0; i < LENGTH; i++){
        Q.queue[i] = 0;
    }
    int v = {0};
    return v;
}
