# Makefile for compiling C code to RISC-V assembly (no machine code)
# Assumes riscv64-unknown-elf-gcc is in PATH
# we will code out in C then stop right before RISC-V assembly to understand RISC-V

# CC = riscv64-unknown-elf-gcc
# CFLAGS = -S -O0 -Wall -Wextra   # -S stops at assembly, -O0 disables optimizations
# SRC = $(wildcard *.c)
# ASM = $(SRC:.c=.s)

# # Default target
# all: $(ASM)

# # Rule: .c -> .s
# %.s: %.c
# 	$(CC) $(CFLAGS) $< -o $@

# # Clean up generated files
# clean:
# 	rm -f $(ASM)
# ## testing github fix


# ---- Toolchain (32-bit by default) ----
# If you have a pure 32-bit toolchain, you can do:
#   make RISCV_PREFIX=riscv32-unknown-elf
RISCV_PREFIX ?= riscv64-unknown-elf
CC           := $(RISCV_PREFIX)-gcc

# ---- Target ISA/ABI (32-bit) ----
# Common 32-bit combo: rv32imac + ilp32
ARCH ?= rv32imac
ABI  ?= ilp32

# -S: stop at assembly; -O0: no opts; add ISA/ABI flags
CFLAGS  := -S -O0 -Wall -Wextra -march=$(ARCH) -mabi=$(ABI)

SRC := $(wildcard *.c)
ASM := $(SRC:.c=.s)

.PHONY: all clean
.DEFAULT_GOAL := all

# Build all .s from .c
all: $(ASM)

# Rule: .c -> .s (assembly)
%.s: %.c
	$(CC) $(CFLAGS) $< -o $@

# Clean up generated files
clean:
	rm -f $(ASM)
