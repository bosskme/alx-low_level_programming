#include "main.h"

/**
 *File: 100-os_palindrome.c
 *Auth:Kachi
 */

int find_strlen(char *s);
int check_palindrome(har *s, int len, int index);
int is_palindrome(char *s);

/**
 * find_strlen - Returns the length of a string.
 *@s: The string to be measured.
 *
 *Return: The length of the string.
 */
int find_strlen(char *s)
{
  int len = 0;

  if(*(s + len))
    {
      len++;
      len += find_strlen(s + len);
    }
  return(len);
}
