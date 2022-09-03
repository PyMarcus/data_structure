#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Node{
    int value;
    struct Node *next;
    int length;
}node;


int generator(int limit)
{
    srand(time(NULL));
    return rand() % limit;
}


node* push(node *top, int value)
// adiciona no topo da pilha
{
    node *n;

    n = malloc(sizeof(node));
    if(n)
    {
        n->value = value;
        n->next = top;
        n->length++;
        return n;
    }else
    {
        printf("insufficient memory");
    }
    return NULL;
}


void print(node *st)
{
    printf("\n");
    while(st)
    {
        printf("%d ", st->value);
        st = st->next;
    }
        //printf("%d ", generator(199));
}


node* pop(node *st)
// remove do inicio da pilha
{
    int aux = st->value;
    st->length--;
    st = st->next;
    return st;
}


int main()
{
    // pilhas são estruturas de dados muito comum, onde o primeiro que entra é o ultimo que sai
    node *st;
    st = push(st, 2);
    st = push(st, 3);
    st = push(st, 4);
    // entrada: 2, 3, 4 -> saida 4, 3, 2
    print(st);
    st = pop(st);
    print(st);
}
