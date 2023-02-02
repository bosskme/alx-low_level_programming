#include "main.h"
#include <stddef.h>
#include <math.h>

/**
 * binary_to_uint - Convert a string representing a binary number to an
 * unsigned int decimal value
 * @b: The string containing the binary
 *
 * Return: 0 if string contains something other than 1 or 0, or
 * if the string is NULL, return the decimal value on success
 */

unsigned int binary_to_unit(const char *b){
  unsigned int result = 0;

  if (b == NULL) {
    return 0;
  }

  size_t length = 0;
  while (b[length] != '\0') {
    length++;
  }

  for (int i = length - 1; i >= 0; i--) {
    if (b[i] == '0' || b[i] == '1') {
      result += (b[i] - '0') * pow(2, length - i - 1);
    } else {
      return 0;
    }
  }

  return result;
}
