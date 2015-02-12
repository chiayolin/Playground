#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define MAXLEN 1000

int main() {
	char input[MAXLEN], output[MAXLEN];
	uint8_t c;
	size_t i;
	
	c = i = 0;
	while((c = getchar()) != '\n')
		input[i++] = c;
	input[i] = '\0';
	
	const size_t key = 4;
	size_t posi = 0, c_key = key;

	for 
	for(i = 0; input[i] != '\0'; i++) {
		if(c_key > 8)
			c_key = 0;
		output[i] = input[i] + (3 * c_key++);
			
	}
	output[i] = '\0';
	
	printf("%s\n", output);
	return 0;
}
