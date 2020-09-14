#include <stdio.h>
#include <stdlib.h>

extern void hexdump(const void *buffer, int length, int offset, int (*_putchar)(int));

int main(void)
{
	char buffer[0x100] = "TEST";
	hexdump(buffer, sizeof(buffer), 0, putchar);

	return EXIT_SUCCESS;
}
