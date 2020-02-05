#include <stdio.h>
#include <string.h>
#include "ciphers.h"

//Uses C standard C99
//Nohl Egan
//250964782
//This program contains the main function which will test the functions in ciphers.c 

int main(){
	char *ciphertext, *plaintext = (char *) malloc(256 * sizeof(char));
	char *text = (char *) malloc(256* sizeof(char));
	int cipherchoice;
	int key;
	double letters[26];
	
	printf("Input plaintext: ");
	scanf("%255[^\n]", plaintext);
	printf("\nAvailable Ciphers:\n1) Caesar\n2) Vigenere\n\nSelect Cipher: ");
	scanf("%d", &cipherchoice);
	
	//Caesar Cipher was chosen
	if(cipherchoice == 1){
		printf("\nInput key as number: ");
		
		//Error Checking
		if(scanf("%d", &key) != 1){
			printf("Error: Bad key!\n");
			return 1;
		}
		ciphertext = caesar_encrypt(plaintext, key);
		
		printf("\nPlaintext:\n%s\n\n", plaintext);
		printf("Ciphertext:\n%s\n\n", ciphertext);
		printf("Decrypted plaintext:\n%s\n\n", caesar_decrypt(ciphertext, key));
	}
	//Vigenere Cipher was chosen
	else if(cipherchoice == 2){
		printf("\nInput key as string: ");
		scanf("%255s", text);
		
		ciphertext = vigen_encrypt(plaintext, text);

		printf("\nPlaintext:\n%s\n\n", plaintext);
		printf("Ciphertext:\n%s\n\n", ciphertext);
		printf("Decrypted plaintext:\n%s\n\n", vigen_decrypt(ciphertext, text));
	}
	//An invalid choice was given
	else{
		printf("Error: Bad Selection!\n");
		return 1;
	}
	
	freq_analysis(ciphertext, letters);
	printf("Frequency analysis:\n");
	//going through the letters array to print out the frequency analysis
	for(key = 0; key < 26; key++){
		printf("%c: %.1f\n", key+65, letters[key]);
	}
	
	free(plaintext);
	free(ciphertext);
	free(text);
	return 0;
}
