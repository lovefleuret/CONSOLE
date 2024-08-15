#ifndef DHT11_USR_H
#define DHT11_USR_H

#include "manager.h"
#include <pthread.h>

struct dht11_data{
    int temperature;
    int temperature_decimal;
    int humidity;
    int humidity_decimal;
};
void register_dht11(void);

#endif /* DHT11_USR_H */
