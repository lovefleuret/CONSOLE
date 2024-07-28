

#include "include/manager.h"
#include "ui/ui.h"


int main(int args, char** argv, char** env)
{   

    ConsoleSysInit();

    ConsoleSysRun();

    ConsoleRelease();

    while(1)
    {   
        lv_task_handler();
        
        usleep(5000);
    }
    return 0;
}