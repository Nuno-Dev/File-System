/*
 * File: list_funcs.h
 * Author: Nuno Martins 99292
 * Description: Definition of the data structure used in this project which is a singly linked-list. Also in this file we declare all the other functions that manipulates the chosen data structure.
*/

#ifndef _LIST_FUNCS_H_
#define _LIST_FUNCS_H_

/*define structure *Node*/
typedef struct node
{
    char *path;
    char *value;
    struct node *next;
} * Node;

/* Function declarations */
char *correct_path(char *path);

Node NEW(char *path, char *value);

Node insertEnd(Node head, char *path, char *value);

Node find_path(Node head, char *path);

Node find_value(Node head, char *value);

void free_node(Node x);

int is_subpath(char *path, char *subpath);

Node delete_subpaths(Node head, char *subpath);

Node delete_all(Node head);

#endif
