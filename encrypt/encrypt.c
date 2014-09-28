#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXLEN 1000

void encrypt(char *input);
void decrypt(char *input);
int init_vector;

int main() {
	FILE *inputFilePointer, *outputFilePointer;
	char choice, string[MAXLEN] = {};
	extern int init_vector;
	int ch, i;
	bool encryption;
	i = ch  = encryption = choice = init_vector = 0;
	
	printf("[E]ncrypt or [D]ecrypt: ");
	scanf(" %c", &choice);
	switch(choice) {
		case 'e': case 'E': case '1':
			encryption = true;
			break;
		case 'd': case 'D': case '2':
			encryption = false;
			break;
		default:
			printf("Alas, \"%c\" is not an option!\n", choice);
			return 1;			
	}
	
	printf("Enter one digit interger init vector: ");
	scanf("%d", &init_vector);

	getchar();
	while((ch = getchar()) != '\n') 
		string[i++] = ch;

	(encryption) ? encrypt(string) : decrypt(string);

	return 0;
}

void encrypt(char *input) {
	extern int init_vector;
	int i, key = 0, len = strlen(input);
	key = init_vector;
	for(i = 0; i < len; i++) {
		if(key >= 9) key = 0;
		input[i] = input[i] ^ key;
		key = key + 1;
	}
	printf("%s\n", input);
}

void decrypt(char *input) {
	extern int init_vector;
	int i, key = 0, len = strlen(input);
	key = init_vector;
	for(i = 0; i < len; i++) {
		if(key >= 9) key = 0;
		input[i] = input[i] ^ key;
		key = key + 1;
	}
	printf("%s\n", input);
}
