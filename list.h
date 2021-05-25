/*
 * File: list.h
 * Author: Nuno Martins 99292
 * Description: Declaration of the functions.
*/

#ifndef _LIST_H_
#define _LIST_H_

/* Function declarations */
void free_vec(char **vec, int vec_size);

void list(char *line, Node head);

void list_root(Node head);

#endif 