#include <stdio.h>

#define MAX 1000

int main(void) {
	int number, i;
	number = i = 0;
	scanf("%d", &number);
	
	double resistors[MAX];
	for(i = 0; i < number;
		scanf("%lf", &resistors[i++]));
	
	double r_tot = 0;
	for(i = 0; i < number;
		r_tot += 1.0 / resistors[i++]);
	r_tot = 1.0 / r_tot;

	printf("%lf\n", r_tot);

	return 0;
}
