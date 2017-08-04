/**
 * 将对标准库中内存管理函数的调用封装到通过Mem接口规定的更安全的软件包中
 */
#include <stdlib.h>
#include <stddef.h>
#include "assert.h"
#include "except.h"
#include "mem.h"
const Except_T Mem_Failed = {"Allocation Failed"};
void *Mem_alloc(long nbtyes, const char *file, int line) {
	void *ptr;
	assert(nbtyes > 0);
	ptr = malloc(nbtyes);
	if (ptr == NULL) {
		if (file == NULL)
			RAISE(Mem_Failed);
		else
			Except_raise(&Mem_Failed, file, line);
	}
	return ptr;
}
void *Mem_calloc(long count, long nbtyes,
	const char *file, int line) {
	void *ptr;
	assert(count > 0);
	assert(nbtyes > 0);
	ptr = calloc(count, nbtyes);
	if (ptr == NULL) {
		if (file == NULL)
			RAISE(Mem_Failed);
		else
			Except_raise(&Mem_Failed, file, line);
	}
	return ptr;
}
void Mem_free(void *ptr, const char *file, int line) {
	if (ptr)
		free(ptr);
}
void *Mem_resize(void *ptr, long nbtyes,
	const char *file, int line) {
	assert(ptr);
	assert(nbtyes > 0);
	ptr = realloc(ptr, nbtyes);
	if (ptr == NULL) {
		if (file == NULL)
			RAISE(Mem_Failed);
		else
			Except_raise(&Mem_Failed, file, line);
	}
	return ptr;
}