/*
 * File: list.c
 * Author: Nuno Martins 99292
 * Description: This file contains the functions that deal with the 'list' command. 
 * All the functions have their description above them.
*/

/* System Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Project Headers */
#include "common.h"
#include "list_funcs.h"
#include "list.h"
#include "quick_sort.h"

/* free_vec: receives a pointer to a list of char pointers and the size of that list
and frees the memory allocated to all the individual char pointers. In the end it 
also frees the memory allocated to the whole list of pointers */
void free_vec(char **vec, int vec_size)
{
    int i;
    for (i = 0; i < vec_size; i++)
    {
        free(vec[i]);
    }
    free(vec);
}

/* print_uniques_sorted: receives a pointer to a list of char pointers and the size
of that list. Firstly it stores all the values in the list of char pointers with their
memory corresponding to the actual length of the char it contains, so that no memory is
wasted. After storing all the chars with the correct memory, it uses the quick_sort algorithm
to sort all the strings pointed by each char pointer by ASCII order and upper-case first order.
After that, it prints all the sorted strings. */
void print_uniques_sorted(char **temp_vec_strings, int vec_size)
{
    char **vec_strings;
    int k = 0, j;
    vec_strings = (char **)malloc(sizeof(char *) * vec_size);
    vec_strings[0] = (char *)malloc(sizeof(char) * (strlen(temp_vec_strings[0]) + 1));
    strcpy(vec_strings[0], temp_vec_strings[0]);
    k++;

    for (j = 0; j < vec_size - 1; j++)
    {
        if (strcmp(temp_vec_strings[j], temp_vec_strings[j + 1]) != 0)
        {
            vec_strings[k] = (char *)malloc(sizeof(char) * (strlen(temp_vec_strings[j + 1]) + 1));
            strcpy(vec_strings[k++], temp_vec_strings[j + 1]);
        }
    }
    quick_sort(vec_strings, 0, k - 1);
    for (j = 0; j < k; j++)
    {
        printf("%s\n", vec_strings[j]);
    }
    free_vec(vec_strings, k);
}

/* list: is the function called when the 'list' command is called with arguments.
It prints all the components that are immediately after the given path.
Example: it receives 'a/b/' and we have a path that is 'a/b/c', then 'c' is printed.
If there is not a path equal to the path passed as a string after the 'list' command, 
then we print the error 'not found'.*/
void list(char *line, Node head)
{
    Node x;
    char **temp_vec_strings = (char **)malloc(sizeof(char *) * DIM_VEC_STRINGS);
    char *command, *subpath, *corrected_subpath, *aux;
    int len_line = strlen(line), idx = 0, len_path = 0, i = 0;
    subpath = (char *)calloc(sizeof(char), len_line + 1);
    command = (char *)malloc(sizeof(char) * DIM_COMMAND);
    sscanf(line, "%s %s", command, subpath);
    free(command);
    corrected_subpath = correct_path(subpath);
    free(subpath);
    subpath = corrected_subpath;
    for (x = head; x != NULL; x = x->next)
    {
        idx = is_subpath(x->path, subpath);
        len_path = strlen(x->path);

        if (idx > -1 && idx <= len_path)
        {
            aux = (char *)malloc(sizeof(char) * strlen(x->path));
            strcpy(aux, x->path + idx);
            temp_vec_strings[i] = strtok(aux, "/");
            i++;
        }
    }
    if (i == 0)
    {
        printf(LIST_ERR_NOT_FOUND);
        return;
    }
    print_uniques_sorted(temp_vec_strings, i);
    free(aux);
    free(subpath);
}

/* get_root: receives a path and it returns the root component.
Example: receives 'a/b/c' then we return a pointer to the char 'a'. */
char *get_root(char *path)
{
    char *aux = (char *)malloc(sizeof(char) * (strlen(path) + 1));
    char *root;
    strcpy(aux, path);
    root = strtok(aux, "/");
    return root;
}

/* list_root: is the function called when the 'list' command is called with no arguments.
it prints all the root Nodes of all the paths that are stored in our Singly Linked-List data
structure */
void list_root(Node head)
{
    Node x;
    char **temp_vec_strings = (char **)malloc(sizeof(char *) * DIM_VEC_STRINGS);
    char *root, *aux;
    int i = 0;
    for (x = head; x != NULL; x = x->next)
    {
        aux = get_root(x->path);
        root = (char *)malloc(sizeof(char) * (strlen(aux) + 1));
        strcpy(root, aux);
        temp_vec_strings[i] = root;
        i++;
    }
    print_uniques_sorted(temp_vec_strings, i);
    free(root);
    free_vec(temp_vec_strings, i);
}