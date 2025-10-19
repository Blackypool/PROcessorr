#include "pechatnik_asm.h"

void ffprintff(struct GEN* ration, int* adres, FILE *fp_out)
{
    for (size_t i = 0; i < ration->char_in_file; ++i)
    {
        fprintf(fp_out, "PUSH %d\n", ration->full_txt[i]);  // -- пушим символ
        fprintf(fp_out, "PUSH %d\n", *adres);               // -- пущим его адрес 
            
        fprintf(fp_out, "POPREG AX\n");                     // -- в регистре AX хранится адрес
        fprintf(fp_out, "POPM [AX]\n");                     // -- в памяти в ячейку под номером адреса запихиваем в память ASCII символа

        fprintf(fp_out, "PUSHM [AX]\n");                    // -- достаем из памяти ячейки адреса в стек
        fprintf(fp_out, "OUT\n");
    }

    (*adres)++;
}

void open_write_all(FILE* fp_out)
{
    for (int nomer_file = 1; nomer_file <= KADROV; ++nomer_file)
    {
        struct GEN ration = {};

        number_of_file(&ration, nomer_file);

        file_pointer_read(&ration, nomer_file);
            
        int adres = 0;

        ffprintff(&ration, &adres, fp_out);

        // fprintf(“clear”);

        fprintf(fp_out, "SLEEP %f\n", PING);

        free(ration.full_txt);
    }
}

