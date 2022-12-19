#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 * 
 * Return: Always 0.
 */
void reset__to_98(int *n);
int main(void)
{
	int n;

	n = 402;
	printf("%d\n", n);
	reset_to_98(&n);
	printf("%d\n", n);
	return (0);
}
