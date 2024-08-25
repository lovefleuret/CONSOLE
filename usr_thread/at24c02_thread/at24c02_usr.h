
#ifndef AT24C02_USR_H
#define AT24C02_USR_H

#include "manager.h"
#include <pthread.h>
#include <sys/ioctl.h>

#define IOC_AT24C02_WRITE 101
#define IOC_AT24C02_READ  100
struct at24c02_data{
    
};
void register_at24c02(void);

#endif /* AT24C02_USR_H */



