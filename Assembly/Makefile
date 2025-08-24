# Makefile for compiling C code to RISC-V assembly (no machine code)
# Assumes riscv64-unknown-elf-gcc is in PATH
# we will code out in C then stop right before RISC-V assembly to understand RISC-V

CC = riscv64-unknown-elf-gcc
CFLAGS = -S -O0 -Wall -Wextra   # -S stops at assembly, -O0 disables optimizations
SRC = $(wildcard *.c)
ASM = $(SRC:.c=.s)

# Default target
all: $(ASM)

# Rule: .c -> .s
%.s: %.c
	$(CC) $(CFLAGS) $< -o $@

# Clean up generated files
clean:
	rm -f $(ASM)
## testing github fix