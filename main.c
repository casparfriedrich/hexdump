#include <stdint.h>
#include <stdlib.h>

extern void hexdump(const void *buffer, size_t length, size_t offset);

int main(void)
{
	char buffer[0x100 + 8];
	hexdump(buffer, sizeof(buffer), 8);

	return EXIT_SUCCESS;
}
