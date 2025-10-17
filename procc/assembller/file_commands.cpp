#include "file_commands.h"

char** glue_of_functio(int& count_operation, int& lines_num)
{
    size_t number_char_in_file = number_of_file();

    char *full_asm = file_pointer_read();
    ASSERTICHE(full_asm, NULL);
    
    lines_num = number_of_lens(full_asm);

    char ** str_str = v_str_ku(full_asm, lines_num, number_char_in_file, count_operation);
    ASSERTICHE(str_str, NULL);

    free(full_asm);

    return str_str; //добавить в массив строк строки с atoi параметрами файла
}

size_t number_of_file()
{
    struct stat file_info = {};

    if (stat(FILE_for_ASM, &file_info) != 0)
    {
        perror("stat error");
        return 1;
    }

    return (size_t)file_info.st_size;
}

char* file_pointer_read()
{
    size_t number_char = number_of_file();

    FILE *fp = fopen(FILE_for_ASM, "rb");
    ASSERTICHE(fp, NULL);

    char *ptr = (char*) calloc((size_t)(number_char + 2), sizeof(char));
    if (ptr == NULL)
    {
        perror("Dinamics error");
        return NULL;
    }

    size_t count = fread(ptr, sizeof(char), number_char, fp );

    fclose (fp);

    return ptr;
}

int number_of_lens(char* ptr)
{
    ASSERTICHE(ptr, -1);

    int lines_num = 0;

    for(int i = 0; ptr[i] != '\0'; ++i)
    {
        if(ptr[i] == '\n')
            ++lines_num;
    }

    return lines_num + 1;
}
