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

void hexdump(const void *buffer, int buffer_length, int offset, int (*putchar)(int))
{
	static const int num_address_digits = 8;
	static const int num_bytes_per_line = 16;
	static const char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7',
	                              '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	static const unsigned char *bytes = 0;
	static int start_of_section = 0;
	static int end_of_section = 0;

	bytes = buffer;
	start_of_section = offset - offset % num_bytes_per_line;
	end_of_section = start_of_section + num_bytes_per_line;

	if (offset >= buffer_length) {
		return;
	}

	for (int i = num_address_digits; i > 0; i--) {
		putchar(digits[(start_of_section >> ((i - 1) << 2)) & 15]);
	}

	putchar(' ');
	putchar(' ');

	for (int i = start_of_section; i < end_of_section; i++) {

		if (i - start_of_section == num_bytes_per_line >> 1) {
			putchar(' ');
		}

		if (i >= offset && i < buffer_length) {
			putchar(digits[bytes[i] >> 4]);
			putchar(digits[bytes[i] & 15]);
		} else {
			putchar(' ');
			putchar(' ');
		}

		putchar(' ');
	}

	putchar(' ');
	putchar('|');

	for (int i = start_of_section; i < end_of_section; i++) {
		if (i >= offset && i < buffer_length) {
			putchar((bytes[i] > 0x1f) && (bytes[i] < 0x7f) ? bytes[i] : '.');
		} else {
			putchar(' ');
		}
	}

	putchar('|');
	putchar('\n');

	hexdump(buffer, buffer_length, end_of_section, putchar);
}
