#include "sr501_usr.h"
#include "debug.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>



int sr501_fd= -1;
pthread_t sr501_tid;

// pthread_mutex_t sr501_mutex = PTHREAD_MUTEX_INITIALIZER;
struct sr501_data sr501_num = {
    
};
led_class_t led = {
    .led_fd = -1,
    .led_status = -1
};


static void sr501_init(void)
{
    sr501_fd = open("/dev/sr501", O_RDWR);
    if(sr501_fd < 0)
    {
        printf("open wwj_sr501 failed\n");
        return;
    }
    printf("open wwj_sr501 success\n");
    led.led_fd = open("/dev/led", O_RDWR);
    if(led.led_fd < 0)
    {
        printf("open led failed\n");
        return;
    }
}
static void* sr501_thread(void* args)
{   
    DEBUG
    if(sr501_fd < 0)
    {
        printf("sr501_fd is invalid\n");
        pthread_exit(NULL);
    }
    int val;

    while(1)
    {
        read(sr501_fd, &val, sizeof(val));
        // pthread_mutex_lock(&sr501_mutex);
        // pthread_mutex_unlock(&sr501_mutex);
        if (read(sr501_fd, &val, 4) == 4)
        {
            printf("get button: 0x%x\n", val);
            
            if(led.led_fd < 0)
            {
                printf("open led failed\n");
                return NULL;
            }
            led.led_status = 1;
            write(led.led_fd, &led.led_status, 1);

        }else
        {
            printf("get button: -1\n");
            led.led_status = 0;
            write(led.led_fd, &led.led_status, 1);
        }
			

        sleep(2);
    }
    
    pthread_exit(NULL);
}

static void sr501_run(void* args)
{   
    int res = pthread_create(&sr501_tid, NULL, sr501_thread, NULL);
    if(res != 0)
    {
        printf("create sr501 thread failed\n");
        return;
    }
}
static void sr501_exit(void)
{   
    // pthread_mutex_destroy(&sr501_mutex);
    close(sr501_fd);
    close(led.led_fd);
    pthread_join(sr501_tid, NULL);
}


Console_t sr501_route = {
	.name = "sr501_route",
	.Create = sr501_init,
	.Run = sr501_run,
	.Release = sr501_exit,
	.ptNext = NULL
};

void register_sr501(void)
{	
	dev_join(&sr501_route);
}