#include <stdio.h>
#include <stdlib.h>

/**
 * turtle - prints before the main
 */
void __attribute__ ((constructor)) turtle()
{
	printf("You're beat! and yet, you must allow,\n"
			"I bore my house upon my back!\n");
}
