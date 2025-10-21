#include"music.h"

#ifndef COD_GEN
#define COD_GEN

int main() 
{
    system("open -n -a Terminal");
    
    sleep(2);
    send_to_terminal("cd ~/Desktop/прога/procc/codegen");
    send_to_terminal("make");
    send_to_terminal("./a.out");
    
    return 0;
}

#endif


#ifndef ASM_BIN
#define ASM_BIN

int main() 
{
    system("open -n -a Terminal");
    
    sleep(2);
    send_to_terminal("cd ~/Desktop/прога/procc/codegen");
    send_to_terminal("make");
    send_to_terminal("./a.out");
    
    return 0;
}

#endif


#ifndef SPU_SPU
#define SPU_SPU

int main() 
{
    pid_t pid = fork();

    if(pid == 0)
    {
        system("open -n -a Terminal");
        
        sleep(2);
        send_to_terminal("cd ~/Desktop/прога/procc/spu");
        send_to_terminal("make");
        send_to_terminal("./a.out");
    }
        
    else system("afplay Hitsujibungaku.mp3");

    return 0;
}

#endif