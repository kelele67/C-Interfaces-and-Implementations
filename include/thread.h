#ifndef THREAD_INCLUDED
#define THREAD_INCLUDED
#include "except.h"
#define T Thread_T
typedef struct T *T
extern const Except_T Thread_Failed;
extern const Except_T Thread_Alerted;
extern int Thread_init(int preempt, ...);
extern T Thread_new(int apply(void *), void *args, int nbytes);
extern void Thread_exit(int code);
extern void Thread_alert(T t);
extern T Thread_self(void); // 返回调用线程的线程句柄
extern int Thread_join(T t); // 导致调用线程暂停执行，直至线程t通过调用Thread_exit结束 
extern void Thread_pause(void) // 导致调用线程放弃处理器
#undef T
#endif