/*
 * File: search.c
 * Author: Nuno Martins 99292
 * Description: Searches for a path given a value.
*/

/* System Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Project Headers */
#include "common.h"
#include "list_funcs.h"
#include "search.h"

/* search: gets the value from the input line and uses 'find_value' 
function that is present in list_funcs and if there's a Node
that has the same value of the value passed as an argument through
the input line, then we print it's path. If there's no Node, we print
an error. */
void search(char *line, Node head)
{
    Node res;
    char *command, *value;
    int len_line = strlen(line);
    value = (char *)calloc(sizeof(char), len_line + 1);
    command = (char *)malloc(sizeof(char) * DIM_COMMAND);
    sscanf(line, "%s %[^\n]", command, value);
    free(command);
    res = find_value(head, value);
    if (res == NULL)
    {
        printf(SEARCH_ERR_NOT_FOUND);
    }
    else
    {
        printf("/%s\n", res->path);
    }
    free(value);
}