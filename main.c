#include <stdio.h>
#include <stdlib.h>

extern void hexdump(const void *buffer, int buffer_length, int offset, int (*putchar)(int));

int main(void)
{
	char buffer[0x100];
	hexdump(buffer, sizeof(buffer), 0, putchar);

	return EXIT_SUCCESS;
}
