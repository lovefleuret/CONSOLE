#include "dht11_usr.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>



int dht11_fd= -1;
pthread_t dht11_tid;

// pthread_mutex_t dht11_mutex = PTHREAD_MUTEX_INITIALIZER;
struct dht11_data dht11_num = {
    .humidity = 0,
    .humidity_decimal = 0,
    .temperature = 0,
    .temperature_decimal = 0
};

static void dht11_init(void)
{
    dht11_fd = open("/dev/dht11", O_RDWR);
    if(dht11_fd < 0)
    {
        printf("open dht11 failed\n");
        return;
    }
    printf("open dht11 success\n");
    
}
static void* dht11_thread(void* args)
{   
    if(dht11_fd < 0)
    {
        printf("dht11_fd is invalid\n");
        pthread_exit(NULL);
    }
    
    unsigned char dht11_data[4];
    while(1)
    {
        read(dht11_fd, dht11_data, sizeof(dht11_data));
        // pthread_mutex_lock(&dht11_mutex);
        dht11_num.humidity = dht11_data[0];
        dht11_num.humidity_decimal = dht11_data[1];
        dht11_num.temperature = dht11_data[2];
        dht11_num.temperature_decimal = dht11_data[3];
        // pthread_mutex_unlock(&dht11_mutex);
        printf("humidity: %d.%d%%, temperature: %d.%dC\n", 
        dht11_num.humidity, dht11_num.humidity_decimal, dht11_num.temperature, dht11_num.temperature_decimal);

        sleep(3);
    }
    
    pthread_exit(NULL);
}

static void dht11_run(void* args)
{   
    int res = pthread_create(&dht11_tid, NULL, dht11_thread, NULL);
    if(res != 0)
    {
        printf("create dht11 thread failed\n");
        return;
    }
}
static void dht11_exit(void)
{   
    // pthread_mutex_destroy(&dht11_mutex);
    close(dht11_fd);
    pthread_join(dht11_tid, NULL);
}


Console_t dht11_route = {
	.name = "dht11_route",
	.Create = dht11_init,
	.Run = dht11_run,
	.Release = dht11_exit,
	.ptNext = NULL
};

void register_dht11(void)
{	
	dev_join(&dht11_route);
}