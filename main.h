#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
int handle_specifier(va_list *ap, char sp);
int print_char(char c);
int print_string(const char *s);

#endif
