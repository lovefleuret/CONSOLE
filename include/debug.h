#ifndef DEBUG_H
#define DEBUG_H

#ifdef CONFIG_DEBUG
#define DEBUG printf("-------\x1b[33m-----------------%s--------------------------------%s-------%d---\x1b[0m----\n", __FILE__, __func__, __LINE__);
#else
#define DEBUG do{}while(0);
#endif


#endif //? DEBUG_H