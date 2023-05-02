//
// Created by xiazhiping on 2022/5/28.
//

#include <stdint.h>
#include "posapi.h"
#include "libcalg.h"
#include "event_base.h"
#include "lvgl.h"


#define __HAVE_DEBUG_INFO__
#include "api_debug.h"

//#define api_printf(a, arg...) do{printf(a, ##arg);printf("\r\n");}while(0)
static void *global_lvgl_queue;
static void *global_app_queue;
static void *global_lvgl_mutex;
static void *global_app_sem;

static ListEntry *global_obser_list=NULL;

#define MAX_MSG_SIZE 5

void app_sem_init(void)
{
    global_app_sem = TosSemaphoreCreate();
    if (global_app_sem == NULL) {
        while (1) {
            api_printf("error: app TosSemaphoreCreate");
            sysDelayMs(1000);
        }
    }
}

void app_sem_wait(void)
{
    api_printf("TosSemaphoreTake wait");
    TosSemaphoreTake(global_app_sem);
}

void app_sem_post(void)
{
    api_printf("TosSemaphoreTake give");
    TosSemaphoreGive(global_app_sem);
}


void gui_mutex_init(void)
{
    global_lvgl_mutex = TosMutexCreate();
    if (global_lvgl_mutex == NULL) {
        while (1) {
            api_printf("error: TosMutexCreate");
            sysDelayMs(1000);
        }
    }
}

void gui_mutex_lock(void)
{
    TosMutexTake(global_lvgl_mutex);
}

void gui_mutex_unlock(void)
{
    TosMutexGive(global_lvgl_mutex);
}

int gui_msg_init(void)
{
    global_lvgl_queue = TosQueueCreate(MAX_MSG_SIZE, sizeof(message_t));
    if (global_lvgl_queue == NULL) {
        while (1) {
            api_printf("error: TosQueueCreate");
            sysDelayMs(1000);
        }
        return -1;
    }

    global_app_queue = TosQueueCreate(MAX_MSG_SIZE, sizeof(message_t));
    if (global_app_queue == NULL) {
        while (1) {
            api_printf("error: TosQueueCreate");
            sysDelayMs(1000);
        }
        return -1;
    }

    return 0;
}


int get_gui_msg_num(void)
{
    return (MAX_MSG_SIZE-TosQueueSpacesAvailable(global_lvgl_queue));
}

int get_app_msg_num(void)
{
    return (MAX_MSG_SIZE-TosQueueSpacesAvailable(global_app_queue));
}


int __gui_receive_msg(char *s, int line, message_t *msg, int time_ms)
{
    if (global_app_queue != NULL) {
        return TosQueueReceive(global_app_queue, msg, time_ms);
    }

    return -1;
}

int __gui_send_msg(char *s, int line, message_t *msg, int time_ms)
{
    int retval;
    if (global_lvgl_queue != NULL) {
        LV_LOG_USER("lvgl msg.id=%d, msg.arg1=%d start,  gui_msg_num=%d (%s:%d) ",  msg->id, msg->arg1, get_gui_msg_num(), s, line);
        retval = TosQueueSend(global_lvgl_queue, msg, time_ms);
        LV_LOG_USER("lvgl msg.id=%d, msg.arg1=%d end,  gui_msg_num=%d (%s:%d) ",  msg->id, msg->arg1, get_gui_msg_num(), s, line);
        return retval;
    }

    return -1;
}



void gui_reset_app_msg(void)
{
    LV_LOG_USER("(app_msg_num=%d) enter", get_app_msg_num());
    if(get_app_msg_num()!=0) {
        TosQueueReset(global_app_queue);
    }
    LV_LOG_USER("() exit");
}

void app_reset_gui_msg(void)
{
    api_enter("(gui_msg_num=%d) enter", get_gui_msg_num());
    if(get_gui_msg_num()!=0) {
        TosQueueReset(global_lvgl_queue);
    }
    api_exit("() exit");
}

//int app_clear_msg(void)
//{
//    if (global_lvgl_queue != NULL) {
//        return TosQueueReset(global_lvgl_queue);
//    }
//
//    return -1;
//}

int __app_send_msg(char *s, int line, message_t *msg, int time_ms)
{
    if (global_app_queue != NULL) {
        api_printf("app msg.id=%d, msg.arg1=%d app_msg_num=%d (%s:%d)", msg->id, msg->arg1, get_app_msg_num(), s, line);
        return TosQueueSend(global_app_queue, msg, time_ms);
    }

    return -1;
}

int __app_receive_msg(char *func, int line, message_t *msg, int time_ms)
{
    int retval;
    if (global_lvgl_queue != NULL) {
        if (time_ms == WAIT_UNTIL_MSG) {
            api_printf("TosQueueReceive(WAIT_UNTIL_MSG) start, gui_msg_num=%d (%s:%d)",get_gui_msg_num(), func, line);
        }
        retval = TosQueueReceive(global_lvgl_queue, msg, time_ms);
        if (time_ms == WAIT_UNTIL_MSG) {
//            api_printf("TosQueueReceive(WAIT_UNTIL_MSG)=%d end, id=%d, arg1=%d, gui_msg_num=%d (%s:%d)",
//                       retval, msg->id,msg->arg1, get_gui_msg_num(), func, line);
        }
        return retval;
    }

    return -1;
}


void app_init_msg_cb(void)
{
    global_obser_list = (ListEntry *)TosMalloc(sizeof(ListEntry));
    if (global_obser_list==NULL) {
        while (1) {
            api_printf("error: TosMalloc");
            sysDelayMs(1000);
        }
    }
    memset(global_obser_list, 0, sizeof(ListEntry));
}


int app_add_msg_cb(msg_cb_t cb)
{
    ListEntry *entry = list_append(&global_obser_list, cb);

    return entry == NULL?-1:0;
}
static  int value_compare(ListValue value1, ListValue value2)
{
    return value1 == value2;
}

int app_remove_msg_cb(msg_cb_t cb)
{
    return list_remove_data(&global_obser_list, value_compare, cb);
}

void app_clear_msg_cb(void)
{
    return list_free(global_obser_list);
}

void app_run_msg_cb(message_t *msg)
{
    ListIterator iter;
    msg_cb_t msg_cb;

    api_enter("() enter");

    api_printf("list_length()=%d",list_length(global_obser_list));
    list_iterate(&global_obser_list, &iter);
    while(list_iter_has_more(&iter)){
        msg_cb = (msg_cb_t) list_iter_next(&iter);
        if(msg_cb == NULL){
            api_printf("WARNING msg_cb is null");
            continue;
        }
        msg_cb(msg);
    }

    api_exit("() exit");

}



