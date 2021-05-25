/*
 * File: print.c
 * Author: Nuno Martins 99292
 * Description: Prints all the paths and their corresponding values.
*/

/* System Headers */
#include <stdio.h>
#include <string.h>
/* Project Headers */
#include "list_funcs.h"
#include "print.h"

/* print: receives the head Node and iterates through the singly linked-list
and prints both the path and the corresponding value of each Node */
void print(Node head)
{
    Node x;
    for (x = head; x != NULL; x = x->next)
    {
        if (strlen(x->value) > 0)
        {
            printf("/%s %s\n", x->path, x->value);
        }
    }
}
