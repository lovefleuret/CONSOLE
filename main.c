

#include "include/manager.h"


Console_t* H_Conslole = NULL;


Console_t* dev_join(Console_t *ptConsole)
{   

    if(H_Conslole == NULL)
    {
        H_Conslole = ptConsole;
        return H_Conslole;
    }
    
    ptConsole->ptNext = H_Conslole;
    H_Conslole = ptConsole;


    return H_Conslole;

}


Console_t* dev_probe(char *name)
{
	Console_t* ptTmp = H_Conslole;
	while (ptTmp)
	{
		if (strcmp(name, ptTmp->name) == 0)
        {
            return ptTmp;
        }

		ptTmp = ptTmp->ptNext;
	}

	return NULL;
}


void ConsoleSysInit(void)
{   

    Console_t* ptTmp = H_Conslole;
    
    while(ptTmp)
    {
        if(ptTmp->Create)
            ptTmp->Create();
        ptTmp = ptTmp->ptNext;
    }
    return;
}

void ConsoleSysRun(void)
{   
    Console_t* ptTmp = H_Conslole;
    if(ptTmp == NULL)
        return;

    while(ptTmp)
    {
        if(ptTmp->Run)
            ptTmp->Run(NULL);
        ptTmp = ptTmp->ptNext;
    }

    return;
}

void ConsoleRelease(void)
{
    Console_t* ptTmp = H_Conslole;
    if(ptTmp == NULL)
        return;

    while (ptTmp)
    {
        if(ptTmp->Release)
            ptTmp->Release();
        
        ptTmp = ptTmp->ptNext;
    }

    return;
}

void register_Console(void)
{
    register_mqtt();
    register_test();
    register_test2();

}

static void* lvgl_thread(void* args)
{
    while(1)
    {
        lv_task_handler();
        usleep(5000);
    }
}

int main(int args, char** argv, char** env)
{   

    LVGL_init();

   
    
    register_Console();

    ConsoleSysInit();

    ConsoleSysRun();
   


    ConsoleRelease();
   
    pthread_t lvgl;
    int res_t = pthread_create(&lvgl, NULL, lvgl_thread, NULL);
    if(res_t != 0)
    {
        printf("create lvgl thread fail\n");
        exit(res_t);
    }

    return 0;
}