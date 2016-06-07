#include <stdio.h> 

int main(void) {
	return printf("%c\n", 127 & 0x2b) <= 0 ? 1 : 0;
}
