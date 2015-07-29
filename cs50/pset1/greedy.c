#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
	uint64_t c = 0, a = 18446744073709551615;

	int i;
	for(i = 50; i != 0; i /= 5) {
		c += a / i;
		a %= i;
	}

	printf("%llu\n", c);
	return EXIT_SUCCESS;	
}
