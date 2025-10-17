#include "enumchik_s.h"
#include "type_of_opera.h"

#define NAME_FILE "quadr_into_txt.txt"

void nahui_is_compilatora(int *hranilische, size_t number_of);


int main()
{
    int count_operation = 0;
    int lines_num = 0;

    int* black_metka = find_treasure(NUM_label_ss);
    ASSERTICHE(black_metka, 0);

    char ** str_str = glue_of_functio(count_operation, lines_num);
    ASSERTICHE(str_str, 0);

    int* hranilische = what_the_operation(str_str, lines_num, black_metka);
    ASSERTICHE(hranilische, 0);

    hranilische = what_the_operation(str_str, lines_num, black_metka);

    nahui_is_compilatora(hranilische, count_operation);

    free(hranilische);
    free(str_str);
    free(black_metka);

    return 0;
}

void nahui_is_compilatora(int *hranilische, size_t number_of)
{
    ASSERTICHE(hranilische, perror("no way home"));
    
    FILE *fp = fopen(FILE_for_SPU , "wb");
    ASSERTICHE(fp, )

    fwrite(hranilische, number_of, sizeof(int), fp);
      
    // for(int i = 0; i < number_of; i++)
    //     fprintf(fp, "%d\n", hranilische[i]);

    fclose(fp);
}
