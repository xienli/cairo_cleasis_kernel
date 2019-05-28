/* TILE-Gx opcode information.
 *
 * Copyright 2011 Tilera Corporation. All Rights Reserved.
 *
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License
 *   as published by the Free Software Foundation, version 2.
 *
 *   This program is distributed in the hope that it will be useful, but
 *   WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, GOOD TITLE or
 *   NON INFRINGEMENT.  See the GNU General Public License for
 *   more details.
 *
 *
 *
 *
 *
 */

#ifndef opcode_tile_h
#define opcode_tile_h

#include <arch/opcode.h>


enum
{
  TILEGX_MAX_OPERANDS = 4 /* bfexts */
};

typedef enum
{
  TILEGX_OPC_BPT,
  TILEGX_OPC_INFO,
  TILEGX_OPC_INFOL,
  TILEGX_OPC_MOVE,
  TILEGX_OPC_MOVEI,
  TILEGX_OPC_MOVELI,
  TILEGX_OPC_PREFETCH,
  TILEGX_OPC_PREFETCH_ADD_L1,
  TILEGX_OPC_PREFETCH_ADD_L1_FAULT,
  TILEGX_OPC_PREFETCH_ADD_L2,
  TILEGX_OPC_PREFETCH_ADD_L2_FAULT,
  TILEGX_OPC_PREFETCH_ADD_L3,
  TILEGX_OPC_PREFETCH_ADD_L3_FAULT,
  TILEGX_OPC_PREFETCH_L1,
  TILEGX_OPC_PREFETCH_L1_FAULT,
  TILEGX_OPC_PREFETCH_L2,
  TILEGX_OPC_PREFETCH_L2_FAULT,
  TILEGX_OPC_PREFETCH_L3,
  TILEGX_OPC_PREFETCH_L3_FAULT,
  TILEGX_OPC_RAISE,
  TILEGX_OPC_ADD,
  TILEGX_OPC_ADDI,
  TILEGX_OPC_ADDLI,
  TILEGX_OPC_ADDX,
  TILEGX_OPC_ADDXI,
  TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXSC,
  TILEGX_OPC_AND,
  TILEGX_OPC_ANDI,
  TILEGX_OPC_BEQZ,
  TILEGX_OPC_BEQZT,
  TILEGX_OPC_BFEXTS,
  TILEGX_OPC_BFEXTU,
  TILEGX_OPC_BFINS,
  TILEGX_OPC_BGEZ,
  TILEGX_OPC_BGEZT,
  TILEGX_OPC_BGTZ,
  TILEGX_OPC_BGTZT,
  TILEGX_OPC_BLBC,
  TILEGX_OPC_BLBCT,
  TILEGX_OPC_BLBS,
  TILEGX_OPC_BLBST,
  TILEGX_OPC_BLEZ,
  TILEGX_OPC_BLEZT,
  TILEGX_OPC_BLTZ,
  TILEGX_OPC_BLTZT,
  TILEGX_OPC_BNEZ,
  TILEGX_OPC_BNEZT,
  TILEGX_OPC_CLZ,
  TILEGX_OPC_CMOVEQZ,
  TILEGX_OPC_CMOVNEZ,
  TILEGX_OPC_CMPEQ,
  TILEGX_OPC_CMPEQI,
  TILEGX_OPC_CMPEXCH,
  TILEGX_OPC_CMPEXCH4,
  TILEGX_OPC_CMPLES,
  TILEGX_OPC_CMPLEU,
  TILEGX_OPC_CMPLTS,
  TILEGX_OPC_CMPLTSI,
  TILEGX_OPC_CMPLTU,
  TILEGX_OPC_CMPLTUI,
  TILEGX_OPC_CMPNE,
  TILEGX_OPC_CMUL,
  TILEGX_OPC_CMULA,
  TILEGX_OPC_CMULAF,
  TILEGX_OPC_CMULF,
  TILEGX_OPC_CMULFR,
  TILEGX_OPC_CMULH,
  TILEGX_OPC_CMULHR,
  TILEGX_OPC_CRC32_32,
  TILEGX_OPC_CRC32_8,
  TILEGX_OPC_CTZ,
  TILEGX_OPC_DBLALIGN,
  TILEGX_OPC_DBLALIGN2,
  TILEGX_OPC_DBLALIGN4,
  TILEGX_OPC_DBLALIGN6,
  TILEGX_OPC_DRAIN,
  TILEGX_OPC_DTLBPR,
  TILEGX_OPC_EXCH,
  TILEGX_OPC_EXCH4,
  TILEGX_OPC_FDOUBLE_ADD_FLAGS,
  TILEGX_OPC_FDOUBLE_ADDSUB,
  TILEGX_OPC_FDOUBLE_MUL_FLAGS,
  TILEGX_OPC_FDOUBLE_PACK1,
  TILEGX_OPC_FDOUBLE_PACK2,
  TILEGX_OPC_FDOUBLE_SUB_FLAGS,
  TILEGX_OPC_FDOUBLE_UNPACK_MAX,
  TILEGX_OPC_FDOUBLE_UNPACK_MIN,
  TILEGX_OPC_FETCHADD,
  TILEGX_OPC_FETCHADD4,
  TILEGX_OPC_FETCHADDGEZ,
  TILEGX_OPC_FETCHADDGEZ4,
  TILEGX_OPC_FETCHAND,
  TILEGX_OPC_FETCHAND4,
  TILEGX_OPC_FETCHOR,
  TILEGX_OPC_FETCHOR4,
  TILEGX_OPC_FINV,
  TILEGX_OPC_FLUSH,
  TILEGX_OPC_FLUSHWB,
  TILEGX_OPC_FNOP,
  TILEGX_OPC_FSINGLE_ADD1,
  TILEGX_OPC_FSINGLE_ADDSUB2,
  TILEGX_OPC_FSINGLE_MUL1,
  TILEGX_OPC_FSINGLE_MUL2,
  TILEGX_OPC_FSINGLE_PACK1,
  TILEGX_OPC_FSINGLE_PACK2,
  TILEGX_OPC_FSINGLE_SUB1,
  TILEGX_OPC_ICOH,
  TILEGX_OPC_ILL,
  TILEGX_OPC_INV,
  TILEGX_OPC_IRET,
  TILEGX_OPC_J,
  TILEGX_OPC_JAL,
  TILEGX_OPC_JALR,
  TILEGX_OPC_JALRP,
  TILEGX_OPC_JR,
  TILEGX_OPC_JRP,
  TILEGX_OPC_LD,
  TILEGX_OPC_LD1S,
  TILEGX_OPC_LD1S_ADD,
  TILEGX_OPC_LD1U,
  TILEGX_OPC_LD1U_ADD,
  TILEGX_OPC_LD2S,
  TILEGX_OPC_LD2S_ADD,
  TILEGX_OPC_LD2U,
  TILEGX_OPC_LD2U_ADD,
  TILEGX_OPC_LD4S,
  TILEGX_OPC_LD4S_ADD,
  TILEGX_OPC_LD4U,
  TILEGX_OPC_LD4U_ADD,
  TILEGX_OPC_LD_ADD,
  TILEGX_OPC_LDNA,
  TILEGX_OPC_LDNA_ADD,
  TILEGX_OPC_LDNT,
  TILEGX_OPC_LDNT1S,
  TILEGX_OPC_LDNT1S_ADD,
  TILEGX_OPC_LDNT1U,
  TILEGX_OPC_LDNT1U_ADD,
  TILEGX_OPC_LDNT2S,
  TILEGX_OPC_LDNT2S_ADD,
  TILEGX_OPC_LDNT2U,
  TILEGX_OPC_LDNT2U_ADD,
  TILEGX_OPC_LDNT4S,
  TILEGX_OPC_LDNT4S_ADD,
  TILEGX_OPC_LDNT4U,
  TILEGX_OPC_LDNT4U_ADD,
  TILEGX_OPC_LDNT_ADD,
  TILEGX_OPC_LNK,
  TILEGX_OPC_MF,
  TILEGX_OPC_MFSPR,
  TILEGX_OPC_MM,
  TILEGX_OPC_MNZ,
  TILEGX_OPC_MTSPR,
  TILEGX_OPC_MUL_HS_HS,
  TILEGX_OPC_MUL_HS_HU,
  TILEGX_OPC_MUL_HS_LS,
  TILEGX_OPC_MUL_HS_LU,
  TILEGX_OPC_MUL_HU_HU,
  TILEGX_OPC_MUL_HU_LS,
  TILEGX_OPC_MUL_HU_LU,
  TILEGX_OPC_MUL_LS_LS,
  TILEGX_OPC_MUL_LS_LU,
  TILEGX_OPC_MUL_LU_LU,
  TILEGX_OPC_MULA_HS_HS,
  TILEGX_OPC_MULA_HS_HU,
  TILEGX_OPC_MULA_HS_LS,
  TILEGX_OPC_MULA_HS_LU,
  TILEGX_OPC_MULA_HU_HU,
  TILEGX_OPC_MULA_HU_LS,
  TILEGX_OPC_MULA_HU_LU,
  TILEGX_OPC_MULA_LS_LS,
  TILEGX_OPC_MULA_LS_LU,
  TILEGX_OPC_MULA_LU_LU,
  TILEGX_OPC_MULAX,
  TILEGX_OPC_MULX,
  TILEGX_OPC_MZ,
  TILEGX_OPC_NAP,
  TILEGX_OPC_NOP,
  TILEGX_OPC_NOR,
  TILEGX_OPC_OR,
  TILEGX_OPC_ORI,
  TILEGX_OPC_PCNT,
  TILEGX_OPC_REVBITS,
  TILEGX_OPC_REVBYTES,
  TILEGX_OPC_ROTL,
  TILEGX_OPC_ROTLI,
  TILEGX_OPC_SHL,
  TILEGX_OPC_SHL16INSLI,
  TILEGX_OPC_SHL1ADD,
  TILEGX_OPC_SHL1ADDX,
  TILEGX_OPC_SHL2ADD,
  TILEGX_OPC_SHL2ADDX,
  TILEGX_OPC_SHL3ADD,
  TILEGX_OPC_SHL3ADDX,
  TILEGX_OPC_SHLI,
  TILEGX_OPC_SHLX,
  TILEGX_OPC_SHLXI,
  TILEGX_OPC_SHRS,
  TILEGX_OPC_SHRSI,
  TILEGX_OPC_SHRU,
  TILEGX_OPC_SHRUI,
  TILEGX_OPC_SHRUX,
  TILEGX_OPC_SHRUXI,
  TILEGX_OPC_SHUFFLEBYTES,
  TILEGX_OPC_ST,
  TILEGX_OPC_ST1,
  TILEGX_OPC_ST1_ADD,
  TILEGX_OPC_ST2,
  TILEGX_OPC_ST2_ADD,
  TILEGX_OPC_ST4,
  TILEGX_OPC_ST4_ADD,
  TILEGX_OPC_ST_ADD,
  TILEGX_OPC_STNT,
  TILEGX_OPC_STNT1,
  TILEGX_OPC_STNT1_ADD,
  TILEGX_OPC_STNT2,
  TILEGX_OPC_STNT2_ADD,
  TILEGX_OPC_STNT4,
  TILEGX_OPC_STNT4_ADD,
  TILEGX_OPC_STNT_ADD,
  TILEGX_OPC_SUB,
  TILEGX_OPC_SUBX,
  TILEGX_OPC_SUBXSC,
  TILEGX_OPC_SWINT0,
  TILEGX_OPC_SWINT1,
  TILEGX_OPC_SWINT2,
  TILEGX_OPC_SWINT3,
  TILEGX_OPC_TBLIDXB0,
  TILEGX_OPC_TBLIDXB1,
  TILEGX_OPC_TBLIDXB2,
  TILEGX_OPC_TBLIDXB3,
  TILEGX_OPC_V1ADD,
  TILEGX_OPC_V1ADDI,
  TILEGX_OPC_V1ADDUC,
  TILEGX_OPC_V1ADIFFU,
  TILEGX_OPC_V1AVGU,
  TILEGX_OPC_V1CMPEQ,
  TILEGX_OPC_V1CMPEQI,
  TILEGX_OPC_V1CMPLES,
  TILEGX_OPC_V1CMPLEU,
  TILEGX_OPC_V1CMPLTS,
  TILEGX_OPC_V1CMPLTSI,
  TILEGX_OPC_V1CMPLTU,
  TILEGX_OPC_V1CMPLTUI,
  TILEGX_OPC_V1CMPNE,
  TILEGX_OPC_V1DDOTPU,
  TILEGX_OPC_V1DDOTPUA,
  TILEGX_OPC_V1DDOTPUS,
  TILEGX_OPC_V1DDOTPUSA,
  TILEGX_OPC_V1DOTP,
  TILEGX_OPC_V1DOTPA,
  TILEGX_OPC_V1DOTPU,
  TILEGX_OPC_V1DOTPUA,
  TILEGX_OPC_V1DOTPUS,
  TILEGX_OPC_V1DOTPUSA,
  TILEGX_OPC_V1INT_H,
  TILEGX_OPC_V1INT_L,
  TILEGX_OPC_V1MAXU,
  TILEGX_OPC_V1MAXUI,
  TILEGX_OPC_V1MINU,
  TILEGX_OPC_V1MINUI,
  TILEGX_OPC_V1MNZ,
  TILEGX_OPC_V1MULTU,
  TILEGX_OPC_V1MULU,
  TILEGX_OPC_V1MULUS,
  TILEGX_OPC_V1MZ,
  TILEGX_OPC_V1SADAU,
  TILEGX_OPC_V1SADU,
  TILEGX_OPC_V1SHL,
  TILEGX_OPC_V1SHLI,
  TILEGX_OPC_V1SHRS,
  TILEGX_OPC_V1SHRSI,
  TILEGX_OPC_V1SHRU,
  TILEGX_OPC_V1SHRUI,
  TILEGX_OPC_V1SUB,
  TILEGX_OPC_V1SUBUC,
  TILEGX_OPC_V2ADD,
  TILEGX_OPC_V2ADDI,
  TILEGX_OPC_V2ADDSC,
  TILEGX_OPC_V2ADIFFS,
  TILEGX_OPC_V2AVGS,
  TILEGX_OPC_V2CMPEQ,
  TILEGX_OPC_V2CMPEQI,
  TILEGX_OPC_V2CMPLES,
  TILEGX_OPC_V2CMPLEU,
  TILEGX_OPC_V2CMPLTS,
  TILEGX_OPC_V2CMPLTSI,
  TILEGX_OPC_V2CMPLTU,
  TILEGX_OPC_V2CMPLTUI,
  TILEGX_OPC_V2CMPNE,
  TILEGX_OPC_V2DOTP,
  TILEGX_OPC_V2DOTPA,
  TILEGX_OPC_V2INT_H,
  TILEGX_OPC_V2INT_L,
  TILEGX_OPC_V2MAXS,
  TILEGX_OPC_V2MAXSI,
  TILEGX_OPC_V2MINS,
  TILEGX_OPC_V2MINSI,
  TILEGX_OPC_V2MNZ,
  TILEGX_OPC_V2MULFSC,
  TILEGX_OPC_V2MULS,
  TILEGX_OPC_V2MULTS,
  TILEGX_OPC_V2MZ,
  TILEGX_OPC_V2PACKH,
  TILEGX_OPC_V2PACKL,
  TILEGX_OPC_V2PACKUC,
  TILEGX_OPC_V2SADAS,
  TILEGX_OPC_V2SADAU,
  TILEGX_OPC_V2SADS,
  TILEGX_OPC_V2SADU,
  TILEGX_OPC_V2SHL,
  TILEGX_OPC_V2SHLI,
  TILEGX_OPC_V2SHLSC,
  TILEGX_OPC_V2SHRS,
  TILEGX_OPC_V2SHRSI,
  TILEGX_OPC_V2SHRU,
  TILEGX_OPC_V2SHRUI,
  TILEGX_OPC_V2SUB,
  TILEGX_OPC_V2SUBSC,
  TILEGX_OPC_V4ADD,
  TILEGX_OPC_V4ADDSC,
  TILEGX_OPC_V4INT_H,
  TILEGX_OPC_V4INT_L,
  TILEGX_OPC_V4PACKSC,
  TILEGX_OPC_V4SHL,
  TILEGX_OPC_V4SHLSC,
  TILEGX_OPC_V4SHRS,
  TILEGX_OPC_V4SHRU,
  TILEGX_OPC_V4SUB,
  TILEGX_OPC_V4SUBSC,
  TILEGX_OPC_WH64,
  TILEGX_OPC_XOR,
  TILEGX_OPC_XORI,
  TILEGX_OPC_NONE
} tilegx_mnemonic;



typedef enum
{
  TILEGX_PIPELINE_X0,
  TILEGX_PIPELINE_X1,
  TILEGX_PIPELINE_Y0,
  TILEGX_PIPELINE_Y1,
  TILEGX_PIPELINE_Y2,
} tilegx_pipeline;

#define tilegx_is_x_pipeline(p) ((int)(p) <= (int)TILEGX_PIPELINE_X1)

typedef enum
{
  TILEGX_OP_TYPE_REGISTER,
  TILEGX_OP_TYPE_IMMEDIATE,
  TILEGX_OP_TYPE_ADDRESS,
  TILEGX_OP_TYPE_SPR
} tilegx_operand_type;

struct tilegx_operand
{
  /* Is this operand a register, immediate or address? */
  tilegx_operand_type type;

  /* The default relocation type for this operand.  */
  signed int default_reloc : 16;

  /* How many bits is this value? (used for range checking) */
  unsigned int num_bits : 5;

  /* Is the value signed? (used for range checking) */
  unsigned int is_signed : 1;

  /* Is this operand a source register? */
  unsigned int is_src_reg : 1;

  /* Is this operand written? (i.e. is it a destination register) */
  unsigned int is_dest_reg : 1;

  /* Is this operand PC-relative? */
  unsigned int is_pc_relative : 1;

  /* By how many bits do we right shift the value before inserting? */
  unsigned int rightshift : 2;

  /* Return the bits for this operand to be ORed into an existing bundle. */
  tilegx_bundle_bits (*insert) (int op);

  /* Extract this operand and return it. */
  unsigned int (*extract) (tilegx_bundle_bits bundle);
};


extern const struct tilegx_operand tilegx_operands[];

/* One finite-state machine per pipe for rapid instruction decoding. */
extern const unsigned short * const
tilegx_bundle_decoder_fsms[TILEGX_NUM_PIPELINE_ENCODINGS];


struct tilegx_opcode
{
  /* The opcode mnemonic, e.g. "add" */
  const char *name;

  /* The enum value for this mnemonic. */
  tilegx_mnemonic mnemonic;

  /* A bit mask of which of the five pipes this instruction
     is compatible with:
     X0  0x01
     X1  0x02
     Y0  0x04
     Y1  0x08
     Y2  0x10 */
  unsigned char pipes;

  /* How many operands are there? */
  unsigned char num_operands;

  /* Which register does this write implicitly, or TREG_ZERO if none? */
  unsigned char implicitly_written_register;

  /* Can this be bundled with other instructions (almost always true). */
  unsigned char can_bundle;

  /* The description of the operands. Each of these is an
   * index into the tilegx_operands[] table. */
  unsigned char operands[TILEGX_NUM_PIPELINE_ENCODINGS][TILEGX_MAX_OPERANDS];

};

extern const struct tilegx_opcode tilegx_opcodes[];

/* Used for non-textual disassembly into structs. */
struct tilegx_decoded_instruction
{
  const struct tilegx_opcode *opcode;
  const struct tilegx_operand *operands[TILEGX_MAX_OPERANDS];
  long long operand_values[TILEGX_MAX_OPERANDS];
};


/* Disassemble a bundle into a struct for machine processing. */
extern int parse_insn_tilegx(tilegx_bundle_bits bits,
                             unsigned long long pc,
                             struct tilegx_decoded_instruction
                             decoded[TILEGX_MAX_INSTRUCTIONS_PER_BUNDLE]);



#endif /* opcode_tilegx_h */
