/* 
 * Description:
 * ASDC - Average and Standard Deviation Calculator
 * 
 * Author: Chiayo Lin
 * Email : chiayo.lin@gmail.com
 * Date  : Sep 04, 2014
 * Site  : www.chiayolin.org
 *
 */

#include <stdio.h>
#include <math.h>
#define MAX 1000

float square(float b);

int main() {
	float input[MAX] = { 0 };
	int len, index = 1;
	float sum, avg, sd;
	sd = avg = len = sum = 0;

	printf("Lenght            : ");
	scanf("%d", &len);

	while(index <= len) {
		printf("Input[%02d]         : ", index);
		scanf("%f", &input[index]);
		sum = input[index] + sum;
		++index;
	}

	avg = sum / len;
	sum = 0;
	index = 1;

	int i;
	for(i = 0; i < len; i++) {
		input[index] = input[index] - avg;
		sum = sum + square(input[index]);
		++index;
	} 

	sd = sqrt(sum / len);
	
	printf("\nAverage           : %.3f\n", avg);
	printf("Standard Deviation: %.3f\n", sd);

	return 0;
}

float square(float b) {
	float s;
	s = b * b;

	return s;
}
