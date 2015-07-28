#include <stdio.h>

int main(void) {
	long int number = 600851475143, divisor = 2;
	
	while(number / divisor != 0) {
		if(number % divisor != 0)
			divisor++;
		else {
			number /= divisor;
			printf("%ld\t", divisor);
		}
	}

	puts("");
	return 0;
}
