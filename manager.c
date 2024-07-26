
#include "include/ui.h"
struct Console_t 
void ConsoleSysInit(void)
{
    LVGL_init();

}

void ConsoleSysRun(void)
{
    
}

void ConsoleRelease(void)
{
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}