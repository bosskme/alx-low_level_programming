#include "main.h"
#include <stdio.h>

/**
  * _puts - Prints a string
  * @str: The string to print
  *
  * Return: void
  */

void print_rev(char *s) {

int len = strlen(s); // Determine the length of the string

for (int i = len - 1; i >= 0; i--) { // Iterate through string from the end to beginning
printf("%c", s[i]); // Print character at each iteration
}

printf("\n"); // Print new line at end of loop
}
