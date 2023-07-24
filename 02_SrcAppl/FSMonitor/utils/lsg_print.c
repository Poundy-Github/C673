#include "lsg_print.h"
#include <stdarg.h>
#include "printf.h"

#pragma section farbss "log.g_lsg_log"
static struct lsg_log_t *s_global_log;
#pragma section farbss restore

int strlen_(const char *str) {
    if(str==NULL) return 0;

    int len = 0;
    for(; *str++ != '\0'; )
    {
        len++;
    }
    return len;
}

void lsg_log_set_gloabl(struct lsg_log_t *log){
    s_global_log = log;
}

void lsg_log_print(const char *str){
    lsg_log_write(s_global_log,str,strlen_(str));
}
static char tmp_buff[256];
void lsg_log_printf(const char *format,...){
    va_list args;

    va_start(args,format);

    vsnprintf(tmp_buff,sizeof(tmp_buff),format,args);

    va_end(args);

    tmp_buff[sizeof(tmp_buff)-1] = '\0';
    
    lsg_log_print(tmp_buff);

}