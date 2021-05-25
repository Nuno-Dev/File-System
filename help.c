/*
 * File: help.c
 * Author: Nuno Martins 99292
 * Description: Prints all the available commands including their description.
*/

/* System Headers */
#include <stdio.h>
#include <stdlib.h>
/* Project Headers */
#include "help.h"

/* help: prints all the available commands */
void help()
{
    char *message = (char *)calloc(sizeof(char), 350);
    message = "help: Imprime os comandos disponíveis.\nquit: Termina o programa.\nset: Adiciona ou modifica o valor a armazenar.\nprint: Imprime todos os caminhos e valores.\nfind: Imprime o valor armazenado.\nlist: Lista todos os componentes imediatos de um sub-caminho.\nsearch: Procura o caminho dado um valor.\ndelete: Apaga um caminho e todos os subcaminhos.";
    printf("%s\n", message);
    free(message);
}