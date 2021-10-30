//
// Created by Michele De Sena on 30/10/21.
//


/* C Program to remove duplicates from a sorted linked list */
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
typedef struct listnode_s
{
    int data;
    listnode* next;
}listnode;

/* The function removes duplicates from a sorted list */
listnode removeDuplicates(listnode* param_1)
{

    listnode* current = param_1;

    listnode* next_next;


    if (current == NULL)
        return current;


    while (current->next != NULL)
    {

        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }

    return param_1;

}

