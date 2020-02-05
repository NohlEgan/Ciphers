#Uses the default C standard (GNU89)
#Nohl Egan
#250964782
#This is a makefile to compile and link my program

C = gcc
CFLAGS = -std=c99
RFLAGS = -f
EXNAME = ciphers

$(EXNAME): ciphers.o cipher_main.o
	$(CC) $(CFLAGS) -o $(EXNAME) ciphers.o cipher_main.o
ciphers.o: ciphers.c ciphers.h
	$(CC) $(CFLAGS) -c ciphers.c
cipher_main.o: cipher_main.c ciphers.h
	$(CC) $(CFLAGS) -c cipher_main.c
test:	$(EXNAME)
	$(EXNAME)
clean:
	rm $(RMFLAGS) $(EXNAME) *.o core
