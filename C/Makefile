# # format 
# # Target: dependencies 
# #	action	
# #

CC = gcc 
CFLAGS = -Wall -Wextra -std=c99 -O2

run:
	./malloc

C: malloc.o
	$(CC) $(CFLAGS) malloc.o -o malloc 

malloc.o: malloc.c 
	$(CC) $(CFLAGS) -c malloc.c 

clean:
	rm *.o malloc