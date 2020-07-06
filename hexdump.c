/*
 * Copyright 2020 Caspar Friedrich <c.s.w.friedrich@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <stdint.h>
#include <stdio.h>

#define BYTES_PER_LINE 16u

void hexdump(const void *buffer, uint32_t length, uint32_t offset, const char *title)
{
	static const char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7',
	                              '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	const uint8_t *bytes = (const uint8_t *)buffer;
	const uint32_t start_of_section = offset - offset % BYTES_PER_LINE;
	const uint32_t end_of_section = start_of_section + BYTES_PER_LINE;

	if (offset >= length) {
		return;
	}

	if (title) {
		puts(title);
	}

	putchar(' ');
	putchar(' ');

	for (uint32_t i = 8; i > 0; i--) {
		putchar(digits[(start_of_section >> (i - 1) * 4u) % 16]);
	}

	putchar(' ');
	putchar('|');
	putchar(' ');

	for (uint32_t i = start_of_section; i < end_of_section; i++) {
		if (i % BYTES_PER_LINE) {
			putchar(' ');
		}

		if (i >= offset && i < length) {
			putchar(digits[bytes[i] >> 4u]);
			putchar(digits[bytes[i] & 15u]);
		} else {
			putchar(' ');
			putchar(' ');
		}
	}

	putchar(' ');
	putchar('|');
	putchar(' ');

	for (uint32_t i = start_of_section; i < end_of_section; i++) {
		if (i >= offset && i < length) {
			putchar((bytes[i] > 0x1f) && (bytes[i] < 0x7f) ? bytes[i] : '.');
		} else {
			putchar(' ');
		}
	}

	putchar('\n');

	hexdump(buffer, length, end_of_section, NULL);
}
