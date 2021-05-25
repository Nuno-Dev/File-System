/*
 * File: common.h
 * Author: Nuno Martins 99292
 * Description: This file is used by other files that have 
 * certain structures that need certain dimensions. It also 
 * contains all the error messages that are used throughout the project.
*/

#ifndef _COMMON_H_
#define _COMMON_H_

#define DIM_LINHA 65600 /*max line length*/
#define DIM_COMMAND 10 /*max command length*/
#define DIM_VEC_STRINGS 100000 /*max number of stored strings*/

/* errors related to the 'find' command*/
#define FIND_ERR_NOT_FOUND "not found\n"
#define FIND_ERR_NO_DATA "no data\n"
/* errors related to the 'search' command*/
#define SEARCH_ERR_NOT_FOUND "not found\n"
/* errors related to the 'delete' command*/
#define DELETE_ERR_NOT_FOUND "not found\n"
/* errors related to the 'list' command*/
#define LIST_ERR_NOT_FOUND "not found\n"

#endif 