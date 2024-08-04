


#include "main_page.h"

#define MY_DEV_NUM 1


int fd = -1;
static int led_status = 0;
static int status = 0;
lv_obj_t* main_page = NULL;
lv_obj_t* consoleIcon = NULL;
lv_obj_t* tah_cont = NULL;

SCREEN_TYPE_E cur_scr = 0, last_scr=0;

extern lv_obj_t* main_page;
extern lv_obj_t* menu_page;
extern lv_obj_t* menu_page;
extern void create_menu_page();


static int temp_value = 30;
static int humi_value = 90;

void change_screen(int stype)
{
    cur_scr = stype;
    switch (stype) {
        case SCREEN_TYPE_MAIN:
            cur_scr = SCREEN_TYPE_MAIN;
            break;
        case SCREEN_TYPE_MENU:
            cur_scr = SCREEN_TYPE_MENU;
            break;
    }
}
static int led_open(char* file)
{
	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		printf("can not open file %s\n", file);
		return -1;
	}
	return fd;
}

static void led_on(int fd)
{	
	status = 1;
	write(fd, &status, 1);
}


static void led_off(int fd)
{	
	status = 0;
	write(fd, &status, 0);

}

static void led_close(int fd)
{
	close(fd);
}

int res2;
pthread_t thread2;
static void mainpage_exit(void)
{	
	led_close(fd);
	pthread_join(thread2, NULL);
}
static void cur_screen_set(enum SCREEN_TYPE cur, enum SCREEN_TYPE last)
{
    cur_scr = cur;
    last_scr = last;
}
static void _ui_screen_change(lv_obj_t* obj, int time, int delay)
{
    lv_scr_load_anim(obj, LV_SCR_LOAD_ANIM_FADE_ON, time, delay, false);//!切换有动画需要传入有点延时
}
void mainpage_create(void);
static void* mainpage_thread(void* args)
{   
    cur_screen_set(SCREEN_TYPE_CHANNEL, SCREEN_TYPE_CHANNEL);
    change_screen(SCREEN_TYPE_MAIN);
	while(1) {
      /* Periodically call the lv_task handler.
       * It could be done in a timer interrupt or an OS task too.*/
        if(cur_scr != last_scr){
            switch(cur_scr){
                case SCREEN_TYPE_MAIN:
                    if(!main_page)
                        mainpage_create();
                    _ui_screen_change(main_page, 500, 0);
                break;
                case SCREEN_TYPE_MENU:
                    if(!menu_page)
                        create_menu_page();
                    _ui_screen_change(menu_page,  500, 0 );
                break;
            
            }
            last_scr = cur_scr;
        }
        
        
        lv_timer_handler();
        usleep(5 * 1000);
    }
	pthread_exit(NULL);
}


static void mainpage_run(void* p)
{
	res2 = pthread_create(&thread2, NULL, mainpage_thread, NULL);
	if(res2 != 0) {
		printf("create ledtest thread fail");
		exit(res2);
	}
}


static void consoleIcon_click_event_cb(lv_event_t* e)
{
    lv_obj_t* obj = lv_event_get_target(e);
    if(e->code == LV_EVENT_PRESSED) {

        change_screen(SCREEN_TYPE_MENU);
        
    }
}

static void create_funcBar(lv_obj_t* parent)
{
    lv_obj_t* cont = lv_obj_create(parent);
    static const lv_coord_t grid_cols[] = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static const lv_coord_t grid_rows[] = {LV_GRID_FR(1), LV_GRID_FR(1),LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    
    lv_obj_set_grid_dsc_array(cont, grid_cols, grid_rows);
    lv_obj_set_size(cont , LV_PCT(6), LV_PCT(85));
    lv_obj_set_style_bg_color(cont,  lv_color_make(0x34, 0x36, 0x47),LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cont, LV_STATE_DEFAULT, 255);
    lv_obj_set_style_border_width(cont, 0, 0);
    lv_obj_align_to(cont, consoleIcon, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
   
    //! 设置网格圆角为最大
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_radius(&style, LV_RADIUS_CIRCLE);
    lv_obj_add_style(cont, &style, 0);

}

static void create_tah_cont(lv_obj_t* parent)
{
    tah_cont = lv_obj_create(parent);
    lv_obj_set_size(tah_cont, LV_PCT(30), LV_PCT(95));
    lv_obj_set_style_bg_color(tah_cont, lv_color_make(0x34, 0x36, 0x47),LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(tah_cont, 0, 0);

    lv_obj_align(tah_cont, LV_ALIGN_RIGHT_MID, -10, 0);

    lv_obj_t* label = lv_label_create(tah_cont);
    lv_label_set_text(label, "Temperature and humidity");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_16, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
    lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 0);

    static lv_style_t style_arc;
    lv_style_init(&style_arc);


    lv_style_set_bg_color(&style_arc, lv_color_make(234, 60, 155));  // 起始颜色
    lv_style_set_bg_grad_color(&style_arc, lv_color_make(0, 0, 0));  // 结束颜色
    lv_style_set_bg_grad_dir(&style_arc, LV_GRAD_DIR_VER);  // 渐变方向




    lv_obj_t* temp_arc = NULL;
    lv_obj_t* humi_arc = NULL;
  
    temp_arc = lv_arc_create(tah_cont);
    lv_obj_set_size(temp_arc, 160, 160);
    lv_obj_align(temp_arc, LV_ALIGN_TOP_MID, 0, 50);

    lv_arc_set_rotation(temp_arc, 0);
    lv_arc_set_bg_angles(temp_arc, 0, 360);
    lv_obj_remove_style(temp_arc, NULL, LV_PART_KNOB);   /*Be sure the knob is not displayed*/
    lv_obj_clear_flag(temp_arc, LV_OBJ_FLAG_CLICKABLE);  /*To not allow adjusting by click*/
    //设置颜色可以随着值的改变进行渐变
    lv_obj_set_style_arc_color(temp_arc, lv_color_make(234, 60, 155), LV_PART_INDICATOR);


    
    lv_obj_t* label_temp = lv_label_create(tah_cont);
    lv_label_set_text_fmt(label_temp, "temp: %d°C", 20);
    lv_obj_set_style_text_font(label_temp, &lv_font_montserrat_16, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label_temp, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
    lv_obj_align_to(label_temp, temp_arc, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_style(temp_arc, &style_arc, LV_PART_INDICATOR);

    lv_arc_set_value(temp_arc, temp_value); //! 这个可以设置温度值 0-100的温度
    
//todo----
    // lv_obj_t* 
//todo----
    humi_arc = lv_arc_create(tah_cont);
    lv_obj_set_size(humi_arc, 160, 160);
    lv_obj_align(humi_arc, LV_ALIGN_BOTTOM_MID, 0, -50);

    lv_arc_set_rotation(humi_arc, 0);
    lv_arc_set_bg_angles(humi_arc, 0, 360);
    lv_obj_remove_style(humi_arc, NULL, LV_PART_KNOB);   /*Be sure the knob is not displayed*/
    lv_obj_clear_flag(humi_arc, LV_OBJ_FLAG_CLICKABLE);  /*To not allow adjusting by click*/
    lv_obj_set_style_arc_color(humi_arc, lv_color_make(42, 172, 236), LV_PART_INDICATOR);
    


    lv_obj_t* label_humi = lv_label_create(tah_cont);
    lv_label_set_text_fmt(label_humi, "humi: %d%%", 30);
    lv_obj_set_style_text_font(label_humi, &lv_font_montserrat_16, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label_humi, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
    lv_obj_align_to(label_humi, humi_arc, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_style(humi_arc, &style_arc, LV_PART_INDICATOR);


    lv_arc_set_value(humi_arc, humi_value); //! 这个可以设置湿度值 0-100的湿度


}

static void create_my_dev_cont(lv_obj_t* obj)
{

    // // lv_obj_t* list_btn12 =
    const char *names[] = {"air conditioner", "refrigerator", "Water heater", "Electric light"};
    lv_palette_t colors[] = {LV_PALETTE_BLUE, LV_PALETTE_RED, LV_PALETTE_YELLOW, LV_PALETTE_GREEN};
    lv_coord_t values[] = {216, 173, 86, 72};
    int percentages[] = {70, 56, 30, 15};

    lv_obj_t* cont = lv_obj_create(obj);
    lv_obj_set_size(cont, LV_PCT(30), LV_PCT(45));
    lv_obj_align_to(cont, tah_cont, LV_ALIGN_OUT_LEFT_BOTTOM, -315, 0);
    lv_obj_set_style_bg_color(cont, lv_color_make(52, 54, 71), 0);
    lv_obj_set_style_border_width(cont, 0, 0);

    lv_obj_t* label = lv_label_create(cont);
    lv_label_set_text(label, "Electricity consumption: ");
    lv_obj_set_style_text_color(label, lv_color_make(255, 255, 255), 0);
    lv_obj_align(label, LV_ALIGN_TOP_LEFT, 0, 5);

    static const lv_img_dsc_t* img_dscs[] = {&_air_conditioner_alpha_30x30, &_refrigerator_alpha_30x30, 
                                            &_Water_heater_alpha_30x30, &_The_lamp_alpha_30x30};
    for(int i = 0; i< 4; i++)
    {
        lv_obj_t* slider = lv_slider_create(cont);
        lv_obj_set_size(slider, 200, 3);
        //放到cont的左上角
        lv_obj_align(slider, LV_ALIGN_TOP_RIGHT, -10, 20 + i * 45 + 40);
        // lv_obj_set_grid_cell(slider, LV_GRID_ALIGN_END, i % 2, i / 2, LV_GRID_ALIGN_CENTER, 0, 1);
        lv_slider_set_value(slider, percentages[i], LV_ANIM_ON);
        lv_obj_clear_flag(slider, LV_OBJ_FLAG_CLICKABLE);

        lv_obj_set_style_bg_color(slider, lv_palette_main(colors[i]), LV_PART_INDICATOR);

        //改变把手的颜色
        lv_obj_set_style_bg_color(slider, lv_palette_main(colors[i]), LV_PART_KNOB);
        //给把手添加边框颜色为白色
        lv_obj_set_style_border_color(slider, lv_color_make(255, 255, 255), LV_PART_KNOB);
        lv_obj_set_style_border_width(slider, 2, LV_PART_KNOB);


        lv_obj_t* img = lv_img_create(cont);
        lv_img_set_src(img, img_dscs[i]);
        lv_obj_align_to(img, slider, LV_ALIGN_OUT_LEFT_MID, -10, 0);

        lv_obj_t* label = lv_label_create(cont);
        lv_label_set_text_fmt(label, "%s (%d)", names[i], values[i]);
        lv_obj_set_style_text_color(label, lv_color_make(255, 255, 255), 0);
        lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_LEFT, 0, -7);
        // label = lv_label_create(cont);
        // lv_label_set_text_fmt(label, "%s (%d)", names[i], values[i]);
        // lv_obj_set_grid_cell(label, LV_GRID_ALIGN_START, i % 2, i / 2, LV_GRID_ALIGN_CENTER, 0, 1);
        // lv_obj_align_to(label, slider, LV_ALIGN_OUT_RIGHT_MID, 10, 10);
    }

}
static void dev_control_event_cb(lv_event_t* e)
{   
    lv_obj_t* obj = lv_event_get_target(e);
    if(e->code == LV_EVENT_PRESSED) {
        printf("click\n");
        led_status = !led_status;
        if(led_status)
            lv_obj_set_style_bg_img_opa(obj, 255, 0);
        else
            lv_obj_set_style_bg_img_opa(obj, 50, 0);
            
    }
}


static void create_dev_control(lv_obj_t* obj)
{
    lv_obj_t* cont = lv_obj_create(obj);

    lv_obj_set_size(cont, LV_PCT(60), LV_PCT(48));
    lv_obj_align_to(cont, tah_cont, LV_ALIGN_OUT_LEFT_TOP, -10, 0);
    lv_obj_set_style_bg_color(cont, lv_color_make(52, 54, 71), 0);
    lv_obj_set_style_border_width(cont, 0, 0);

    static const lv_coord_t grid_cols[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static const lv_coord_t grid_rows[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};

    lv_obj_t* grid = lv_obj_create(cont);
    lv_obj_set_grid_dsc_array(cont, grid_cols, grid_rows);
    lv_obj_set_size(grid, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_bg_opa(grid, 0, 0);
    lv_obj_set_style_border_width(grid, 0, 0);
    lv_obj_center(grid);
   

    static const lv_img_dsc_t* img_dscs[] = {&_led_livingRoom_alpha_60x60, &_led_livingRoom_alpha_60x60, 
                                            &_led_livingRoom_alpha_60x60, &_led_livingRoom_alpha_60x60};
    static const char* names[] = {"lv led", "led2", "led3", "led4"};
    
    for(int i = 0; i< MY_DEV_NUM; i++)
    {
        lv_obj_t* imgbtn = lv_imgbtn_create(grid);
        lv_obj_set_grid_cell(imgbtn, LV_GRID_ALIGN_STRETCH, i%3, 0, LV_GRID_ALIGN_STRETCH, i/3, 0);
        lv_obj_set_style_bg_img_src(imgbtn,img_dscs[i] ,LV_STATE_DEFAULT);
        lv_obj_set_size(imgbtn, 60, 60);
        lv_obj_add_event_cb(imgbtn, dev_control_event_cb, LV_EVENT_PRESSED, NULL);

        lv_obj_t* label = lv_label_create(grid);
        lv_label_set_text(label, names[i]);
        lv_obj_set_style_text_color(label, lv_color_make(255, 255, 255), 0);
        lv_obj_align_to(label, imgbtn, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
    }
}

static void create_Bar_chart(lv_obj_t* obj)
{
    lv_obj_t* cont_chart = lv_obj_create(obj);
    lv_obj_set_size(cont_chart, LV_PCT(29), LV_PCT(45));
    lv_obj_align_to(cont_chart, tah_cont, LV_ALIGN_OUT_LEFT_BOTTOM, -10, 0);
    lv_obj_set_style_bg_color(cont_chart, lv_color_make(52, 54, 71), 0);
    lv_obj_set_style_border_width(cont_chart, 0, 0);



    //创建树状图
    lv_obj_t* chart = lv_chart_create(cont_chart);
    lv_obj_set_size(chart, LV_PCT(100), LV_PCT(100));
    lv_obj_align(chart, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_bg_opa(chart, 0, 0);
    // lv_chart_set_type(chart, LV_CHART_TYPE_COLUMN);
    // lv_chart_set_range(chart, 0, 100);

        // 设置图表的点数
    lv_chart_set_point_count(chart, 10); // 设置图表的点数

    // 设置图表的范围
    lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_X, 0, 100);
    lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 0, 100);
    
    //创建4个序列
    lv_chart_series_t* ser0 = lv_chart_add_series(chart , lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_X);
    lv_chart_series_t* ser1 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_series_t* ser2 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_series_t* ser3 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_series_t* ser4 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_YELLOW), LV_CHART_AXIS_PRIMARY_Y);

    //设置序列值
    // lv_chart_set_next(chart, ser1, 10);
    // lv_chart_set_next(chart, ser2, 20);
    lv_chart_set_next_value(chart, ser1, 10);
    lv_chart_set_next_value(chart, ser1, 20);
    lv_chart_set_next_value(chart, ser1, 30);
    lv_chart_set_next_value(chart, ser1, 40);
    lv_chart_set_next_value(chart, ser1, 50);

    lv_chart_set_next_value(chart, ser2, 15);
    lv_chart_set_next_value(chart, ser2, 25);
    lv_chart_set_next_value(chart, ser2, 35);
    lv_chart_set_next_value(chart, ser2, 45);
    lv_chart_set_next_value(chart, ser2, 55);



}

void mainpage_create(void)
{
	main_page = lv_obj_create(NULL);
    // main_page = lv_scr_act();
    lv_obj_set_size(main_page, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_radius(main_page, 0, 0);
    lv_obj_set_style_bg_color(main_page, lv_color_make(34,36,37), 0);
    lv_obj_set_style_border_color(main_page, lv_color_make(23,27,36), 0);
    lv_obj_set_style_border_width(main_page, 5, 0);

    consoleIcon = lv_imgbtn_create(main_page);
    lv_obj_set_style_bg_img_src(consoleIcon,&(_ConsoleIcon_alpha_50x50) ,LV_STATE_DEFAULT);
    lv_obj_set_size(consoleIcon, 50, 50);
    lv_obj_set_style_bg_img_opa(consoleIcon, LV_STATE_DEFAULT, 255);
    lv_obj_align(consoleIcon, LV_ALIGN_TOP_LEFT, 10, 10);

    lv_obj_add_event_cb(consoleIcon, consoleIcon_click_event_cb, LV_EVENT_PRESSED, NULL);

    create_funcBar(main_page);

    create_tah_cont(main_page);

    create_my_dev_cont(main_page);

    create_dev_control(main_page);

    create_Bar_chart(main_page);

}


Console_t lv_mainpage = {
	.name = "lv_mainpage",
	.Create = mainpage_create,
	.Run = mainpage_run,
	.Release = mainpage_exit,
	.ptNext = NULL
};

void register_lvgl(void)
{	
	dev_join(&lv_mainpage);
}