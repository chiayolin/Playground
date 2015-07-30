#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cs50.h>

int greedy(int cent);

int main(void) {
	float amount = 0;
	for(;;) { 
		printf("How Much Change is Owed?\n");
		amount = GetFloat();
		
		if(amount < 0) 
			continue; 
		else 
			break;
	}
	
	printf("%d\n", greedy((int) 
		round(amount * 100)));
	return EXIT_SUCCESS;
	
}

int greedy(int cent) {
	int coin = 0;

	coin += cent / 25;
	cent %= 25;
	coin += cent / 10;
	cent %= 10;
	coin += cent / 5;
	cent %= 5;
	coin += cent;
	
	return coin;
}
