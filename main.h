#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - formatted output to stdout (subset)
 * @format: format string
 * Return: number of printed chars, or -1 on error
 */
int _printf(const char *format, ...);

/**
 * print_int - prints a signed integer from va_list (%d/%i)
 * @ap: variadic arguments list
 * Return: number of printed chars
 */
int print_int(va_list ap);

#endif /* MAIN_H */
