#include <stdio.h>
#include <stdlib.h>

extern void hexdump(const void *buffer, int offset, int length, int (*_putchar)(int));

int main(void)
{
	char buffer[0x100];
	hexdump(buffer, 0, sizeof(buffer), putchar);

	return EXIT_SUCCESS;
}
