/*
 * File: main.c
 * Author: Nuno Martins 99292
 * Description: This is the main file of our program.
*/

/* System Headers */
#include <stdlib.h>
#include <stdio.h>

/* Project Headers */
#include "common.h"
#include "list_funcs.h"
#include "read_input.h"
#include "check_command.h"

/* main: Initializes the head Node, reads the input line with 
'read_input' until the input line is empty and runs 'check_command' 
on every iteration, updating the head Node*/
int main()
{
    char *line = (char *)calloc(sizeof(char), DIM_LINHA);
    Node head = NULL;
    while (read_input(line, DIM_LINHA) != 0)
    {
        /* transform input into arguments and update the head Node*/
        head = check_command(line, head);
    }
    free(line);
    delete_all(head);
    return 0;
}
