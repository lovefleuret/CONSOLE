# Console项目介绍
- 设计框架
```c
      extern int show_gsensor_data;

        static void update_label_cb(lv_timer_t * timer) {
            char buf[32];
            pthread_mutex_lock(&gsensor_mutex);
            snprintf(buf, sizeof(buf), "gsensor: %+d", show_gsensor_data);
            lv_label_set_text(gsensor_data, buf);
            pthread_mutex_unlock(&gsensor_mutex);
      
        }
    


       
        set_label_text2(lv_obj_get_child(keystone_list, UP_OR_CORR), STR_KEY_CORRECTION, FONT_NORMAL);
        gsensor_data = lv_label_create(lv_obj_get_child(keystone_list, UP_OR_CORR));
        lv_label_set_text(gsensor_data, " ");
        lv_obj_set_style_text_color(gsensor_data, lv_color_white(), 0);
        lv_obj_align(gsensor_data, LV_ALIGN_RIGHT_MID, -20, 0);
        lv_timer_create(update_label_cb, 500, NULL);


  
```
