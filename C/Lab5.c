/*
 * Lab5.c
 * Minimal, working C translation of the provided pseudocode for
 * RISCV -> WASM translation. This file implements a self-contained
 * `RISCVtoWASM` function and small helpers. Translators are
 * intentionally simple placeholders that emit representative
 * WASM bytes so the control flow and structure from the pseudocode
 * are preserved.
 */

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

static uint32_t load_word(const uint8_t *ptr)
{
    /* little-endian 32-bit load */
    return (uint32_t)ptr[0]
         | ((uint32_t)ptr[1] << 8)
         | ((uint32_t)ptr[2] << 16)
         | ((uint32_t)ptr[3] << 24);
}

/* Placeholder: in a full converter this would build a table of
 * branch targets. For this minimal implementation we do nothing. */
static void generateTargetTable(const uint8_t *risc_v_ptr)
{
    (void)risc_v_ptr;
}

/* Placeholder: always return 0 (no forward/backward loop markers).
 * A real implementation would consult the generated target table. */
static unsigned readTargetCount(const uint8_t *start, const uint8_t *instr_ptr, int forward)
{
    (void)start; (void)instr_ptr; (void)forward;
    return 0;
}

static size_t translateIType(uint8_t *out, const uint8_t *instr_ptr, uint8_t wasm_opcode)
{
    /* Minimal encoding: emit the opcode and a single-byte immediate (0) */
    (void)instr_ptr;
    out[0] = wasm_opcode;
    out[1] = 0x00;
    return 2;
}

static size_t translateRType(uint8_t *out, const uint8_t *instr_ptr, uint8_t wasm_opcode)
{
    /* Minimal encoding: emit the opcode only */
    (void)instr_ptr;
    out[0] = wasm_opcode;
    return 1;
}

static size_t translateBranch(uint8_t *out, const uint8_t *instr_ptr, uint8_t wasm_opcode)
{
    /* Minimal encoding: emit the branch opcode and a dummy depth 0 */
    (void)instr_ptr;
    out[0] = wasm_opcode;
    out[1] = 0x00;
    return 2;
}

/* Top-level translation function. It follows the structure of the
 * pseudocode: scan instructions until sentinel 0xFFFFFFFF, emit
 * loop/end markers for branch targets (none here), translate each
 * instruction and append a small WASM epilogue. */
size_t RISCVtoWASM(const uint8_t *risc_v_ptr, uint8_t *wasm_output_ptr)
{
    generateTargetTable(risc_v_ptr);

    size_t bytes_written = 0;
    const uint8_t *current_instruction_ptr = risc_v_ptr;

    while (1) {
        uint32_t instruction = load_word(current_instruction_ptr);
        if (instruction == 0xFFFFFFFFu)
            break;

        unsigned forward_count = readTargetCount(risc_v_ptr, current_instruction_ptr, 1);
        for (unsigned i = 0; i < forward_count; ++i) {
            *wasm_output_ptr++ = 0x0b; /* end */
            bytes_written += 1;
        }

        unsigned backward_count = readTargetCount(risc_v_ptr, current_instruction_ptr, 0);
        for (unsigned i = 0; i < backward_count; ++i) {
            *wasm_output_ptr++ = 0x03; /* loop */
            *wasm_output_ptr++ = 0x40; /* void */
            bytes_written += 2;
        }

        size_t n = 0;
        uint32_t opcode = instruction & 0x7Fu;

        if (opcode == 0x13u) { /* I-type */
            uint32_t funct3 = (instruction >> 12) & 0x7u;
            if (funct3 == 0x0u) { /* ADDI */
                n = translateIType(wasm_output_ptr, current_instruction_ptr, 0x6a);
            } else if (funct3 == 0x7u) { /* ANDI */
                n = translateIType(wasm_output_ptr, current_instruction_ptr, 0x71);
            }
        } else if (opcode == 0x33u) { /* R-type */
            uint32_t funct3 = (instruction >> 12) & 0x7u;
            uint32_t funct7 = (instruction >> 25) & 0x7Fu;
            if (funct3 == 0x0u && funct7 == 0x00u) { /* ADD */
                n = translateRType(wasm_output_ptr, current_instruction_ptr, 0x6a);
            } else if (funct3 == 0x0u && funct7 == 0x20u) { /* SUB */
                n = translateRType(wasm_output_ptr, current_instruction_ptr, 0x6b);
            }
        } else if (opcode == 0x63u) { /* Branch */
            uint32_t funct3 = (instruction >> 12) & 0x7u;
            if (funct3 == 0x0u) { /* BEQ */
                n = translateBranch(wasm_output_ptr, current_instruction_ptr, 0x46);
            } else if (funct3 == 0x5u) { /* BGE */
                n = translateBranch(wasm_output_ptr, current_instruction_ptr, 0x4e);
            }
        }

        bytes_written += n;
        wasm_output_ptr += n;
        current_instruction_ptr += 4;
    }

    /* Epilogue: get_local 0, return, end (4 bytes) */
    *wasm_output_ptr++ = 0x20; /* get_local */
    *wasm_output_ptr++ = 0x00; /* 0 */
    *wasm_output_ptr++ = 0x0f; /* return */
    *wasm_output_ptr++ = 0x0b; /* end */
    bytes_written += 4;

    return bytes_written;
}

/* Small test harness to demonstrate the converter. Builds a tiny
 * RISC-V instruction stream ending with the sentinel and prints out
 * the produced WASM bytes in hex. */
int main(void)
{
    /* A few dummy 32-bit little-endian instructions followed by sentinel */
    uint8_t risc[] = {
        0x13, 0x00, 0x00, 0x00, /* I-type (opcode 0x13) */
        0x33, 0x00, 0x00, 0x00, /* R-type (opcode 0x33) */
        0x63, 0x00, 0x00, 0x00, /* Branch (opcode 0x63) */
        0xFF, 0xFF, 0xFF, 0xFF  /* sentinel */
    };

    uint8_t wasm[256];
    memset(wasm, 0, sizeof(wasm));

    size_t written = RISCVtoWASM(risc, wasm);
    printf("bytes_written=%zu\n", written);
    for (size_t i = 0; i < written; ++i)
        printf("%02x ", wasm[i]);
    printf("\n");

    return 0;
}