#include <stdio.h>

/* Tomohiko Sakamoto's Algorithm */
int dow(int, int, int);

/* dow algorithm */
int dow(int y, int m, int d) { 
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4}, 
			   c = 0; // day offset;
	y -= m < 3;
	return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d + c) % 7;
}

int main(void) {
	unsigned int y, m, d;
	y = m = d = 0;

	printf("month / day / year\n");
	scanf("%d %d %d", &m, &d, &y);
	
	printf("%d\n", dow(y, m, d));
	return 0;
}
