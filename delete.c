/*
 * File: delete.c
 * Author: Nuno Martins 99292
 * Description: This file is used to delete a certain path. 
 * It calls a function that is present in the file 'list_funcs' that 
 * deletes all the paths that 'subpath' is a subpath of them.
*/

/* System Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Project Headers */
#include "common.h"
#include "list_funcs.h"
#include "delete.h"

/*delete_path: receives the line input and the head Node and returns 
the call of the 'delete_subpaths' function which is the new head Node.*/
Node delete_path(char *line, Node head)
{
    char *command, *subpath, *corrected_subpath;
    int len_line = strlen(line);
    subpath = (char *)calloc(sizeof(char), len_line + 1);
    command = (char *)malloc(sizeof(char) * DIM_COMMAND);
    sscanf(line, "%s %s", command, subpath);
    free(command);
    corrected_subpath = correct_path(subpath);
    free(subpath);
    subpath = corrected_subpath;
    return delete_subpaths(head, subpath);
}
