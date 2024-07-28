#ifndef MANAGER_H
#define MANAGER_H

#include <string.h>
#include "../ui/ui.h"
#include "../kawaii-mqtt/mqtt.h"


typedef struct Console {
	char *name;
	void (*Create)(void);
	void (*Run)(void *pParams);
	void (*Release)(void);

	struct Console *ptNext;
}Console_t;

Console_t* dev_join(Console_t *ptConsole);
Console_t* dev_probe(char *name);
void ConsoleSysInit(void);
void ConsoleSysRun(void);
void ConsoleRelease(void);



extern void register_mqtt(void);
#endif
