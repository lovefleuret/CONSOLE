#ifndef MANAGER_H
#define MANAGER_H

#include "../ui/ui.h"
#include "../kawaii-mqtt/mqtt.h"
#include "../usr_thread/usr_gui/src/main_page.h"
#include "../usr_thread/dht11_thread/dht11_usr.h"
#include "../usr_thread/sr501_thread/sr501_usr.h"
#include "../usr_thread/at24c02_thread/at24c02_usr.h"
#include <string.h>
#include <stdio.h>
#include "debug.h"


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
void register_Console(void);


extern void register_mqtt(void);
#endif
