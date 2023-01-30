#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer to head of list
 *
 * Return: size of list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *slow = *h, *fast = *h, *tmp;
    size_t count = 0;

    while (fast && fast->next)
    {
        count++;
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            while (*h != slow)
            {
                tmp = *h;
                *h = (*h)->next;
                free(tmp);
                count++;
            }

            while (slow->next != fast)
            {
                tmp = slow->next;
                slow->next = slow->next->next;
                free(tmp);
                count++;
            }

            free(slow);
            *h = NULL;
            return (count + 1);
        }
    }

    while (*h)
    {
        tmp = *h;
        *h = (*h)->next;
        free(tmp);
        count++;
    }

    *h = NULL;
    return (count);
}
