//
// Created by Marcus on 28/08/2022.
//
#include <stdio.h>
#include <stdlib.h>


typedef struct Queue
{
    int value;
    int *next; // pointer to next value
}Node;


void insert(Node **queue, int value)
{
    Node *new_item = (Node*)malloc(sizeof (Node));
    if(new_item){
        new_item->value = value;
        new_item->next = NULL; // como é o ultimo, sempre apontará pra nulo
        // is empty?
        if(*queue == NULL){
            *queue = value;
        }else{
            // percorre até o final
            Node *aux = *queue; // ponteiro aponta para o ponteiro q aponta pra fila
            while (aux->next != NULL){
                aux = aux->next;
            }
            aux->next = new_item;
        }
    }else{
        printf("Error. Insuficient space");
    }
}