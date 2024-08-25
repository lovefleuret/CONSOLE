#ifndef SR501_USR_H
#define SR501_USR_H

#include "manager.h"
#include <pthread.h>

struct sr501_data{
    
};
typedef struct led_class{
    int led_fd;
    int led_status;
}led_class_t;
void register_sr501(void);

#endif /* SR501_USR_H */
