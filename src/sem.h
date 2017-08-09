/**
 * 信号量是一个受保护的整数
 * 可以原子化的
 * +1 -> signal
 * -1 -> wait等待s变为正数
 */
#ifndef SEM_INCLUDED
#define SEM_INCLUDED
/**
 * 一个信号量就是指向一个Sem_T结构实例的指针
 */
#define T Sem_T
typedef struct T {
	int count;
	void *queue;
} T;
#define LOCK(mutex) do { Sem_T *_yymutex = &(mutex); \
	Sem_wait(_yymutex);
#define END_LOCK Sem_signal(_yymutex); } while (0)
extern void Sem_init(T *s, int count);
extern T *Sem_new(int count);
extern void Sem_wait(T *s);
extern void Sem_signal(T *s);
#undef T
#endif