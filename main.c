#include <stdio.h>
#include <stdlib.h>

#define INITIAL_OFFSET 24

extern void hexdump(const void *buffer, int buffer_length, int offset, int (*putchar)(int));

int main(void)
{
	char buffer[256 + INITIAL_OFFSET];

	for (int i = INITIAL_OFFSET; i < sizeof(buffer); ++i) {
		buffer[i] = (unsigned char)(i - INITIAL_OFFSET);
	}

	hexdump(buffer, sizeof(buffer), INITIAL_OFFSET, putchar);

	return EXIT_SUCCESS;
}
