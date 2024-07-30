#ifndef DEBUG_H
#define DEBUG_H

#ifdef CONFIG_DEBUG
#define DEBUG printf("------------%d-----------%s---------\n",  __LINE__, __FUNCTION__);
#else
#define DEBUG do{}while(0);
#endif


#endif //? DEBUG_H