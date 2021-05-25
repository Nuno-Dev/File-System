/*
 * File: list_funcs.c
 * Author: Nuno Martins 99292
 * Description: This file has all the functions that are linked to building 
 and updating the data structure chosen for this project that is a singly 
 linked list that has a pointer to a char value, a pointer to a char path 
 and a pointer to the next Node. All the functions have comments above 
 them describing each one.
*/

/* System Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Project Headers */
#include "common.h"
#include "list_funcs.h"

/*  correct_path: gets a path and returns a pointer to a new path that 
is updated with only one '/' between each component of the path. 
Basically it corrects wrong input from the user into a simple path. 
For example it turns ///a//b///c/// into a/b/c  */
char *correct_path(char *path)
{
    int i = 0, c = 0, len = strlen(path);
    char *newString = (char *)calloc(sizeof(char), len + 1);

    while (path[i] == '/')
    {
        i++;
    }
    for (; i < len; i++)
    {
        if (path[i] != path[i + 1] || (path[i] != '/' && path[i + 1] != '/'))
        {
            newString[c++] = path[i];
        }
    }
    c--;
    if (newString[c] == '/')
    {
        newString[c] = '\0';
    }
    else
    {
        c++;
        newString[c] = '\0';
    }
    return newString;
}

/* NEW: responsible to allocate memory to create a new Node and update it 
with the value and the path given by the user. In the end returns the 
newly created Node */
Node NEW(char *path, char *value)
{
    Node x = (Node)malloc(sizeof(struct node));

    x->path = (char *)calloc(sizeof(char), strlen(path) + 1);
    x->value = (char *)calloc(sizeof(char), strlen(value) + 1);

    strcpy(x->path, path);
    strcpy(x->value, value);
    x->next = NULL;
    return x;
}

/* insertEnd: receives the head Node, a path and a value and it uses 
NEW to createa a new Node with the new value and path and it inserts 
it and the end of the linked list. In the end it returns the head Node. */
Node insertEnd(Node head, char *path, char *value)
{
    Node x, prev;
    char *new_value;
    int len_value = strlen(value);
    if (head == NULL)
    {
        return NEW(path, value);
    }

    for (x = head, prev = NULL; x != NULL; prev = x, x = x->next)
    {
        /* if the path is already in the linkedlist, just update it's value */
        if (strcmp(x->path, path) == 0)
        {
            if (len_value > 0)
            {
                new_value = (char *)calloc(sizeof(char), len_value + 1);
                strcpy(new_value, value);
                free(x->value);
                x->value = new_value;
            }

            return head;
        }
    }
    /* else create a new Node at the end of the linkedlist */
    prev->next = NEW(path, value);
    return head;
}

/* find_path: receives the head Node and a path and returns the Node 
that has the same path as the received argument */
Node find_path(Node head, char *path)
{
    Node x;
    for (x = head; x != NULL; x = x->next)
        if (strcmp(x->path, path) == 0)
        {
            return x;
        }
    return NULL;
}

/* find_value: receives the head Node and a value and returns the Node 
that has the same value as the received argument */
Node find_value(Node head, char *value)
{
    Node x;
    for (x = head; x != NULL; x = x->next)
        if (strcmp(x->value, value) == 0)
        {
            return x;
        }
    return NULL;
}

/* free_node: receives a Node and frees the memory allocated by their 
char pointers as well as the memory allocated to the Node itself */
void free_node(Node x)
{
    free(x->path);
    free(x->value);
    free(x);
}

/* is_subpath: returns -1 if the passed 'subpath' is not a subpath of 'path' 
both received as arguments. If is is, then we return an integer which is
the index of the the beggining character of the next component of the path */
int is_subpath(char *path, char *subpath)
{
    int i, len_path = strlen(path), len_subpath = strlen(subpath);
    /*a path is never smaller than any of their subpaths*/
    if (len_subpath > len_path)
    {
        return -1;
    }
    for (i = 0; i < len_path; i++)
    {
        if (path[i] != subpath[i])
        {
            break;
        }
    }
    /* for the subpath to be a valid subpath of path, it needs either to
    be equal to the path or if different, the subpath's last component
    needs to be equal to a path's whole component */
    if (i == len_path || (i == len_subpath && path[i] == '/'))
    {
        /*return the index where the next component
        of the path starts (useful for the 'list' command)*/
        return i + 1;
    }
    else
    {
        return -1;
    }
}

/* delete_subpaths: receives the head Node and a subpath and it deletes all paths
that have 'subpath' as one of their subpaths. */
Node delete_subpaths(Node head, char *subpath)
{
    Node x, prev;
    int num_deleted = 0;
    /* If the head node itself has 'subpath' as a one of their subpaths*/
    while (head != NULL && is_subpath(head->path, subpath) > 0)
    {
        prev = head;
        head = head->next;
        free_node(prev);
        num_deleted++;
    }

    prev = NULL;
    x = head;
    /* Delete occurrences other than head*/
    while (x != NULL)
    {
        /* 'subpath' is a valid subpath of the current node's path */
        if (is_subpath(x->path, subpath) > -1)
        {
            /* Adjust connection for previous node*/
            if (prev != NULL)
            {
                prev->next = x->next;
            }

            /* Delete current node*/
            free_node(x);
            num_deleted++;
            x = prev->next;
        }
        else
        {
            prev = x;
            x = x->next;
        }
    }
    /* if no Nodes were deleted, print the error message */
    if (num_deleted == 0)
    {
        printf(DELETE_ERR_NOT_FOUND);
    }
    return head;
}

/* delete_all: deletes the whole singly linked list */
Node delete_all(Node head)
{
    Node current = head, next;

    while (current != NULL)
    {
        next = current->next;
        free_node(current);
        current = next;
    }
    return NULL;
}
