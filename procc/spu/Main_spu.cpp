#include "str_of_str.h"
#include "enumchik_s.h"
#include "switch_func.h"

int* read_er(int *lines);

void memory_crafter(SPU* spu);

int resume_calc(TO_MUSH_ARG);


int main()
{
    struct SPU spu = {};
    int lines = 0;

    int* str_str = read_er(&lines);
    ASSERTICHE(str_str, 0);

    memory_crafter(&spu);

    lego_stack(&spu.start_stk, STK_capacity);
    lego_stack(&spu.stk_ret, RET_capacity);


    ans_typ answer = 0;
    for(int line_now = 0; line_now < lines && answer != HLT_ && answer != ER_R_OR; ++line_now)
        answer = resume_calc(&spu.start_stk, &spu.stk_ret, line_now, str_str, lines, spu.ram, 0);

    if(answer == ER_R_OR)
        printf("\n911 errorr\n");
    
    free(spu.ram);
    free(str_str);
    
    clear_stk(&spu.start_stk);
    clear_stk(&spu.stk_ret);

    return 0;
}

void memory_crafter(SPU* spu)
{
    int* Ram = (int*) calloc(OPE_rativ_ka, sizeof(int));
    ASSERTICHE(Ram, perror("memory_crafter ruined"));

    spu->ram = Ram;
}

int* read_er(int *lines)
{   
    struct stat file_info = {};

    if (stat(FILE_for_SPU, &file_info) != 0)
    {
        perror("stat error");
        return NULL;
    }

    FILE *fp = fopen(FILE_for_SPU, "rb");
    ASSERTICHE(fp, NULL);

    int* arraayy = (int*) calloc(file_info.st_size / sizeof(int) + 1, sizeof(int));
    ASSERTICHE(arraayy, NULL);

    *lines = file_info.st_size / sizeof(int);

    size_t count = fread(arraayy, sizeof(int), *lines, fp);

    fclose(fp);

    return arraayy;
}

int resume_calc(TO_MUSH_ARG)
{
    ASSERTICHE(data, HLT_);
    ASSERTICHE(stk_ret, HLT_);

    FOR_SW(line);

    LOGIC(_CALC_,  calcc_func);

    LOGIC(_BASE_,  steck_fucn);

    LOGIC(_REG_,   registors);

    LOGIC(_GAMMY_, jump_mishki_gammy);

    LOGIC(_FUNCN_, for_functions);

    LOGIC(_MEMOR_, work_with_memory);
    
    return ER_R_OR;
}
