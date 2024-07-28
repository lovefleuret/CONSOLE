


#include "ledtest.h"
#include "lv_event.h"
#include "lvgl/src/lv_api_map.h"
#include "manager.h"
/*
 * ./ledtest /dev/100ask_led0 on
 * ./ledtest /dev/100ask_led0 off
 */

int fd;
char status;
lv_obj_t* led_page = NULL;
lv_obj_t* led_button = NULL;
lv_obj_t* led_label = NULL;
int led_open(char* file)
{
	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		printf("can not open file %s\n", file);
		return -1;
	}
	return fd;
}

void led_on(int fd)
{	
	status = 1;
	write(fd, &status, 1);
}


void led_off(int fd)
{	
	status = 0;
	write(fd, &status, 0);

}

void led_close(int fd)
{
	close(fd);
}

int res2;
pthread_t thread2;
void ledtest_exit(void)
{
	pthread_join(thread2, NULL);
}

void* ledtest_thread(void* args)
{
	while(1)
	{
		lv_task_handler();
		usleep(5000);
	}
	pthread_exit(NULL);
}


void led_run(void* p)
{
	res2 = pthread_create(&thread2, NULL, ledtest_thread, NULL);
	if(res2 != 0) {
		printf("create ledtest thread fail");
		exit(res2);
	}
}

static void led_button_event_cb(lv_event_t * e)
{   
    if(e->code == LV_EVENT_RELEASED) {
	DEBUG

        printf("LED Button Clicked\n");
        static bool led_state = false;
        led_state = !led_state;
        if(led_state) {
            lv_label_set_text(led_label, "LED Control\nLED ON");
            led_on(fd);
        } else {
            lv_label_set_text(led_label, "LED Control\nLED OFF");
            led_off(fd);
        }
        
    }
}
void ledtest_create(void)
{
	led_page = lv_obj_create(lv_scr_act());
    lv_obj_set_size(led_page, 1024, 600);
    
    led_button = lv_btn_create(led_page);
    lv_obj_set_size(led_button, 300, 50);
    


    lv_obj_center(led_button);

    led_label = lv_label_create(led_button);
    lv_label_set_text(led_label, "LED Control\n");

	fd = led_open("/dev/100ask_led0");
    lv_obj_add_event_cb(led_button, led_button_event_cb, LV_EVENT_ALL, NULL);

}


Console_t lv_test = {
	.name = "ledtest",
	.Create = ledtest_create,
	.Run = led_run,
	.Release = ledtest_exit,
	.ptNext = NULL
};

void register_test(void)
{	
	dev_join(&lv_test);
}