
#include "mqtt.h"
#include <sys/types.h>
#include "../include/manager.h"

int res;
pthread_t thread1;

static void* mqtt_publish_thread(void* args)
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


static void mqtt_run(void* pParams)
{   

    res = pthread_create(&thread1, NULL, mqtt_publish_thread, client);
    if(res != 0) {
        MQTT_LOG_E("create mqtt publish thread fail");
        exit(res);
    }
}

static void mqtt_init(void)
{
    
    mqtt_client_t *client = NULL;
    
    printf("\nwelcome to mqttclient test...\n");

    mqtt_log_init();

    client = mqtt_lease();

#ifdef TEST_USEING_TLS
    mqtt_set_port(client, "8883");
    mqtt_set_ca(client, (char*)test_ca_get());
#else
    mqtt_set_port(client, "5000");
#endif

//    mqtt_set_host(client, "120.25.213.14"); /* iot.100ask.net */
    mqtt_set_host(client, "192.168.64.45"); /* iot.100ask.net */
//    mqtt_set_host(client, "192.168.0.112"); /* iot.100ask.net */
    mqtt_set_client_id(client, random_string(10));
    mqtt_set_user_name(client, random_string(10));
    mqtt_set_password(client, random_string(10));
    mqtt_set_clean_session(client, 1);

    mqtt_connect(client);
    
    mqtt_subscribe(client, "topic1", QOS0, topic1_handler);
    mqtt_subscribe(client, "topic2", QOS1, NULL);
    mqtt_subscribe(client, "topic3", QOS2, NULL);
    
    
}

static oid mqtt_release(void)
{
    pthread_join(thread1, NULL);
}

Console_t mqtt_thread = {
    .name = "mqtt",
    .Create = mqtt_init,
    .Run = mqtt_run,
    .Release = mqtt_release,

    .ptNext = NULL,
}


void register_mqtt(void)
{
    dev_join(&mqtt_thread);
}
