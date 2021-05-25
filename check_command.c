/*
 * File: check_command.c
 * Author: Nuno Martins 99292
 * Description: Functions in this file get the command from the input line and 
calls functions based on the command given by the user.
*/

/* System Headers */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Project Headers */
#include "common.h"
#include "list_funcs.h"
#include "check_command.h"
#include "help.h"
#include "quit.h"
#include "set.h"
#include "print.h"
#include "find.h"
#include "search.h"
#include "delete.h"
#include "list.h"

/* check_command: Reads the command (first string of the line), 
calls other functions based on the command and in the end returns the head Node. */
Node check_command(char *line, Node head)
{
    char *command = (char *)malloc(sizeof(char) * DIM_COMMAND);
    sscanf(line, "%s", command);
    if (strcmp(command, "help") == 0)
    {
        help();
    }
    else if (strcmp(command, "quit") == 0)
    {
        quit();
    }
    else if (strcmp(command, "set") == 0)
    {
        head = set(line, head);
    }
    else if (strcmp(command, "print") == 0)
    {
        print(head);
    }
    else if (strcmp(command, "find") == 0)
    {
        find(line, head);
    }
    else if (strcmp(command, "search") == 0)
    {
        search(line, head);
    }
    else if (strcmp(command, "delete") == 0)
    {
        if (strcmp(line, command) == 0)
        {
            head = delete_all(head);
        }
        else
        {
            head = delete_path(line, head);
        }
    }
    else if (strcmp(command, "list") == 0)
    {
        if (strcmp(line, command) == 0)
        {
            list_root(head);
        }
        else
        {
            list(line, head);
        }
    }
    free(command);
    return head;
}