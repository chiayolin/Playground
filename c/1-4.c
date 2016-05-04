#include <stdio.h>

#define C_TO_F(celcius) ((celcius / (5.0 / 9.0)) + 32)
#define HEADER "\033[1m\033[36mC\tF\n\033[0m"

int main(void) {
	printf(HEADER);

	float celsius;
	for(celsius = 0; celsius <= 40; printf("%.0f\t%3.1f\n", 
		celsius, C_TO_F(celsius)), ++celsius)
			;

	return 0;
}
