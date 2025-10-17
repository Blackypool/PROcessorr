#include "type_of_opera.h"

static const struct operatio oper[] = {

      {"ADD",  ADD_, 3, 0},  //0
       {"SUB",  SUB_, 3, 0},  //1
        {"MUL",  MUL_, 3, 0},  //2
         {"DIV",  DIV_, 3, 0},  //3
          {"POW",  POW_, 3, 0},  //4
           {"SQRT", SQRT_, 4, 0}, //5
                                {"PUSH", PUSH_, 4, 1},  //6
                                 {"OUT",  OUT_,  3, 0},  //7
                                  {"HLT",  HLT_,  3, 0},  //8
           {"POPREG", POPREG_, 6, 1},  //9
            {"PSHREG", PSHREG_, 6, 1},  //10
                                     {"JMP", JMP_, 4, 1},   //11
                                      {"JB",  JB_,  3, 1},   //12
                                       {"JBE", JBE_, 3, 1},   //13
                                        {"JA",  JA_,  3, 1},   //14
                                         {"JAE", JAE_, 3, 1},   //15
                                          {"JE",  JE_,  3, 1},   //16
                                           {"JNE", JNE_, 3, 1},   //17
                        {"RET",  RET_, 3, 0},  //18
                         {"CALL", CALL_, 4, 1}, //19
                                              {"POPM",  POPM_, 4, 1},//20
                                               {"PUSHM", PUSHM_, 5, 1},//21
                    
                                       };

int* what_the_operation(char** str_str, int lines, int *black_metka)
{
    ASSERTICHE(str_str, NULL);

    int *hranilische = (int*) calloc((size_t)(lines) * 2, sizeof(int));
    ASSERTICHE(hranilische, NULL);

    int oper_find = 0;
    int sche = 0; 
    for(int lin = 0; lin < lines; ++lin)
    {
        oper_find = choose_operatia(str_str, &lin, black_metka);
        ASSCANF(oper_find);

        hranilische[sche] = oper_find;

        if (oper[hranilische[sche]].need_param == 1)
        {
            ++sche;
            hranilische[sche] = need_param(str_str, lin, black_metka, oper_find);
            ASSCANF(hranilische[sche]);
        }

        ++sche;
    }

    return hranilische;    
}

int choose_operatia(char** str_str, int *lin, int *black_metka)
{
    int number_of_operation = sizeof(oper) / sizeof(oper[0]);

    if (str_str[*lin][0] == ':')
    {
        int def = 0;
        int ret = sscanf(str_str[*lin] + 1, " %d ", &def);
        ASSCANF(ret);

        *lin++;
        black_metka[def] = *lin;
    }

    for(int i = 0; i < number_of_operation; ++i)
            if (strncmp(str_str[*lin], oper[i].opera, oper[i].len_len) == 0)
                return i;
    
    return -1;
}

int need_param(char** str_str, int lin, int *black_metka, int oper_find)
{
    int valli = 0;
    if (sscanf(str_str[lin] + oper[oper_find].len_len, " :%d " , &valli) > 0)
        return black_metka[valli];

    else 
        if (sscanf(str_str[lin] + oper[oper_find].len_len, " %d " , &valli) > 0)
            return valli;

        else 
            {
                char command[2] = {};
                if (sscanf(str_str[lin] + oper[oper_find].len_len, "[%1c", command) > 0)
                    return command[0] - 'A';
                
                else 
                    if(sscanf(str_str[lin] + oper[oper_find].len_len, " %1c ", command) > 0)
                        return command[0] - 'A';
            }
    
    return -1;
}

int* find_treasure(int number_of_metok)
{
    int *black_metka = (int*) calloc(number_of_metok, sizeof(int));
    ASSERTICHE(black_metka, NULL);
    
    return black_metka;
}
