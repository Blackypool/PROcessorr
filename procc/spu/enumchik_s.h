#ifndef ENUMICHE
#define ENUMICHE

enum for_user
{
    STK_capacity = 10,
    RET_capacity = 5,
    OPE_rativ_ka = 100,
    NUM_label_ss = 5
};

#define FILE_for_SPU "quadr_into_txt.txt" 
#define FILE_for_ASM "quadratic.asm"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <getopt.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include "constructor.h"
#include "push_pop.h"
// #include "file_commands.h"

typedef int ans_typ;

#define ASSERTICHE(ptr, ret) \
        if((ptr) == NULL) {   \
            fprintf(stderr, "\nassert react in line {%d}\nfile {%s}\n", __LINE__, __FILE__, strerror(errno)); \
            return ret; \
        }


#define ASSCANF(ret)   \
        if((ret) < 0) { \
            fprintf(stderr, "\nsscanf ruined in line {%d}\nfile {%s}\n", __LINE__, __FILE__, strerror(errno)); \
            return  NULL; \
        }


#define LOGIC(MASK, func_type)   \
        if((MASK & operation)){   \
            func_type(data, stk_ret, line, str_str, lines_all, push_memory, operation);\
            return SU_CC_ESS;\
        }


#define DEBUG printf("hranilische[%d] = {%d} = (%s)[%d}\n", sche, hranilische[sche], str_str[lin], lin)
            

#define ST_PP(data)\
        int v_1 = stack_pop(data);\
        int v_2 = stack_pop(data);


#define TO_MUSH_ARG \
        struct stk* data, struct stk* stk_ret, int &line, int* str_str, int lines_all, int* push_memory, int operation


#define FOR_SW(line)\
        operation = str_str[line];


struct SPU
{
    int* ram       = 0;
    stk  start_stk = {};
    stk  stk_ret   = {};
};


struct ASM
{
    int* black_metka = 0;
    char ** str_str  = 0;
};


struct operatio
{
    char    opera[16];
    int     maska;
    size_t  len_len;
    int     need_param;
};


enum calcic
{

    _CALC_  = 0x00000011,
    ADD_    = 0x00000012,
    SUB_    = 0x00000013,
    MUL_    = 0x00000014,
    DIV_    = 0x00000015,     
    POW_    = 0x00000016,
    SQRT_   = 0x00000017,
    
    _BASE_  = 0x00000110,
    PUSH_   = 0x00000120,
    OUT_    = 0x00000130,
    HLT_    = 0x00000140,
    
    _REG_   = 0x00001100,
    POPREG_ = 0x00002100,   
    PSHREG_ = 0x00003100,

    _GAMMY_ = 0x00001001,
    JMP_    = 0x00001002,
    JB_     = 0x00001003,
    JBE_    = 0x00001004,
    JA_     = 0x00001005,
    JAE_    = 0x00001006,                 
    JE_     = 0x00001007,                   
    JNE_    = 0x00001008,

    _FUNCN_ = 0x00000101,
    RET_    = 0x00000707,
    CALL_   = 0x00000808,

    _MEMOR_ = 0x00001010,
    POPM_   = 0x00002020,
    PUSHM_  = 0x00003030,

    _INT_   = 0x00001111,
};

enum er_sC
{
    SU_CC_ESS = 1,
    ER_R_OR   = 911
};

#endif
