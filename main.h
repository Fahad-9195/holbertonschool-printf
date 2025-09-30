#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - simplified printf function
 * @format: format string
 * Return: number of chars printed or -1 on error
 */
int _printf(const char *format, ...);

#endif
