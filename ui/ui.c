#include <sys/select.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include "led/ledtest.h"
#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"

// #include "lvgl/demos/lv_demos.h"
#include "lvgl/examples/widgets/lv_example_widgets.h"
#include "lvgl/src/core/lv_event.h"
#include "lvgl/src/core/lv_obj_pos.h"



#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <pthread.h>

#include "mqtt_config.h"
#include "mqtt_log.h"
#include "mqttclient.h"




#define DISP_BUF_SIZE (1024 * 600)


#include <stdio.h>


#include "led.h"
lv_obj_t* led_page = NULL;
lv_obj_t* led_button = NULL;
lv_obj_t* led_label = NULL;

int fd = 0;
static void led_button_event_cb(lv_event_t * e)
{   
    if(e->code == LV_EVENT_RELEASED) {
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

    // led_close(fd);
}

void led_test()
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





static void topic1_handler(void* client, message_data_t* msg)
{
    (void) client;
    MQTT_LOG_I("-----------------------------------------------------------------------------------");
    MQTT_LOG_I("%s:%d %s()...\ntopic: %s\nmessage:%s", __FILE__, __LINE__, __FUNCTION__, msg->topic_name, (char*)msg->message->payload);
    MQTT_LOG_I("-----------------------------------------------------------------------------------");
    
    int name_ret = strcmp(msg->topic_name, "topic1");
    int message_ret = strcmp((char*)msg->message->payload, "led on");
    int message_ret1 = strcmp((char*)msg->message->payload, "led off");
    if(name_ret == 0 && message_ret == 0){
        if(fd){
            fd = led_open("/dev/100ask_led0");
        }
        led_on(fd);
    }
    if(name_ret == 0 && message_ret1 == 0){
        if(fd){
            fd = led_open("/dev/100ask_led0");
        }
        led_off(fd);
    }
}

void *mqtt_publish_thread(void *arg)
{
    mqtt_client_t *client = (mqtt_client_t *)arg;
	int cnt = 0;

    char buf[100] = { 0 };
    mqtt_message_t msg;
    memset(&msg, 0, sizeof(msg));
    sprintf(buf, "welcome to mqttclient, this is a publish test...");

    sleep(2);

    mqtt_list_subscribe_topic(client);

    msg.payload = (void *) buf;
    
    while(1) {
        //sprintf(buf, "welcome to mqttclient, this is a publish test, a rand number: %d ...", random_number());
        sprintf(buf, "arm-linux, %d", cnt++);

        msg.qos = 0;
        mqtt_publish(client, "arm-linux", &msg);

        sleep(5);
    }

    pthread_exit(NULL);
}


void *lvgl_thread(void *arg)
{   

    led_test();

    while(1)
    {   
        lv_task_handler();
        
        usleep(5000);
    }
    pthread_exit(NULL);

}

int LVGL_init(void)
{
    /*LittlevGL init*/
    lv_init();

    /*Linux frame buffer device init*/
    fbdev_init();

    /*A small buffer for LittlevGL to draw the screen's content*/
    static lv_color_t buf[DISP_BUF_SIZE];

    /*Initialize a descriptor for the buffer*/
    static lv_disp_draw_buf_t disp_buf;
    lv_disp_draw_buf_init(&disp_buf, buf, NULL, DISP_BUF_SIZE);

    /*Initialize and register a display driver*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf   = &disp_buf;
    disp_drv.flush_cb   = fbdev_flush;
    disp_drv.hor_res    = 1024;
    disp_drv.ver_res    = 600;
    lv_disp_drv_register(&disp_drv);

	/* Linux input device init */
    evdev_init();
	
    /* Initialize and register a display input driver */
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);      /*Basic initialization*/

    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = evdev_read;
    lv_indev_t * my_indev = lv_indev_drv_register(&indev_drv); 



//!-------------------------------------------------------------------------------------------
//?   

//!-------------------------------------------------------------------------------------------
    



//!-------------------------------------------------------------------------------------------
    int res1;
    pthread_t thread2;
    
    res1 = pthread_create(&thread2, NULL, lvgl_thread, client);
    if(res1 != 0) {
        MQTT_LOG_E("create mqtt publish thread fail");
        exit(res1);
    }

    // lv_demo_music();
    /*Create a Demo*/
    // lv_100ask_demo_course_2_1_1();
    // lv_demo_widgets();

    /*Handle LitlevGL tasks (tickless mode)*/

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    close(fd);

    return 0;
}


/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}
