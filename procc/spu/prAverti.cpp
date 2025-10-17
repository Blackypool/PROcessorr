#include "prAverti.h"

void pr_in_tf(struct stk* data, int num_line, const char* file_n)
{
    ssize_t schetchik = data->capacity;

    FILE *fp = fopen("OTLADCHIK.txt", "w");
    if(fp == NULL)
        perror("file not open((");
      
    while(schetchik > 0)
    {
        schetchik--;

        tip_lac shtrih = data->stack[schetchik];
        fprintf(fp, "stack[%zd] = (%d)\n", schetchik, shtrih);
    }

    fclose(fp);
}



void yadro_li_you(struct stk* data, int num_line, const char* file_n)
{
    uintptr_t adr_ptr = (uintptr_t)(data->stack);

    if ((adr_ptr < 0x1000) || (adr_ptr > 0x00007FFFFFFFFFFF))
    {
        printf(ANSI_COLOR_RED "\nNO_NO_NO Mr. fish, you go out is pamyat yadra\n" 
                "----------------------------------------\nin line %d\n----------------------------------------\nand\n----------------------------------------\nfile <%s>\n----------------------------------------\n" ANSI_COLOR_RESET, num_line - 1, file_n);

        if(data->stack != NULL)
            free(data->stack);

        data->stack = (tip_lac*) calloc(data->capacity, sizeof(int));

        if(data->stack == NULL)
            perror("Unluck - x2\n");
    }
}



void defence_of_capacity(struct stk* data, int num_line, const char* file_n)
{
    ssize_t schetchik = data->capacity;

    if(llabs(data->capacity) >= pow(2, 62))
    {
        printf("To big capacity = (%zu) brrrr\n\n----------------------------------------\nin line %d\n----------------------------------------\nand\n----------------------------------------\nfile <%s>\n----------------------------------------\n" ANSI_COLOR_RESET, data -> capacity, num_line - 1, file_n);
        schetchik = llabs(data->capacity) / 4;
        data -> capacity = schetchik;
    }


    ssize_t def_capacity = (data->capacity);

    if(data->capacity == 0)
    {
        printf(ANSI_COLOR_RED "Capacity cant be zero\nBut I can fix it\n" ANSI_COLOR_RESET);
        def_capacity = 1;
    }


        if(schetchik < 0)
    {
        printf(ANSI_COLOR_RED "\nCAPACITY STRONGER THAT YOU THINK /(modul of capasity)\\\n----------------------------------------\nin line (%d)\n----------------------------------------\nand\n----------------------------------------\nfile <%s>\n----------------------------------------\n" ANSI_COLOR_RESET, num_line - 1, file_n);

        schetchik = labs(data->capacity) +2;
        data->capacity = schetchik + 4;
    }
}


void def_size_capacity(struct stk* data, int num_line, const char* file_n)
{
    ssize_t def_capacity = (data->capacity);

    if((data->size) >= (data->capacity))
    {
        printf("size >= capacity(((");
        while((data->size) >= def_capacity)
            def_capacity = def_capacity * 2;

        tip_lac* def_stack = (tip_lac*) realloc(data->stack, def_capacity * sizeof(tip_lac) + 2);
        
        data->stack = def_stack;

        //data->stack[data->capacity + 1] = POISON;

        data->capacity = def_capacity;
        data->stack[data->capacity + 1] = 419;
    }
}



void dinamayk_def(struct stk* data, int num_line, const char* file_n)
{
    if((data->stack[0] != 23) || (data->stack[data->capacity + 1] != 7557))
        fprintf(stderr, "\nRUNRUNRUN KANAREYKA in [][][] IS REACT\n", num_line, file_n);
}

void double_kanar(struct stk* data, int num_line, const char* file_n)
{
    if((data->Kana_ != 914) || (data->_reikA != 419))
        fprintf(stderr, "\nKANAREYKA in struct IS REACT\n", num_line, file_n);
}

// void P_O_I_S_O_N(struct stk* data)
// {
//     for(int i = 1; i <= data->capacity; ++i)
//         data->stack[i] = POISON;
// }

uintptr_t hash_hash(struct stk* data)
{
    uintptr_t adr_ptr = (uintptr_t)(data->stack);

    uintptr_t znacheni_a = 0;

    ssize_t i = data->size;

    for(i; i > 0; --i)
        znacheni_a = znacheni_a + data->stack[i] * 2;

    znacheni_a = adr_ptr * 23 - (znacheni_a * data->size) + data->Kana_ - data->_reikA * 8 + i;

    return znacheni_a;
}
