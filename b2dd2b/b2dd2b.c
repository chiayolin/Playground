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
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define PRT_HELP printf("use b2dd2b -h for help\n");
#define MAX 1000

int getaton(int array[MAX]); /* Read ASCII numbers into an array, convert to numbers, return size */
int btod(int binary[MAX], const int size); /* Convert Bin. to Dec. */
int dtob(int decimal, int binary[MAX]); /* Convert Dec. to Bin. */
void printa(const int array[MAX], const int size); /* Print an array */
void reverse(int array[MAX], const int size); /* Reverse an array */

int main(const int argc, char *argv[]) {
	int binary[MAX], decimal;
	int size;
	
	/* Enter interactive mode if there are no command line options */
	if(argc == 1) { 
		int option;
		printf("[0] Dec to Bin\n[1] Bin to Dec\n");
		scanf("%d", &option);
		switch(option) {
			case 0: {
				scanf("%d", &decimal);
				size = dtob(decimal, binary);
				printa(binary, size);
				break; 
			}

			case 1: {
				size = getaton(binary);
				decimal = btod(binary, size);
				printf("%d\n", decimal);
				break;
			}
		
			default:
				printf("Not an option :-(\n");
				break;
		}
	} 
	
	/* Else read the options if argv[0][0] = '-' */
	else if((*++argv)[0] == '-') {
		char opt = *++argv[0];
		switch(opt) {
			case 'd':
				if(argv[1] == NULL)
					printf("agument to '-%s' is missing, expected a decimal number\n", argv[0]);
				else {
					decimal = atoi(argv[1]);
					size = dtob(decimal, binary);
					printa(binary, size);
				}
				break;

			case 'b':
				if(argv[1] == NULL)
					printf("agument to '-%s' is missing, expected a binary number\n", argv[0]);
				else {
					size = strlen(argv[1]);
					int i;
					for(i = 0; i < size; i++)
						binary[i] = argv[1][i] - '0'; 
					decimal = btod(binary, size);
					printf("%d\n", decimal);
				}
				break;

			case 'h':
				printf("Bin. to Dec. and Dec. to Bin. Converter\n");
				printf("usage: b2dd2b [options] [value ...]\n");
				printf("  -h      print this usage and text\n");
				printf("  -d      convert decimal to binary\n");
				printf("  -b      convert binary to decimal\n");
				break;

			default:
				  printf("b2dd2b: alas, invalid option '-%s' \n", argv[0]);
				  PRT_HELP
				  break;
		}
	}
	
	else {
		printf("alas, syntax error :-(\n");
		PRT_HELP
		return 1;
	}
			
	return 0;
}	

int dtob(int decimal, int binary[MAX]) {
	int i, size;
	if(decimal == 0) {
		binary[0] = 0;
		return 1;
	} /* To fix decimal = 0 prints a blank */

	for(i = 0, size = 0; decimal != 0; i++, size++) {
		binary[i] = decimal % 2;
		decimal = decimal / 2;
	}
	reverse(binary, size);

	return size; /* Return the size of array */
}

int btod(int binary[MAX], const int size) {
	int i, decimal;
	i = decimal = 0;

	reverse(binary, size);
	for(i = 0; i < size; i++)
		decimal = decimal + (binary[i] * (pow(2, i)));

	return decimal;
}

int getaton(int array[MAX]) {
	int i, c, size;
	getchar(); /* To avoid a return '\n' */

	while((c = getchar()) != '\n') {                                                                                                                             
		array[i] = c - '0'; /* Convert ASCII to interger */
		++i, ++size;
	}
	return size;
}

void printa(const int array[MAX], const int size) {
	int i;
	for(i = 0; i < size; i++)
		printf("%d", array[i]);
	printf("\n");
}

void reverse(int array[MAX], const int size) {
	int temp[MAX], i;
	for(i = 0; i < size; i++)
		temp[i] = array[i]; /* Copy array into a buffer */
	int j;
	for(i = 0, j = size - 1; j >= 0; i++, j--)
		array[i] = temp[j];
}
