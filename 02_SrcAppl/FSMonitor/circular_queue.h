/**
 * File: circular_queue.h
 * File Created:  2019-12-25 12:49:49
 * Last Modified: 2022-11-10 15:12:09
 * Author: MingyiLi
 * 
 * @version 1.3
 * 
 * @brief ls_circular_queue
 * Auto Code-gen a circular queue 
 * 
 * CHANGES:
 * 1.0 init
 * 1.1 add ref_dequeue
 * 1.2 Static initializer
 * 1.3 add (unsafe) ref enqueue
 * 1.4 fix a bug caused by __max_size__ is not surrouned by parentheses.
 *       which expr in __max_size__ will be calculated seperately.and cause size check bug
 */
#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

typedef enum {
    QueueStatus_OK = 0,
    QueueStatus_Error
}QueueStatus;

#ifndef __out
#define __out
#endif 

#define LS_CIRCULAR_QUEUE_HEADER(__prefix__,__data_type__)\
struct __prefix__##_cq_t;\
QueueStatus __prefix__##_init( struct __prefix__##_cq_t *queue );\
QueueStatus __prefix__##_enqueue(struct __prefix__##_cq_t *queue,const __data_type__ *elements);\
QueueStatus __prefix__##_dequeue(struct __prefix__##_cq_t *queue,__out __data_type__ *elements);\
QueueStatus __prefix__##_ref_dequeue(struct __prefix__##_cq_t *queue,__out  __data_type__ **element);\
int __prefix__##_get_length( const struct __prefix__##_cq_t *queue );\


#define LS_CIRCULAR_QUEUE_GEN_FULL(__prefix__,__data_type__,__max_size__,__fn_describtor__) \
struct __prefix__##_cq_t{\
    __data_type__ elements[__max_size__];\
    int front;\
    int rear;\
};\
__fn_describtor__ QueueStatus __prefix__##_init( struct __prefix__##_cq_t *queue ){ \
    queue->front      = 0;\
    queue->rear       = 0;\
    return QueueStatus_OK;\
}\
__fn_describtor__ QueueStatus __prefix__##_ref_enqueue(struct __prefix__##_cq_t *queue,__data_type__ **element){\
    if( (queue->rear + 1) % (__max_size__) == queue->front) {\
        return QueueStatus_Error;\
    }\
    *element = &queue->elements[queue->rear];\
    queue->rear = (queue->rear + 1) % (__max_size__);\
    return QueueStatus_OK;\
}\
__fn_describtor__ QueueStatus __prefix__##_enqueue(struct __prefix__##_cq_t *queue,const __data_type__ *element){\
    if( (queue->rear + 1) % (__max_size__) == queue->front) {\
        return QueueStatus_Error;\
    }\
    queue->elements[queue->rear] = *element;\
    queue->rear = (queue->rear + 1) % (__max_size__);\
    return QueueStatus_OK;\
}\
__fn_describtor__ QueueStatus __prefix__##_ref_dequeue(struct __prefix__##_cq_t *queue,__data_type__ **element){\
    if(queue->front == queue->rear){\
        return QueueStatus_Error;\
    }\
    if(element != NULL){\
        *element = queue->elements + queue->front;\
    }\
    queue->front  = (queue->front + 1) % (__max_size__);\
    return QueueStatus_OK;\
}\
__fn_describtor__ QueueStatus __prefix__##_dequeue(struct __prefix__##_cq_t *queue,__out __data_type__ *element){\
    if(queue->front == queue->rear){\
        return QueueStatus_Error;\
    }\
    if(element){\
        *element = queue->elements[queue->front];\
    }\
    queue->front  = (queue->front + 1) % (__max_size__);\
    return QueueStatus_OK;\
}\
__fn_describtor__ QueueStatus __prefix__##_ref_get(struct __prefix__##_cq_t *queue,__out __data_type__ **element){\
    if(queue->front == queue->rear){\
        return QueueStatus_Error;\
    }\
    *element = queue->elements + (queue->front);\
    return QueueStatus_OK;\
}\
__fn_describtor__ int __prefix__##_get_length( const struct __prefix__##_cq_t *queue ){\
    return (queue->rear - queue->front + (__max_size__)) % (__max_size__);\
}

#define LS_CIRCULAR_QUEUE_GEN(__prefix__,__data_type__,__max_size__) LS_CIRCULAR_QUEUE_GEN_FULL(__prefix__,__data_type__,__max_size__, ) 

#define LS_CIRCULAR_QUEUE_GEN_STATIC(__prefix__,__data_type__,__max_size__) LS_CIRCULAR_QUEUE_GEN_FULL(__prefix__,__data_type__,__max_size__, static )

#define LS_CIRCULAR_QUEUE_INITIALIZER {{},0,0}

#endif /** __CIRCULAR_QUEUE_H__ */
