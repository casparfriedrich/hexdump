#include <stdint.h>
#include <stdlib.h>

extern void hexdump(const void *buffer, uint32_t length, uint32_t offset, const char *title);

int main(void)
{
	char buffer[0x100+1];
	hexdump(buffer, sizeof(buffer), 0, __PRETTY_FUNCTION__);

	return EXIT_SUCCESS;
}
