#include "main.h"
#include <stdio.h>

/**
  * print_rev - Prints a string in reverse
  * @s: The string to print
  *
  * Return: void
  */
void print_rev(char *s)
{
  int len = strlen(str);
  for (int i = len - 1; i >= 0; --i) {
    printf("%c\n", str[i]);
}
}
