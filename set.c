/*
 * File: set.c
 * Author: Nuno Martins 99292
 * Description: Adds a new path or modifies the stored value.
*/

/* System Headers */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Project Headers */
#include "common.h"
#include "list_funcs.h"
#include "set.h"

/* set_aux: inserts or modifies all the components of a given path.
If the path given is 'a/b/c' then we add the paths: 'a', 'a/b' and
'a/b/c'. All the subpaths, except the last one (the main one given as 
an argument) is initialized with an empty value. The path given as
an argument, in that example, 'a/b/c' is initialized with the value received
as an argumetn. */
Node set_aux(Node head, char *path, char *value)
{
    char *current, *empty_value = (char *)calloc(sizeof(char), 1);
    int i, len_path = strlen(path);

    current = (char *)calloc(sizeof(char), len_path + 1);

    for (i = 0; i < len_path; i++)
    {
        if (path[i] == '/')
        {
            head = insertEnd(head, current, empty_value);
        }
        current[i] = path[i];
    }

    return insertEnd(head, path, value);
}

/* set: gets both the path and the value from the input line. 
If only the path is present in the input line, then we iniatilize
it with an empty value (by allocating 1 empty memory char block).
We also correct the path using 'correct_path' that for example
turns '////a///b/c///' into 'a/b/c'. After that we pass the 
corrected path and value into set_aux */
Node set(char *line, Node head)
{
    char *command, *temp_path, *path, *temp_value, *value, *corrected_path;
    int len_path, len_value, args_read, len_line = strlen(line);
    command = (char *)calloc(sizeof(char), DIM_COMMAND);
    temp_path = (char *)calloc(sizeof(char), len_line + 1);
    temp_value = (char *)calloc(sizeof(char), len_line + 1);
    args_read = sscanf(line, "%s %s %[^\n]", command, temp_path, temp_value);
    len_path = strlen(temp_path);
    len_value = strlen(temp_value);
    path = (char *)calloc(sizeof(char), len_path + 1);
    value = (char *)calloc(sizeof(char), len_value + 1);
    strcpy(path, temp_path);
    strcpy(value, temp_value);
    free(temp_path);
    free(temp_value);
    free(command);
    corrected_path = correct_path(path);
    free(path);
    path = corrected_path;
    /* if no value was given, then give it NULL value
    by allocating an empty memory char space*/
    if (args_read == 2)
    {
        free(value);
        value = (char *)calloc(sizeof(char), 1);
    }
    return set_aux(head, path, value);
}
