/* 
 * Description:
 * ASDC - Average and Standard Deviation Calculator
 * 
 * Author : Chiayo Lin
 * Email  : chiayo.lin@gmail.com
 * Date   : Sep 04, 2014
 * License: GPL 3.0
 *
 */

#include <stdio.h>
#include <math.h>

#define MAX 100

float square(float b) { 
	return b * b;
}

int main() {
	float input[MAX] = {};
	float sum, avg, sd;
	int len, index = 1;
	sd = avg = len = sum = 0;

	printf("lenght            : ");
	scanf("%d", &len);

	while(index <= len) {
		printf("input[%02d]         : ", index);
		scanf("%f", &input[index]);
		sum = input[index++] + sum;
	}

	/* Get average */
	avg = sum / len;
	sum = 0, index = 1;
	
	/* Get standard deviation */
	int i;
	for(i = 0; i < len; i++) {
		input[index] = input[index] - avg;
		sum = sum + square(input[index]);
		++index;
	} 
	sd = sqrt(sum / len);
	
	printf("\naverage           : %.3f\n", avg);
	printf("standard deviation: %.3f\n", sd);

	return 0;
}
