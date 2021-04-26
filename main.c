#include <stdio.h>

int main() {
	int c;

	do {
		c = getchar();
		switch (c) {
		case ' ':
			fputs("\033[90m·\033[m", stdout);
			break;
		case '\t':
			fputs("\033[90m»       \033[m", stdout);
			break;
		case '\n':
			puts("\033[90m$\033[m");
			break;
		case EOF:
			break;
		case 0x7f:
			fputs("\033[7m^?\033[m", stdout);
			break;
		default:
			if (0 <= c && c < 0x20) {
				printf("\033[7m^%c\033[m", c|0x40);
			} else if (c == 0xc0 || c == 0xc1 || c >= 0xf5) {
				printf("\033[7m<0x%02X>\033[m", c);
			} else {
				putchar(c);
			}
			break;
		}
	} while (c != EOF);

	return 0;
}
