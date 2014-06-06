/* 
   CYC 1.0

   Name:
   CYC - Chmod Vaule Counter

   Discriprion:
   This is a program that helps people who is new to 
   Linux to get the value after the command, chmod. 
   
   Author  : Chiayo Lin
   Email   : chiayo.lin@gail.com
   Site    : www.chiayolin.org
   Date    : April 6, 2014
   License : CC BY 2.0 
*/

#include <stdio.h>

int main () {
	char readable, writable, executable;
	int owner, group, other, buff, i;

	for(i = 0; i <= 2; i++) {
		printf("\n+---------------------------+\n");
		if(i == 0) printf("| Owner Permission Setting  |\n");
		if(i == 1) printf("| Group Permission Setting  |\n");
		if(i == 2) printf("| Other Permission Setting  |\n");
		printf("+---------------------------+\n");
		
		printf("Readable   (y/n) :");
		scanf(" %c", &readable);
		printf("Writable   (y/n) :");
		scanf(" %c", &writable);
		printf("Executable (y/n) :");
		scanf(" %c", &executable);

		if(readable   == 'y') buff += 4;
		if(writable   == 'y') buff += 2;
		if(executable == 'y') buff += 1;
		if(i == 0) owner = buff;
		if(i == 1) group = buff;
		if(i == 2) other = buff;
		readable = writable = executable = buff = 0;
		}

	printf("\n+---------------------------+\n");
	printf("| Chmod  Permission  Value  |\n");
	printf("+---------------------------+\n");
	printf("chmod %d%d%d\n\n", owner, group, other);
	return 0;
	
	}
