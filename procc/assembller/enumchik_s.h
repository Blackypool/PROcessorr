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

#include "constructor.h"
#include "push_pop.h"
#include "file_commands.h"

typedef int ans_typ;


#define ASSERTICHE(ptr, ret) \
        if((ptr) == NULL) {   \
            perror("\nbad bad bad\n"); \
            return ret; \
        }


#define ASSCANF(ret)   \
        if((ret) < 0) { \
            perror("\nsscanf ruined\n"); \
            return  NULL; \
        }


#define LOGIC(MASK, func_type)   \
        if((MASK & operation)){   \
            func_type(data, stk_ret, line, str_str, lines_all, push_memory, operation);\
            return SU_CC_ESS;\
        }

            
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


struct operatio
{
    char    opera[16];
    int     maska;
    size_t  len_len;
    int     need_param;
};


enum calcic
{

    _CALC_  = 0x00000001,
    ADD_    = 0x00000002,
    SUB_    = 0x00000003,
    MUL_    = 0x00000004,
    DIV_    = 0x00000005,     
    POW_    = 0x00000006,
    SQRT_   = 0x00000007,
    
    _BASE_  = 0x00000010,
    PUSH_   = 0x00000020,
    OUT_    = 0x00000030,
    HLT_    = 0x00000040,
    
    _REG_   = 0x00010000,
    POPREG_ = 0x00020000,   
    PSHREG_ = 0x00030000,

    _GAMMY_ = 0x00001001,
    JMP_    = 0x00001002,
    JB_     = 0x00001003,
    JBE_    = 0x00001004,
    JA_     = 0x00001005,
    JAE_    = 0x00001006,                 
    JE_     = 0x00001007,                   
    JNE_    = 0x00001008,

    _FUNCN_ = 0x00000011,
    RET_    = 0x00000077,
    CALL_   = 0x00000088,

    _MEMOR_ = 0x00000110,
    POPM_   = 0x00000220,
    PUSHM_  = 0x00000330,

    _INT_    = 0x00100000,
};

enum er_sC
{
    SU_CC_ESS = 1,
    ER_R_OR   = 911
};

#endif
