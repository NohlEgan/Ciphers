#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ciphers.h"

//Uses the default C standard (GNU89)
//Nohl Egan
//250964782
//This program contains the encryption and decryption functions for each type of cipher (Caesar and Vigenere)

char * caesar_encrypt(char *plaintext, int key){
	char *ciphertext = (char *) malloc(strlen(plaintext) * sizeof(char));
	
	//checking to make sure the string is dynamically allocated in memory
	if(ciphertext == NULL){
		printf("Error allocating memory!\n");
		exit(0);
	}

	strcpy(ciphertext, plaintext);
	int i = 0;
	//read through each character of the given string
	while(*(ciphertext+i) != '\0'){
		//checking to make sure that the current character being read is a letter
		if(toupper(*(ciphertext+i)) >= 65 && toupper(*(ciphertext+i)) <=90){
			//adjusting the key if it isn't between -26 or 26 (not inclusive)
			if(key >= 26){
				key = key % 26;
			}
			else if(key <= -26){
				while(key <= -26){
					key = key + 26;
				}
			}
			
			//adding key to the uppercase of the given character, then subtracting 65 so that it can be
			//modulo divided by 26
			*(ciphertext+i) = toupper(*(ciphertext+i)) + key - 65;
			//adjusting the character to make sure it ends up being a letter after encryption
			if(*(ciphertext+i) < 0){
				//modulo dividing for a negative number
				while(*(ciphertext+i) < 0){
					*(ciphertext+i) = *(ciphertext+i) + 26;
				}
			}
			else{
				*(ciphertext+i) = *(ciphertext+i) % 26;
			}
			*(ciphertext+i) = *(ciphertext+i) + 65;
		}
		i++;
	}
	return ciphertext;
}

char * caesar_decrypt(char *ciphertext, int key){
	return caesar_encrypt(ciphertext, key * -1);
}

char * vigen_encrypt(char *plaintext, char *k){
	char *ciphertext = (char *) malloc(strlen(plaintext) * sizeof(char));
	
	if(ciphertext == NULL){
		printf("Error allocating memory!\n");
		exit(0);
	}
	
	strcpy(ciphertext, plaintext);
	int len = strlen(k);
	int i = 0;
	int n = 0;
	
	while(*(ciphertext+i) != '\0'){
		if(toupper(*(ciphertext+i)) >= 65 && toupper(*(ciphertext+i)) <= 90){
			*(ciphertext+i) = toupper(*(ciphertext+i)) + toupper(*(k+n)) - 130;
			if(*(ciphertext+i) < 0){
				while(*(ciphertext+i) < 0){
					*(ciphertext+i) = *(ciphertext+i) + 26;
				}
			}
			else{
				*(ciphertext+i) = *(ciphertext+i) % 26;
			}
			*(ciphertext+i) = *(ciphertext+i) + 65;
		}
		i++;
		n++;
		//padding the key
		if(n == len){
			n = 0;
		}
	}
	return ciphertext;
} 

char * vigen_decrypt(char *ciphertext, char *k){
	char *plaintext = (char *) malloc(strlen(ciphertext) * sizeof(char));
	
	if(plaintext == NULL){
		printf("Error allocating memory!\n");
		exit(0);
	}
	
	strcpy(plaintext, ciphertext);
	int len = strlen(k);
	int i = 0;
	int n = 0;
	
	while(*(plaintext+i) != '\0'){
		if(toupper(*(plaintext+i)) >= 65 && toupper(*(plaintext+i)) <= 90){
			*(plaintext+i) = toupper(*(plaintext+i)) - toupper(*(k+n));
			if(*(plaintext+i) < 0){
				while(*(plaintext+i) < 0){
					*(plaintext+i) = *(plaintext+i) + 26;
				}
			}
			//no need to check if it's greater than 25, since because they are 2 letters being subtracted,
			//it is impossible for them to be greater than 25
			*(plaintext+i) = *(plaintext+i) + 65;
		}
		i++;
		n++;
		if (n == len){
			n = 0;
		}
	}
	return plaintext;
}

void freq_analysis(char *ciphertext, double letters[26]){
	double *a = letters;
	int i, letter;
	double total = 0;
	//clearing the letters array
	for(i = 0; i < 26; i++){
		*(a+i) = 0;
	}
	
	//checking how many times each letter appears in the given string and storing the amount in the array
	i = 0;
	while(*(ciphertext+i) != '\0'){
		//printf("%s, %c\n", ciphertext, *(ciphertext+i));
		if(toupper(*(ciphertext+i)) >= 65 && toupper(*(ciphertext+i)) <= 90){
			letter = toupper(*(ciphertext+i)) - 65;
			*(a+letter) += 1;
			total++;
		}
		i++;
	}
	
	//averaging each of the amounts stored in the array
	for(i = 0; i < 26; i++){
		*(a+i) = (*(a+i) / total) * 100;
	}
}
