/*
 * File: quick_sort.c
 * Author: Nuno Martins 99292
 * Description: Implementation of the quick sort algorithm to sort 
 strings by ASCII order (upper-case first).
*/

/* System Headers */
#include <stdio.h>
#include <string.h>
/* Project Headers */
#include "quick_sort.h"

/* swap: Swaps two elements of 'vec' indexed by "x" and "y". */
void swap(char **vec, int x, int y)
{
    char *temp;

    temp = vec[x];
    vec[x] = vec[y];
    vec[y] = temp;
}

/* quick_sort: implementation of the quick_sort algorithm to sort
strings by ASCII order (upper-case first) */
void quick_sort(char **vec, int left, int right)
{
    int pivot, i, j;
    char *key;

    /* If the vec has only one entry (trivial case) */

    if (right - left == 1)
    {
        if (strcmp(vec[left], vec[right]) > 0)
        {
            swap(vec, left, right);
        }
        return;
    }

    /* Pivot = middle point between left and right */

    pivot = (left + right) / 2;
    key = vec[pivot];

    swap(vec, left, pivot);

    i = left + 1;
    j = right;

    while (i < j)
    {
        while (i <= right && strcmp(vec[i], key) < 0)
        {
            i++;
        }
        while (j >= left && strcmp(vec[j], key) > 0)
        {
            j--;
        }
        if (i < j)
        {
            /* "vec[i]" is greater than "key", and "vec[j]" is
               less than or equal to "key", so swap them. */
            swap(vec, i, j);
        }
    }

    swap(vec, left, j);

    if (left < j - 1)
    {
        /* Sort the left half using recursion */
        quick_sort(vec, left, j - 1);
    }
    if (j + 1 < right)
    {
        /* Sort the right half using recursion */
        quick_sort(vec, j + 1, right);
    }
}