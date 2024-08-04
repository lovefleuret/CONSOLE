#include "menu_page.h"
#include "lvgl/src/core/lv_obj_pos.h"
#include "lvgl/src/misc/lv_color.h"

lv_obj_t* menu_page = NULL;
lv_obj_t* list_btn = NULL;
lv_obj_t* list_btn1 = NULL;
lv_obj_t* list_btn2 = NULL;
lv_obj_t* list_btn3 = NULL;
lv_obj_t* list_btn4 = NULL;
lv_obj_t* list_btn5 = NULL;
lv_obj_t* list_btn6 = NULL;
lv_obj_t* list_btn7 = NULL;
lv_obj_t* list_btn8 = NULL;
lv_obj_t* list_btn9 = NULL;
lv_obj_t* list_btn10 = NULL;
lv_obj_t* list_btn11 = NULL;
lv_obj_t** list_group[] = {&list_btn, &list_btn1, &list_btn2, &list_btn3, &list_btn4, &list_btn5, 
&list_btn6, &list_btn7, &list_btn8, &list_btn9, &list_btn10, &list_btn11};

static void event_btn_cb(lv_event_t* e)
{
    if(e->code == LV_EVENT_CLICKED)
    {
        change_screen(SCREEN_TYPE_MAIN);
    }
}

static void create_menu_page_widgets(lv_obj_t* obj)
{
    lv_obj_t* back_btn = lv_imgbtn_create(menu_page);
    lv_obj_set_style_bg_img_src(back_btn,&(_back_alpha_50x50) ,LV_STATE_DEFAULT);
    lv_obj_set_size(back_btn, 50, 50);
    lv_obj_set_style_bg_img_opa(back_btn, LV_STATE_DEFAULT, 255);
    lv_obj_align(back_btn, LV_ALIGN_TOP_LEFT, 10, 10);
    // lv_obj_invalidate(back_btn);//!手动刷新界面函数

    lv_obj_add_event_cb(back_btn, event_btn_cb, LV_EVENT_CLICKED, NULL);

}

static void event_list_btn_cb(lv_event_t* e)
{   
    lv_obj_t* obj = lv_event_get_target(e);
    if(e->code == LV_EVENT_CLICKED)
    {
        if(obj == list_btn)
        {
            printf("Home\n");
            change_screen(SCREEN_TYPE_MAIN);
        }
        else if(obj == list_btn1)
        {
            printf("Bell\n");
        }
        else if(obj == list_btn2)
        {
            printf("Settings\n");
            
        }
        else if(obj == list_btn3)
        {
            printf("Wifi\n");
        }
        else if(obj == list_btn4)
        {
            printf("Battery\n");
        }
        else if(obj == list_btn5)
        {
            printf("Bluetooth\n");
        }
        else if(obj == list_btn6)
        {
            printf("GPS\n");
        }
        else if(obj == list_btn7)
        {
            printf("USB\n");
        }
        else if(obj == list_btn8)
        {
            printf("SD Card\n");
        }
        else if(obj == list_btn9)
        {
            printf("File\n");
        }
        else if(obj == list_btn10)
        {
            printf("Close\n");
        }
        else if(obj == list_btn11)
        {
            printf("OK\n");
        }
    }
}

static void create_menu_list(lv_obj_t* obj)
{
    lv_obj_t* cont = lv_obj_create(obj);
    lv_obj_set_size(cont, LV_PCT(30), LV_PCT(95));
    lv_obj_set_style_bg_color(cont, lv_color_make(0x34, 0x36, 0x47),LV_STATE_DEFAULT);
    lv_obj_align(cont, LV_ALIGN_LEFT_MID, 100, 0);

    lv_obj_t* label = lv_label_create(cont);
    lv_label_set_text(label, "My devices");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_16, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
    lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 0);
//! 创建列表的例子
    lv_obj_t* list = lv_list_create(cont);
    lv_obj_set_size(list, LV_PCT(100), LV_PCT(100));
    lv_obj_align(list, LV_ALIGN_BOTTOM_LEFT, 0, 0);
//! 一些自带的图标
    list_btn = lv_list_add_btn(list, LV_SYMBOL_HOME, "Home");
    list_btn1 = lv_list_add_btn(list, LV_SYMBOL_BELL, "Bell");
    list_btn2 = lv_list_add_btn(list, LV_SYMBOL_SETTINGS, "Settings");
    list_btn3 = lv_list_add_btn(list, LV_SYMBOL_WIFI, "Wifi");
    list_btn4 = lv_list_add_btn(list, LV_SYMBOL_BATTERY_FULL, "Battery");
    list_btn5 = lv_list_add_btn(list, LV_SYMBOL_BLUETOOTH, "Bluetooth");
    list_btn6 = lv_list_add_btn(list, LV_SYMBOL_GPS, "GPS");
    list_btn7 = lv_list_add_btn(list, LV_SYMBOL_USB, "USB");
    list_btn8 = lv_list_add_btn(list, LV_SYMBOL_SD_CARD, "SD Card");
    list_btn9 = lv_list_add_btn(list, LV_SYMBOL_FILE, "File");
    list_btn10 = lv_list_add_btn(list, LV_SYMBOL_CLOSE, "Close");
    list_btn11 = lv_list_add_btn(list, LV_SYMBOL_OK, "OK");


    for(int i = 0; i < 12; i++)
    {
        lv_obj_add_event_cb(*list_group[i], event_list_btn_cb, LV_EVENT_CLICKED, NULL);
    }
}

void create_menu_page()
{

    menu_page = lv_obj_create(NULL);
    // menu_page = lv_scr_act();
    lv_obj_set_style_bg_color(menu_page, lv_color_make(52, 54, 71), 0);
    lv_obj_set_size(menu_page,LV_PCT(100),LV_PCT(100));

 

    create_menu_page_widgets(menu_page);
    create_menu_list(menu_page);
}