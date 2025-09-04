# # # # format 
# # # # Target: dependencies 
# # # #	action	
# # # #

# # CC = gcc 
# # CFLAGS = -Wall -Wextra -std=c99 -O2

# # R1:
# # 	./malloc 

# # R2: 
# # 	./Fibonacci

# # C1: malloc.o 
# # 	$(CC) $(CFLAGS) malloc.o -o malloc 

# # C2: Fibonacci.o
# # 	$(CC) $(CFLAGS) Fibonacci.o -o Fibonacci 


# # malloc.o: malloc.c 
# # 	$(CC) $(CFLAGS) -c malloc.c 

# # Fibonacci.o: Fibonacci.c 
# # 	$(CC) $(CFLAGS) -c Fibonacci.c 

# # clean:
# # 	rm *.o malloc Fibonacci


# # Grab the current folder name (used as executable name)
# TARGET := $(notdir $(CURDIR))

# # Collect all C files in the folder
# SRCS := $(wildcard *.c)
# OBJS := $(SRCS:.c=.o)

# # Compiler and flags
# CC := gcc
# CFLAGS := -Wall -Wextra -O0

# # Default target
# all: $(TARGET)

# # Link the final executable
# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) -o $@ $^

# # Compile each .c into .o
# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Run the program
# run: $(TARGET)
# 	./$(TARGET)

# # Clean up build files
# clean:
# 	rm -f $(OBJS) $(TARGET)

# ---- Settings ----
TARGET ?= program      # name of the executable
CC     := gcc
CFLAGS := -Wall -Wextra -O0

# ---- Build ----
.PHONY: build
build:
ifndef MAIN
	$(error Please provide MAIN=<file.c>)
endif
	$(CC) $(CFLAGS) -o $(TARGET) $(MAIN) $(SRCS)
	@echo "Built $(TARGET) from $(MAIN) $(SRCS)"

# ---- Run ----
.PHONY: run
run:
ifeq ($(wildcard $(TARGET)),)
	$(error No program built yet. Run 'make build MAIN=foo.c' first)
endif
	./$(TARGET)

# ---- Clean ----
.PHONY: clean
clean:
	rm -f $(TARGET) *.o
