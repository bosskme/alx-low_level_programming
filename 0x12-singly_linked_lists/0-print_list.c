#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Print_list - prints all the elements of a linked list
 * @h: pointer to the list_t list to print
 *
 * Return: the number of nodes printed
 */

size_t print_list(const list_t *h) {
    if (h == NULL) {
        printf("[0] (nil)\n");
        return 0;
    }

    size_t count = 0;
    const list_t *current = h;
    while (current != NULL) {
        printf("[%d] %s\n", current->val, current->str ? current->str : "(nil)");
        current = current->next;
        count++;
    }
    return count;
}
