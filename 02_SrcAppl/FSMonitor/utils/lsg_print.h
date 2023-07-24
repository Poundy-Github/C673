#ifndef LSG_PRINT_H
#define LSG_PRINT_H
#include "lsglog.h"

void lsg_log_set_gloabl(struct lsg_log_t *log);

void lsg_log_print(const char *str);

void lsg_log_printf(const char *format,...);

#endif /** LSG_PRINT_H */