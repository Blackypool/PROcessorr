#ifndef SWITCH
#define SWITCH

#include"enumchik_s.h"

#define ST_PP_CALC(data, uslovie)\
        int v_1 = stack_pop(data);\
        int v_2 = stack_pop(data); \
        stack_push(data, uslovie);  \
        printf("line[%d] = {%d}", line, uslovie);


#define ST_PP_JUMP(data, uslovie)   \
            line++;\
            int v_1 = stack_pop(data);\
            int v_2 = stack_pop(data); \
            if(uslovie)\
                line = str_str[line];    \
            else line++; \
            printf("line[%d] = {%d}", line, uslovie);

int calcc_func(TO_MUSH_ARG);

int steck_fucn(TO_MUSH_ARG);

int registors(TO_MUSH_ARG);

int jump_mishki_gammy(TO_MUSH_ARG);

int for_functions(TO_MUSH_ARG);

int work_with_memory (TO_MUSH_ARG);

int in_func(TO_MUSH_ARG);

#endif