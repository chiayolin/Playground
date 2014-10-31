/*
 * b2dd2b.c
 * Binary to Decimal and Decimal to Binary Converter
 * Copyright (C) 2014  Chiayo Lin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdio.h>
#include <math.h>
#define MAX 1000

int btod(); /* Convert Bin. to Dec. */
int dtob(int decimal, int binary[MAX]); /* Convert Dec. to Bin. */
void reverse(int array[MAX], const int size); /* Reverse array */

int main() {
	int binary[MAX], decimal;

	int option;
	printf("[0] Dec to Bin\n[1] Bin to Dec\n");
	scanf("%d", &option);
	switch(option) {
		case 0: {
			int input;
			scanf("%d", &input);

			int size;
			size = dtob(input, binary);
			int i;
			for(i = 0; i < size; i++)
				printf("%d", binary[i]);
			printf("\n");
			break; 
		}

		case 1: {
			decimal = (btod());
			printf("%d\n", decimal);
			break;
		}
		
		default:
			printf("Not an option :-(\n");
			break;
	}

	return 0;
}	


int dtob(int decimal, int binary[MAX]) {
	int i, size;
	for(i = 0, size = 0; decimal != 0; i++, size++) {
		binary[i] = decimal % 2;
		decimal = decimal / 2;
	}
	
	reverse(binary, size);

	return size; /* Returns the size of array */
}

int btod() {
	int binary[MAX], decimal = 0;
	int c, i, size;
	c = i = size = 0;
	getchar();

	while((c = getchar()) != '\n') {
		binary[i] = c - '0'; /* Convert ASCII to interger */
		++i, ++size;
	}
	
	reverse(binary, size);

	for(i = 0; i < size; i++)
		decimal = decimal + (binary[i] * (pow(2, i)));

	return decimal;
}

void reverse(int array[MAX], const int size) {
	int temp[MAX], i;
	for(i = 0; i < size; i++)
		temp[i] = array[i];
	int j;
	for(i = 0, j = size - 1; j >= 0; i++, j--)
		array[i] = temp[j];
}
