//Uses the default C standard (GNU89)
//Nohl Egan
//250964782
//This program is the header file containing the function prototypes for each function in ciphers.c, and the macro-defined constants.

typedef char *plaintext;
typedef char *ciphertext;
typedef char *k;
typedef int key;
typedef double letters[26];

char * caesar_encrypt(char *plaintext, int key);
char * caesar_decrypt(char *ciphtertext, int key);
char * vigen_encrypt(char *plaintext, char *k);
char * vigen_decrypt(char *ciphertext, char *k);
void freq_analysis(char *ciphertext, double letters[26]);
