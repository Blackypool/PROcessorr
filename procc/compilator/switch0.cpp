#include "switch_func.h"

int calcc_func(TO_MUSH_ARG)
{
    switch(operation)
        {

            case ADD_:
                ST_PP_CALC(data, v_1 + v_2);

            break;

            case SUB_:
                ST_PP_CALC(data, v_2 - v_1);

            break;

            case MUL_:
                ST_PP_CALC(data, v_1 * v_2);

            break;
        
            case DIV_:
            {
                ST_PP(data);

                if (v_1 == 0)
                {
                    perror("Go out its not matan");
                    break;
                }

                stack_push(data, v_2 / v_1);
            }
            break;
                
            case POW_:
                ST_PP_CALC(data, pow(v_2, v_1));                
            
            break;

            case SQRT_:
            {
                int v_1 = stack_pop(data);
                
                if(v_1 < 0)
                {
                    perror("sqvrt ot <0");
                    break;
                }

                stack_push(data, sqrt(v_1));
            }
            break;

            default: break;

        }
}

int steck_fucn(TO_MUSH_ARG)
{
    switch (operation)
    {

        case PUSH_:
            {
                line++;
                int value = str_str[line];
                
                stack_push(data, value);
            }
            break;
        
        case OUT_:
            {
                int answer = stack_pop(data);
                printf("answer = (%d)", answer);
            }
            break;

        case HLT_:
            {
            line = lines_all;
            }
            break;

        default: break;

    }
}

int registors(TO_MUSH_ARG)
{
    switch (operation)
    {

        case POPREG_:
            {
                line++;
                int xx = str_str[line];

                int param = stack_pop(data);

                data->PuSh_rEg[xx] = param;
            }
            break;
                    
        case PSHREG_:
            {
                line++;
                int xx = str_str[line];

                stack_push(data, data->PuSh_rEg[xx]);
            }
            break;

        default: break;

    }
}

int jump_mishki_gammy(TO_MUSH_ARG)
{
    switch (operation)
    {

        case JMP_:
            {
                line++;

                line = str_str[line];
            }
            break;

        case JB_:
                ST_PP_JUMP(data, v_2 < v_1);

            break;
            
        case JBE_:
                ST_PP_JUMP(data, v_2 <= v_1);

            break;

        case JA_:
                ST_PP_JUMP(data, v_2 > v_1);

            break;

        case JAE_:
                ST_PP_JUMP(data, v_2 >= v_1);

            break;

        case JE_:
                ST_PP_JUMP(data, v_2 == v_1);

            break;

        case JNE_:
                ST_PP_JUMP(data, v_2 != v_1);

            break;

        default: break;

    }
}

int for_functions(TO_MUSH_ARG)
{
    switch (operation)
    {
        case CALL_:
            {
                int line_kuda_tp = line + 1;
                
                int kuda_obratno = line + 2;

                stack_push(stk_ret, kuda_obratno);

                line = line_kuda_tp;
            }
            break;

        case RET_:
            {
                line = stack_pop(stk_ret);
            }
            break;

        default: break;

    }
}

int work_with_memory (TO_MUSH_ARG)
{
    switch (operation)
    {

        case POPM_:
            {
                line++;
                int xx = str_str[line];

                push_memory[xx] = stack_pop(data);
            }
            break;

        case PUSHM_:
            {
                line++;
                int xx = str_str[line];

                stack_push(data, push_memory[xx]);
            }
            break;

        default: break;

    }
}

