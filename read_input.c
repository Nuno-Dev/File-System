/*
 * File: read_input.c
 * Author: Nuno Martins 99292
 * Description: Reads the input line
*/

/* System Headers */
#include <stdio.h>
/* Project Headers */
#include "read_input.h"

/* Reads the input line and stores it in a string vector that has been passed 
as an argument. It returns the number of characters read in the line. If the
returned value is 0, then the line was empty and we end our program.*/
int read_input(char *line, int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }
    line[i] = '\0';
    return i;
}
