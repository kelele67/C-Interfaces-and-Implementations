#ifndef THREAD_INCLUDED
#define THREAD_INCLUDED
#include "except.h"
#define T Thread_T
typedef struct T *T
extern const Except_T Thread_Failed;
extern const Except_T Thread_Alerted;
extern int Thread_init(int preempt, ...);
extern T Thread_new(int apply(void *), void *args, int nbytes); // 创建一个新线程并返回其线程句柄（不透明指针）
extern void Thread_exit(int code);
extern void Thread_alert(T t); // 设置线程的 “警报-待决”标志 
                               // 阻塞->清除标志->运行->下一次运行引发Thread_Alerted异常，
                               // 运行->清除标志->下一次调用Thread_join或调用可能导致阻塞的通信或同步函数时引发Thread_Alerted异常
extern T Thread_self(void); // 返回调用线程的线程句柄
extern int Thread_join(T t); // 导致调用线程暂停执行，直至线程t通过调用Thread_exit结束 
extern void Thread_pause(void) // 导致调用线程放弃处理器
#undef T
#endif