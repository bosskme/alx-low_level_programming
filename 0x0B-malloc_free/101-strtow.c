#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
  * strtow - ...
  * @str: ...
  *
  * Return: ...
  */

char **strtow(char *str) {
    // check for invalid input
    if (!str || !*str) {
        return NULL;
    }

    // allocate memory for the array of strings
    int num_words = 0;
    char **result = malloc(sizeof(char *));
    if (!result) {
        return NULL; // allocation failed
    }

    // split the input string into words
    char *word_start = str;
    while (*str) {
        if (*str == ' ') {
            // found the end of a word, add it to the result array
            int word_len = str - word_start;
            result[num_words] = malloc((word_len + 1) * sizeof(char));
            if (!result[num_words]) {
                // free previously allocated memory and return NULL
                for (int i = 0; i < num_words; i++) {
                    free(result[i]);
                }
                free(result);
                return NULL;
            }
            memcpy(result[num_words], word_start, word_len);
            result[num_words][word_len] = '\0'; // null-terminate the string
            num_words++;

            // reallocate memory for the array of strings
            result = realloc(result, (num_words + 1) * sizeof(char *));
            if (!result) {
                // free previously allocated memory and return NULL
                for (int i = 0; i < num_words; i++) {
                    free(result[i]);
                }
                free(result);
                return NULL;
            }

            // move on to the next word
            word_start = str + 1;
        }
        str++;
    }

    // add the last word to the result array
    int word_len = str - word_start;
    result[num_words] = malloc((word_len + 1) * sizeof(char));
    if (!result[num_words]) {
        // free previously allocated memory and return NULL
        for (int i = 0; i < num_words; i++) {
            free(result[i]);
        }
        free(result);
        return NULL;
    }
    memcpy(result[num_words], word_start, word_len);
    result[num_words][word_len] = '\0'; // null-terminate the string
    num_words++;

    // add a NULL element to the end of the array
    result = realloc(result, (num_words + 1) * sizeof(char *));
    if (!result) {
        // free previously allocated memory and return NULL
        for (int i = 0; i < num_words; i++) {
            free(result[i]);
        }
        free(result);
        return NULL;
    }
    result[num_words] = NULL;

    return result;
}
