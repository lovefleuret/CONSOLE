
#include "include/manager.h"


Console_t* H_Conslole = NULL;


static Console_t* dev_join(Console_t *ptConsole)
{
    ptConsole->Create();

    ptConsole->ptNext = H_Conslole->ptNext;
    H_Conslole = ptConsole;


    return H_Conslole;

}


static Console_t* dev_probe(char *name)
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
    LVGL_init();

    Console_t* ptTmp = H_Conslole;
    Console_t* ptNext = NULL;
    while(ptTmp)
    {
        ptNext = ptTmp->ptNext;
        ptTmp->Create();
        ptTmp = ptNext;
    }
    return;
}

void ConsoleSysRun(void)
{   
    Console_t* ptTmp = H_Conslole;
    Console_t* ptNext = NULL;
    while(ptTmp)
    {
        ptNext = ptTmp->ptNext;
        ptTmp->Run(NULL);
        ptTmp = ptNext;
    }

    return;
}

void ConsoleRelease(void)
{
    Console_t* ptTmp = H_Conslole;
    Console_t* ptNext = NULL;

    while (ptTmp)
    {
        ptNext = ptTmp->ptNext;
        ptTmp->Release();
        ptTmp = ptNext;
    }

    return;
}
