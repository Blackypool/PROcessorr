#include "enumchik_s.h"
#include "str_of_str.h"

int* what_the_operation(char** str_str, int lines, int *black_metka, struct stk* data);

char* file_pointer_read();

size_t number_of_file();

int number_of_lens(char* ptr);

void nahui_is_compilatora(int *hranilische, size_t number_of);


int main()
{
    int number_of_metok = 6;
    int *black_metka = (int*) calloc(number_of_metok, sizeof(int));
    ASSERTICHE(black_metka);

    for(int i = 0; i < number_of_metok; ++i)
        black_metka[i] = 0;


    size_t number_char_in_file = number_of_file();

    char *full_asm = file_pointer_read();   //весь файл в массиве
    ASSERTICHE(full_asm);
    
    int lines_num = number_of_lens(full_asm);   //количество строк
    int count_operation = 0;
    //int count = counteresses(); //количество чисел в файле

    char ** str_str = v_str_ku(full_asm, lines_num, number_char_in_file, count_operation);  //массив строк
    ASSERTICHE(str_str);


    
    int* hranilische = what_the_operation(str_str, lines_num, black_metka, &retyrn);
    ASSERTICHE(hranilische);

    free(hranilische);
    hranilische = what_the_operation(str_str, lines_num, black_metka, &retyrn);

    nahui_is_compilatora(hranilische, count_operation);

    free(full_asm);
    free(hranilische);
    free(str_str);
    free(black_metka);

    clear_stk(&retyrn);

    return 0;
}

int* what_the_operation(char** str_str, int lines, int *black_metka, struct stk* data)
{
    ASSERTICHE(str_str);

    int *hranilische = (int*) calloc((size_t)(lines) * 2, sizeof(int));
    ASSERTICHE(hranilische);

    struct operatio oper[] = {

      {"ADD",  0x00000000, 3, 0},  //1
       {"SUB",  0x00000001, 3},  //2
        {"MUL",  0x00000002, 3},  //3
         {"DIV",  0x00000003, 3},  //4
          {"POW",  0x00000004, 3},  //5
           {"SQRT", 0x00000005, 4},  //6
                                {"PUSH", 0x00000006, 4, 1//HAVEARG//},  //7
                                 {"OUT",  0x00000007, 3},  //8
                                  {"HLT",  0x00000008, 3},  //9
      {"POPREG", 0x00000009, 6},  //10
       {"PSHREG", 0x0000000A, 6},  //11
                              {"JUMP", 0x0000000B, 4},  //12
                               {"JBB",  0x0000000C, 3},  //13
                                {"JBE",  0x0000000D, 3},  //14
                                 {"JAA",  0x0000000E, 3},  //15
                                  {"JAE",  0x0000000F, 3},  //16
                                   {"JEE",  0x00000010, 3},  //17
                                    {"JNE",  0x00000011, 3},  //18
      {"RET", 0x00000012, 3},  //19
       {"CALL", 0x00000013, 4}  //20
                    
                             };

    int number_of_operation = sizeof(oper) / sizeof(oper[0]);


    int sche = 0; 
    for(int lin = 0; lin < lines; ++lin)
    {
        for(int i = 0; i < number_of_operation; ++i)
        {
            
            if (strncmp(str_str[lin], oper[i].opera, oper[i].len_len) == 0)
            {
                // if(i == CALL_)
                //     {
                //         записываем в байткод колл и достаем из метки номер нужной строки

                //         int defin = 0;
                //         int retu = sscanf(str_str[lin] + 2, ": %d ", defin);
                //         ASSCANF(retu);

                //         stack_push(data, black_metka[defin]);   //black_metka[defin] = 0;
                // //     }

                // if(i == RET_)
                // {
                //     hranilische[sche] = JUMP_;
                //     ++sche;
                //     hranilische[sche] = stack_pop(data);
                // }

                if (USLOVIE(i) || CALL_)
                {
                    ++sche;
                    if(strchr(str_str[lin], ':') != NULL)
                    {
                        int valli = 0;
                        int r = sscanf(str_str[lin] + oper[i].len_len + 2, " %d " , valli);
                        hranilische[sche] = black_metka[valli];
                        ASSCANF(r);
                    }

                    else 
                        {
                            int re = sscanf(str_str[lin] + oper[i].len_len, " %d " , &hranilische[sche]);
                            ASSCANF(re);
                        }   //?? проверк //+strlen(str_str[lin] - 2)

                }


                if(i == PSHREG_ || i == POPREG_)
                {
                    char command[2] = {};
                    sscanf(str_str[lin] + oper[i].len_len, " %c", command);
                    ++sche;

                    hranilische[sche] = command[0] - 'A';
                }

                break;
            }

            else if (str_str[lin][0] == ':') //find :
                    {
                        int def = 0;
                        int ret = sscanf(str_str[lin] + 1, " %d ", def);
                        ASSCANF(ret);

                        black_metka[def] = lin;
                    }
        }

        ++sche;
    }

    return hranilische;
}

size_t number_of_file()
{
    struct stat file_info = {};

    if (stat("quadratic.asm", &file_info) != 0)   //asm.asm
    {
        perror("stat error");
        return 1;
    }

    return (size_t)file_info.st_size;
}

char* file_pointer_read()
{
    size_t number_char = number_of_file();

    FILE *fp = fopen("quadratic.asm", "rb");    //asm.asm
    ASSERTICHE(fp);

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

void nahui_is_compilatora(int *hranilische, size_t number_of)
{
    if(hranilische == NULL)
        perror("nah bad");
    
    FILE *fp = fopen("quadr_into_txt.txt", "wb");     //asm_into_txt
    if(fp == NULL)
        perror("file nah bad"); //return

    fwrite(hranilische, number_of, sizeof(int), fp);
      
    // for(int i = 0; i < number_of; i++)
    //     fprintf(fp, "%d\n", hranilische[i]);

    fclose(fp);
}

int number_of_lens(char* ptr)
{
    ASSERTICHE(ptr);

    int lines_num = 0;

    for(int i = 0; ptr[i] != '\0'; ++i)
    {
        if(ptr[i] == '\n')
            ++lines_num;
    }

    return lines_num + 1;
}
