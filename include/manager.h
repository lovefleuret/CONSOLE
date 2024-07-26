#ifndef MANAGER_H
#define MANAGER_H



typedef struct Console {
	char *name;
	void (*Run)(void *pParams);
	void (*Create)(void);
	struct Console *ptNext;
}Console_t, *Console_t;




#endif
