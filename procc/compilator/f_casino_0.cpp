#include"enumchik_s.h"
#include "str_of_str.h"

#define ST_PP(data)\
        int v_1 = stack_pop(data);\
        int v_2 = stack_pop(data);

int* read_er(int &lines);

int resume_calc(struct stk* data, struct stk* better_call_saul, int &line, int* str_str, int lines_all, int* push_memory);

int* memory_crafter(int memory_not_overflow);

int main()
{
    int lines = 0;
    int* str_str = read_er(lines);
    ASSERTICHE(str_str, -1);

    int memory_not_overflow = 100;
    int* push_memory = memory_crafter(memory_not_overflow);
    ASSERTICHE(str_str, -1);

    stk stk1 {};
    ssize_t capacity = 10;
    lego_stack(&stk1, capacity);


    stk better_call_saul {};
    ssize_t capacity = 5;
    lego_stack(&better_call_saul, capacity);

    int answer = 0;
    for(int line_now = 0; line_now < lines || answer != HLT_; ++line_now)
        answer = resume_calc(&stk1, &better_call_saul, line_now, str_str, lines, push_memory);

    free(str_str);
    clear_stk(&stk1);
    clear_stk(&better_call_saul);

    return 0;
}

int* memory_crafter(int memory_not_overflow)
{
    int* memory = (int*) calloc(memory_not_overflow, sizeof(int));
    ASSERTICHE(memory, NULL);

    for(int i = 0; i < memory_not_overflow; ++i)
        memory[i] = 0;

    return memory;
}

int* read_er(int &lines)
{   
    struct stat file_info = {};

    if (stat("quadr_into_txt.txt", &file_info) != 0)  //asm_into_txt.txt    quadr_into_txt
    {
        perror("stat error");
        return NULL;
    }

    FILE *fp = fopen("quadr_into_txt.txt", "rb");   //asm_into_txt.txt  quadr_into_txt
    ASSERTICHE(fp, NULL);

    int* arraayy = (int*) calloc(file_info.st_size / 4 + 1, sizeof(int));
    ASSERTICHE(arraayy, NULL);

    lines = file_info.st_size / 4;

    size_t count = fread(arraayy, sizeof(int), file_info.st_size / 4, fp); //sizeof(int)

    // for(int i = 0; i < count; ++i)
    //     printf("line[%d] = arraayy[%d]\n", i, arraayy[i]);

    //printf("%d", int_count);

    fclose(fp);

    return arraayy;
}

int resume_calc(struct stk* data, struct stk* better_call_saul, int &line, int* str_str, int lines_all, int* push_memory)
{
    ASSERTICHE(data, HLT_);
    ASSERTICHE(better_call_saul, HLT_);
    
    int operation = str_str[line];
    switch (operation)
    {
        case PUSH_:
            {
                printf("\nfunction = {PUSH_}");
                line++;
                int value = str_str[line];
                printf("    value = {%d}\n", value);
                
                stack_push(data, value);
            }
            break;

        case POPREG_:
            {
                printf("function = {POPREG_}");
                line++;
                int xx = str_str[line]; //xx 

                int param = stack_pop(data);

                printf("    param = [%d]", param);
                printf("    PuSh_rEg[%d] = {%d}", xx, data->PuSh_rEg[xx]);

                data->PuSh_rEg[xx] = param;

                printf("    PuSh_rEg[%d] = {%d}\n", xx, data->PuSh_rEg[xx]);
            }
            break;
                    
        case PSHREG_:
            {
                printf("function = {PSHREG_}");
                line++;
                int XX = str_str[line];

                printf("    XX = {%d}     PuSh_rEg[XX] = [%d]\n", XX, data->PuSh_rEg[XX]);

                stack_push(data, data->PuSh_rEg[XX]);
            }
            break;

        case ADD_:
            {
                printf("function = {ADD_}");
                int v_1 = stack_pop(data);
                int v_2 = stack_pop(data);

                printf("    sum = [%d]\n", v_1 + v_2);

                stack_push(data, v_1 + v_2);
            }
            break;

        case SUB_:
            {
                printf("function = {SUB_}");
                int v_1 = stack_pop(data);
                int v_2 = stack_pop(data);

                stack_push(data, v_2 - v_1);
            }
            break;

        case MUL_:
            {
                printf("function = {MUL_}");

                int v_1 = stack_pop(data);
                int v_2 = stack_pop(data);

                printf("    value 1 = [%d]", v_2);
                printf("    value 2 = [%d]", v_1);
                printf("    promeg_ans = [%d]\n", v_1 * v_2);

                stack_push(data, v_1 * v_2);
            }
            break;
        
        case DIV_:
            {
                printf("function = {DIV_}");
                int v_1 = stack_pop(data);
                int v_2 = stack_pop(data);

                if (v_2 == 0)
                    perror("Go out its not matan");

                stack_push(data, v_2 / v_1);
            }
            break;
                
        case POW_:
            {
                printf("function = {POW_}");
                int v_1 = stack_pop(data);
                int v_2 = stack_pop(data);

                stack_push(data, pow(v_2, v_1));                
            }
            break;

        case OUT_:
            {
                printf("function = {OUT_}");
                int answer = stack_pop(data);

                printf(ANSI_COLOR_CYAN "\n\nANSWER = (%d)\n\n", answer);
            }
            break;

        case SQRT_:
            {
                printf("function = {SQvRT_}");
                int v_1 = stack_pop(data);

                printf("    sum = [%d]\n", sqrt(v_1));

                stack_push(data, sqrt(v_1));
            }
            break;

        case JUMP_:
            {
                printf("function = {JBB_}");
                line++;

                line = str_str[line];
                getchar();
            }
            break;

        case JBB_:
            {
                printf("function = {JBB_}");
                line++;


                int a = stack_pop(data);
                int b = stack_pop(data);

                printf("    line now = [%d]    ", line);
                
                if(b < a)
                    line = str_str[line];

                else line++;

                printf("line then = [%d]", line);
            }
            break;
            
        case JBE_:
            {
                printf("function = {JBE_}");
                line++;

                int a = stack_pop(data);
                int b = stack_pop(data);

                if(b <= a)
                    line = str_str[line];

                else line++;
            }
            break;

        case JAA_:
            {
                printf("function = {JAA_}");
                line++;

                int a = stack_pop(data);
                int b = stack_pop(data);

                if(b > a)
                    line = str_str[line];

                else line++;
            }
            break;

        case JAE_:
            {
                printf("function = {JAE_}");
                line++;

                int a = stack_pop(data);
                int b = stack_pop(data);

                if(b >= a)
                    line = str_str[line];

                else line++;
            }
            break;

        case JEE_:
            {
                printf("function = {JEE_}");
                line++;

                int a = stack_pop(data);
                int b = stack_pop(data);

                if(b == a)
                    line = str_str[line];

                else line++;
            }
            break;

        case JNE_:
            {
                printf("function = {JNE_}");
                line++;

                int a = stack_pop(data);
                int b = stack_pop(data);

                if(b != a)
                    line = str_str[line];

                else line++;
            }
            break;

        case HLT_:
            {
            printf("function = {HLT_}");
            line = lines_all;
            }
            break;
        
        case CALL_:
            {
                int line_kuda_tp = line + 1;
                
                int kuda_obratno = line + 2;

                stack_push(better_call_saul, kuda_obratno);

                line = line_kuda_tp;
            }
            break;

        case RET_:
            {
                line = stack_pop(better_call_saul);
            }
            break;

        case POPM_:
            {
                printf("function = {POPM_}");
                line++;
                int xx = str_str[line]; //xx

                push_memory[xx] = stack_pop(data);
            }
            break;

        case PUSHM_:
            {
                printf("\nfunction = {PUSHM_}");

                line++;
                int xx = str_str[line]; //xx

                stack_push(data, push_memory[xx]);
            }
            break;

    }
    return 911;
}

// #define MY_MACRO()

// MY_MACRO()

// #undef MY_MACRO

// #define ST_PP(data)\
//         int v_1 = stack_pop(data);\
//         int v_2 = stack_pop(data);



//codegen
//