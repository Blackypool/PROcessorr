#ifndef ALL_HHH
#define ALL_HHH

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include "readers.h"
#include "pechatnik_asm.h"
#include "for_fast_use.h"

#define ASSCANF(param, retern) \
        if((param) <= 0) { \
            fprintf(stderr, "\nparam ruined in line {%d}\nfile {%s}\n", __LINE__, __FILE__, strerror(errno)); \
            return  retern; \
        }


#define ASSERTICHE(ptr, ret) \
        if((ptr) == NULL) {   \
            fprintf(stderr, "\nassert react in line {%d} -- file {%s}\n", __LINE__, __FILE__, strerror(errno)); \
            return ret; \
        }


struct GEN
{
    size_t char_in_file = 0;
    char* full_txt = 0;
};


#endif