#ifndef UI_H
#define UI_H

#include <sys/select.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

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



#endif