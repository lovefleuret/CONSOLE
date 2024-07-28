#include "test2.h"


lv_obj_t* label1;

int res3;
pthread_t thread3;
void test2_Create(void)
{
    label1 = lv_label_create(lv_scr_act());
    lv_label_set_text(label1, "test2_Create");
    lv_obj_align(label1, NULL, LV_ALIGN_TOP_LEFT, 0);

}

void* test2_thread(void* args)
{
    while(1)
    {
        lv_task_handler();
        usleep(5000);
    }
}
void test2_Run(void *pParams)
{
    res3 = pthread_create(&thread3, NULL, test2_thread, NULL);
    if(res3 != 0) {
        printf("create test2 thread fail");
        exit(res3);
    }
}


void test2_Release(void)
{   
    pthread_exit(NULL);
    printf("test2_Release\n");
}






Console_t test2 = {
    .name = "test2",
    .Create = test2_Create,
    .Run = NULL,
    .Release = NULL,
    .ptNext = NULL,
};


void register_test2(void)
{
    dev_join(&test2);
    
}