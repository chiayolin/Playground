#include <stdio.h>
#include <cs50.h>

int main(void) {
	int h;
	do printf("height: "), 
		h = GetInt(); while(h < 0 || h > 23);

	int i, j, k;
	j = k = 0;
	
	for(i = 0; i < h; i++, j = k = 0) {
		while(k++ < h - (i + 1))
			printf(" ");
		while(j++ <= i + 1)
			printf("#");
		puts("");
	}
	
	return 0;
}
