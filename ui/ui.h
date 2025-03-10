#ifndef UI_H
#define UI_H

#include <sys/select.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"

#include "lvgl/demos/lv_demos.h"
#include "lvgl/examples/widgets/lv_example_widgets.h"
#include "lvgl/src/core/lv_event.h"
#include "lvgl/src/core/lv_obj_pos.h"


#define DISP_BUF_SIZE (1024 * 600)

void LVGL_init(void);


#endif