// 地道的使用指针
char *strcpy(char *dst, const char *src) {
	char *s = dst;
	while (*dst++ = *src++); // 如果使用 (*dst++ = *src++) != '\0' 可能会报错
	return s;
}
// 鲁棒性
#include<assert.h>

char *strcpy(char* dst, const char* src) {
	assert((dst != NULL) && (src != NULL));
	char *s = dst;
	while ((*dst++ = *src++) != '\0');
	return s;
}

// 考虑内存重叠的情况

char *strcpy(char* dst, const char *src) {
	assert((dst != NULL) && (src != NULL));
	char *s = dst;
	my_memcpy(dst, src, strlen(src)+1);
	return s;
}

char *my_memcpy(char *dst, char *src, int cnt) {
	assert((dst != NULL) && (src != NULL));
	char *s = dst;
	// 内存重叠,从高地址开始复制
	if (dst >= src && dst <= src + cnt - 1) {
		dst = dst + cnt - 1;
		src = src + cnt - 1;
		while (cnt --)
			*dst-- = *src--;
	}
	else {
		while (cnt--)
			*dst++ = *src++;
	}
	return s;
}

// 顺便写了strlen, strcat, strcmp
int strlen(const char* str) {
	assert(str != NULL);
	int len = 0;
	while ((*str++) != '\0')
		++len;
	return len;
}

char *strcat(char* dst, const char* src) {
	assert((dst != NULL) && (src != NULL));

	char *s = dst;
	while (dst != '\0')
		++dst;
	while (*dst++ = *src++);
	return s;
}

int strcmp(const char *s1, const char *s2) {
	assert((s1 != NULL) && (s2 != NULL));
	while (*s1 == *s2) {
		if (*s1 == '\0') {
			return 0;
		}
		++s1;
		++s2;
	}
	return *s1 - *s2;
}