#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int value;
    struct Node *next;
}node;


typedef struct Queue
{
    node *first;
    node *last;
    int length;
}queue;


void create_queue(queue *q)
{
    q->first = NULL;
    q->last = NULL;
    q->length = 0;
}


void print(queue *Q)
{
    node *n = Q->first;
    printf(" ");
    while(n)
    {
        printf("-[%d]-", n->value);
        n = n->next;
    }printf("\n");
}


void add(queue *Q, int value)
{
    node *n_main;


    n_main = malloc(sizeof(node));
    printf(" [*]Tryng allocation of %d bytes...\n", sizeof(node));
    if(n_main){
        n_main->value = value;
        n_main->next = NULL;
        if(Q->first == NULL){
            Q->first = n_main;
            Q->last = n_main;
        }else{
            Q->last->next = n_main;
            Q->last = n_main;
        }
        print(Q);
        Q->length++;
    }else{
        printf(" [-]Memory error");
    }
}


node* _remove(queue *q)
{
    if(q->length > 0){
        node *n = q->first;
        node *aux = q->first;
        q->first = n->next;
        n = n->next;
        q->length--;
        return q->first;
    }
    return 0;
}
int main()
{
    queue _q;
    create_queue(&_q);
    add(&_q, 3);
    add(&_q, 2);
    add(&_q, 1);
    node *x = _remove(&_q);
    free(x);
    add(&_q, 5);
    return 0;
}
