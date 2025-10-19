#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define ZERO "z_1.txt"

#define ASSCANF(param, retern) \
        if((param) <= 0) { \
            fprintf(stderr, "\nparam ruined in line {%d}\nfile {%s}\n", __LINE__, __FILE__, strerror(errno)); \
            return  retern; \
        }


#define ASSERTICHE(ptr, ret) \
        if((ptr) == NULL) {   \
            fprintf(stderr, "\nassert react in line {%d}\nfile {%s}\n", __LINE__, __FILE__, strerror(errno)); \
            return ret; \
        }


struct GEN
{
    size_t char_in_file = 0;
    char* full_txt = 0;
};

void number_of_file(struct GEN* ration);

void file_pointer_read(struct GEN* ration);


int main()
{
    struct GEN ration = {};

    number_of_file(&ration);

    file_pointer_read(&ration);

    FILE *fp_out = fopen("asm.asm", "w");

    int adres = 0;

    for (int i = 0; i < ration.char_in_file; ++i)
    {
        fprintf(fp_out, "PUSH %d\n", ration.full_txt[i]);  // -- пушим символ
        fprintf(fp_out, "PUSH %d\n", adres);               // -- пущим его адрес 

        fprintf(fp_out, "POPREG AX\n");                    // -- в регистре AX хранится адрес
        fprintf(fp_out, "POPM [AX]\n");                    // -- в памяти в ячейку под номером адреса запихиваем в память ASCII символа

        fprintf(fp_out, "PUSHM [AX]\n");                   // -- достаем из памяти ячейки адреса в стек
        fprintf(fp_out, "OUT\n");

        adres++;
    }

    fprintf(fp_out, "HLT\n");

    free(ration.full_txt);
    fclose(fp_out);

    return 0;
}


void number_of_file(struct GEN* ration)
{
    struct stat file_info = {};

    if (stat(ZERO, &file_info) != 0)
        perror("stat error");

    ration->char_in_file = (size_t)file_info.st_size;
}

void file_pointer_read(struct GEN* ration)
{
    FILE *fp = fopen(ZERO, "r");
    ASSERTICHE(fp, perror("file not open"));

    char *ptr = (char*) calloc((ration->char_in_file + 2), sizeof(char));
    ASSERTICHE(ptr, perror("calloc ruined"));

    size_t count = fread(ptr, sizeof(char), ration->char_in_file, fp);  //читать не в птр а сразу в ратион - фул-тхт
    ASSCANF(count, perror("fread with coubt failed"));

    ration->full_txt = ptr;

    fclose (fp);
}

    // PUSH %d -- пушим символ
    // PUSH %d -- пущим его адрес 
    // POPREG AX -- в регистре AX хранится адрес
    // POPM [AX] -- в памяти в ячейку под номером адреса запихиваем в память ASCII символа

    // PUSHM [AX] -- достаем из памяти ячейки адреса в стек
    // OUT 