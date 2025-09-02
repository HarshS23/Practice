# # format 
# # Target: dependencies 
# #	action	
# #

CC = gcc 
CFLAGS = -Wall -Wextra -std=c99 -O2

R1:
	./malloc 

R2: 
	./Fibonacci

C1: malloc.o 
	$(CC) $(CFLAGS) malloc.o -o malloc 

C2: Fibonacci.o
	$(CC) $(CFLAGS) Fibonacci.o -o Fibonacci 


malloc.o: malloc.c 
	$(CC) $(CFLAGS) -c malloc.c 

Fibonacci.o: Fibonacci.c 
	$(CC) $(CFLAGS) -c Fibonacci.c 

clean:
	rm *.o malloc Fibonacci