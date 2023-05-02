//
// Created by xiazhiping on 2022/5/28.
//

#ifndef APP_CUP_CUSTOM_SRC_MAIN_EVENT_BASE_H_
#define APP_CUP_CUSTOM_SRC_MAIN_EVENT_BASE_H_

#define WAIT_UNTIL_MSG 0xFFFFFFFF
#define WAIT_NO_TIME   0




typedef void (*msg_callback_t)(int ret_code,void *param);



typedef struct message {
    int id;
    int arg1;
    int arg2;
    void *param;
    int action;
    msg_callback_t cb;
} message_t;


// message init
int __gui_receive_msg(char *s, int line, message_t *msg, int time_ms);
int __gui_send_msg(char *s, int line, message_t *msg, int time_ms);

int __app_send_msg(char *s, int line, message_t *msg, int time_ms);
int __app_receive_msg(char *s,int line, message_t *msg, int time_ms);

#define app_send_msg(a, b) __app_send_msg((char *) __func__,__LINE__ , a, b)
#define app_receive_msg(a, b) __app_receive_msg((char *) __func__,__LINE__ , a, b)
#define gui_send_msg(a, b)  __gui_send_msg((char *) __func__,__LINE__ , a, b)
#define gui_receive_msg(a, b) __gui_receive_msg((char *) __func__,__LINE__ , a, b)
void gui_reset_app_msg(void);
void app_reset_gui_msg(void);
int app_get_msg_num(void);
int get_gui_msg_num(void);
int get_app_msg_num(void);

int gui_msg_init(void);
void gui_mutex_init(void);
void gui_mutex_lock(void);
void gui_mutex_unlock(void);

void app_sem_init(void);
void app_sem_wait(void);
void app_sem_post(void);

typedef  int (*msg_cb_t)(message_t *msg);
void app_init_msg_cb(void);
int app_add_msg_cb(msg_cb_t cb);
int app_remove_msg_cb(msg_cb_t cb);
void app_clear_msg_cb(void);
void app_run_msg_cb(message_t *msg);

#endif //APP_CUP_CUSTOM_SRC_MAIN_EVENT_BASE_H_
