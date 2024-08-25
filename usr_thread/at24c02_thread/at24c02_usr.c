#include "at24c02_usr.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>



int at24c02_fd= -1;
pthread_t at24c02_tid;

// pthread_mutex_t at24c02_mutex = PTHREAD_MUTEX_INITIALIZER;
struct at24c02_data at24c02_num = {

};

static void at24c02_init(void)
{
    at24c02_fd = open("/dev/at24c02", O_RDWR);
    if(at24c02_fd < 0)
    {
        printf("open at24c02 failed\n");
        return;
    }
    printf("open at24c02 success\n");
    
}
static void* at24c02_thread(void* args)
{   
    if(at24c02_fd < 0)
    {
        printf("at24c02_fd is invalid\n");
        pthread_exit(NULL);
    }
    int buf[2];
    // while(1)
    // {
        ioctl(at24c02_fd, IOC_AT24C02_READ, buf);
		printf("Read addr 0x%x, get data 0x%x\n", buf[0], buf[1]);
        // pthread_mutex_lock(&at24c02_mutex);
        //! 这里仅作为示例
        // pthread_mutex_unlock(&at24c02_mutex);
        ioctl(at24c02_fd, IOC_AT24C02_WRITE, buf);
        printf("Write addr 0x%x, data 0x%x\n", buf[0], buf[1]);
        // sleep(3);
    // }
    
    pthread_exit(NULL);
}

static void at24c02_run(void* args)
{   
    int res = pthread_create(&at24c02_tid, NULL, at24c02_thread, NULL);
    if(res != 0)
    {
        printf("create at24c02 thread failed\n");
        return;
    }
}
static void at24c02_exit(void)
{   
    // pthread_mutex_destroy(&at24c02_mutex);
    close(at24c02_fd);
    pthread_join(at24c02_tid, NULL);
}


Console_t at24c02_route = {
	.name = "at24c02_route",
	.Create = at24c02_init,
	.Run = at24c02_run,
	.Release = at24c02_exit,
	.ptNext = NULL
};

void register_at24c02(void)
{	
	dev_join(&at24c02_route);
}