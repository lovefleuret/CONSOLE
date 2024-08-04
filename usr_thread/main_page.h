#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "lvgl/src/lv_api_map.h"
#include "manager.h"

#include "../include/manager.h"


typedef enum SCREEN_TYPE{
    SCREEN_TYPE_MAIN,
    SCREEN_TYPE_MENU,
    SCREEN_TYPE_CHANNEL
}SCREEN_TYPE_E;

LV_IMG_DECLARE(_ConsoleIcon_alpha_50x50);
LV_IMG_DECLARE(_back_alpha_50x50);
LV_IMG_DECLARE(_air_conditioner_alpha_30x30);
LV_IMG_DECLARE(_refrigerator_alpha_30x30);
LV_IMG_DECLARE(_The_lamp_alpha_30x30);
LV_IMG_DECLARE(_Water_heater_alpha_30x30);
LV_IMG_DECLARE(_led_livingRoom_alpha_60x60);


void register_test(void);
void register_lvgl(void);
void change_screen(int stype);


#endif