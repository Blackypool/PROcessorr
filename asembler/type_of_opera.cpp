#include "type_of_opera.h"

static const struct operatio oper[] = {

      {"ADD",  CMD_ADD_,  3, 0},  //0   //CMD_
       {"SUB",  CMD_SUB_,  3, 0},  //1  auto_ считать длину в струтуру длину строки в структуре последним элементом
        {"MUL",  CMD_MUL_,  3, 0},  //2
         {"DIV",  CMD_DIV_,  3, 0},  //3
          {"POW",  CMD_POW_,  3, 0},  //4
           {"SQRT", CMD_SQRT_, 4, 0},  //5
                                {"PUSH", CMD_PUSH_, 4, 1},  //6
                                 {"OUT",  CMD_OUT_,  3, 0},  //7
                                  {"HLT",  CMD_HLT_,  3, 0},  //8
           {"POPREG", CMD_POPREG_, 6, 1},  //9
            {"PUSHREG", CMD_PSHREG_, 6, 1},  //10
                                     {"JMP", CMD_JMP_, 3, 1},   //11
                                      {"JBE", CMD_JBE_, 3, 1},   //12
                                       {"JB",  CMD_JB_,  2, 1},   //13
                                        {"JAE", CMD_JAE_, 3, 1},   //14
                                         {"JA",  CMD_JA_,  2, 1},   //15
                                          {"JNE", CMD_JNE_, 3, 1},   //16
                                           {"JE",  CMD_JE_,  2, 1},   //17
                        {"RET",  CMD_RET_, 3, 0},  //18
                         {"CALL", CMD_CALL_, 4, 1}, //19
                                              {"POPM",  CMD_POPM_, 4, 1},//20
                                               {"PUSHM", CMD_PUSHM_, 5, 1},//21
                            {"INT",  CMD_INT_,  3, 0}, //22
                             {"SLEEP",CMD_SLEP_, 5, 1}, //23
                              {"DRAW", CMD_DRAW_, 4, 0}  //24
                    
                                       };

int* what_the_operation(char** str_str, int lines, int *black_metka)
{
    ASSERTICHE(str_str, NULL);

    int *hranilische = (int*) calloc((size_t)(lines) * 2, sizeof(int));
    ASSERTICHE(hranilische, NULL);

    int Kana = 7;

    int oper_find = 0;
    int sche = 0; 
    for(int lin = 0; lin < lines; ++lin)
    {
        //чек лэйбэл
        label_you_li(str_str, black_metka, &lin);

        oper_find = choose_operatia(str_str, &lin);
        ASSCANFOR_ASM(oper_find, lin);
        
        hranilische[sche] = oper[oper_find].maska;
        
        DEBUG;

        if ((oper[oper_find].need_param) == 1)
        {
            ++sche;
            hranilische[sche] = need_param(str_str, lin, black_metka, oper_find, &Kana);
            ASSCANFOR_ASM(Kana, lin);
        }

        //DEBUG;

        ++sche;
    }
        
    return hranilische;    
}

int choose_operatia(char** str_str, int *lin)
{
    int number_of_operation = sizeof(oper) / sizeof(oper[0]);

    for(int i = 0; i < number_of_operation; ++i)
        if (strncmp(str_str[*lin], oper[i].opera, oper[i].len_len) == 0)
            return i;
    
    return 0;
}

int need_param(char** str_str, int lin, int *black_metka, int oper_find, int *kanareyka)
{   // указательный параметр

    int valli = 0;
    if (sscanf(str_str[lin] + oper[oper_find].len_len, " :%d" , &valli) > 0)
        return black_metka[valli];

    if (sscanf(str_str[lin] + oper[oper_find].len_len, " %d" , &valli) > 0)
        return valli;

    char command[2] = {};
    if (sscanf(str_str[lin] + oper[oper_find].len_len, " [%1cX]%n", command, &valli) == 2)     /////%n
        return command[0] - 'A';
                
    if(sscanf(str_str[lin] + oper[oper_find].len_len, " %1cX%n", command, &valli) > 0)//;,lmknj
        return command[0] - 'A';
    
    *kanareyka = -1;
    return -666;
}

void find_treasure(struct ASM* a_s_m)
{
    int *metka_s = (int*) calloc(NUM_label_ss, sizeof(int));
    ASSERTICHE(metka_s, perror("label not found"));

    for(int i = 0; i < NUM_label_ss; ++i)
        metka_s[i] = -1;

    a_s_m->black_metka = metka_s;
}

void label_you_li(char** str_str, int* black_metka, int *lin)
{
    int def = 0;         //   отдельная функция
    if (sscanf(str_str[*lin], ":%d", &def) > 0)
    {
        (*lin)++;
        black_metka[def] = *lin;
    }
}
