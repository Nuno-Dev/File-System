/*
 * File: find.c
 * Author: Nuno Martins 99292
 * Description: Prints the value that is stored in a path. If the path 
 * doesn't exist, then print 'not found'. If the path has no value then 
 * print 'no data'. All the error messages are present in the common.h file.
*/

/* System Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Project Headers */
#include "common.h"
#include "list_funcs.h"
#include "find.h"

/* find: gets the path from the line input and uses 'find_path' 
function that is present in the list_funcs file */
void find(char *line, Node head)
{
    Node res;
    char *command, *path, *corrected_path;
    int len_line = strlen(line);
    path = (char *)calloc(sizeof(char), len_line + 1);
    command = (char *)malloc(sizeof(char) * DIM_COMMAND);
    sscanf(line, "%s %s", command, path);
    free(command);
    corrected_path = correct_path(path);
    free(path);
    path = corrected_path;
    res = find_path(head, path);
    if (res == NULL)
    {
        printf(FIND_ERR_NO_DATA);
    }
    else
    {
        if (strlen(res->value) > 0)
        {
            printf("%s\n", res->value);
        }
        else
        {
            printf(FIND_ERR_NOT_FOUND);
        }
    }
    free(path);
}