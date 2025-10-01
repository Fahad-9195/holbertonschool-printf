#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* printf clone (subset) */
int _printf(const char *format, ...);

/* print a signed decimal integer read from va_list */
int print_int(va_list ap);

#endif /* MAIN_H */
