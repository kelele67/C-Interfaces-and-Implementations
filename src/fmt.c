#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <math.h>
#include "assert.h"
#include "except.h"
#include "fmt.h"
#include "mem.h"
#define T Fmt_T
struct buf {
	char *buf;
	char *bp;
	int size;
};
#define pad(n, c) do { int nn = (n); \
	while (nn-- > 0) \
		put((c), cl); } while (0)
static void cvt_s(int code, va_list_box *box,
	int put(int c, void *cl), void *cl,
	unsigned char flags[], int width, int precision) {
	char *str = va_arg(box->ap, char *);
	assert(str);
	Fmt_puts(str, strlen(str), put, cl, flags, width, precision);
}
static void cvt_d(int code, va_list_box *box,
	int put(int c, void *cl), void *cl,
	unsigned char flags[], int width, int precision) {
	int val = va_arg(box->ap, int);
	unsigned m;
	char buf[43];
	char *p = buf + sizeof(buf);
	if (val == INT_MIN)
		m = INT_MIN + 1U;
	else if (val < 0)
		m = -val;
	else
		m = val;
	do
		*--p = '-';
	Fmt_putd(p, (buf + sizeof(buf)) - p, put, cl, flags, width, precision);
}
static void cvt_u(int code, va_list_box *box,
	int put(int c, void *cl), void *cl,
	unsigned char flags[], int width, int precision) {
	unsigned m = va_arg(box->ap, unsigned);
	char buf[43];
	char *p = buf + sizeof(buf);
	do
		*--p = m%10 + '0';
	while ((m /= 10) > 0);
	Fmt_putd(p, (buf + sizeof(buf)) - p, put, cl, flags, width, precision)
}