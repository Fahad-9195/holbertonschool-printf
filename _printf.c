#include "main.h"

/**
 * print_char - prints one char
 * @c: character
 * Return: 1 on success, -1 on write error
 */
int print_char(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

/**
 * print_string - prints a C string (handles NULL)
 * @s: string
 * Return: number of chars, -1 on write error
 */
int print_string(const char *s)
{
	int cnt = 0;

	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		if (write(1, s, 1) != 1)
			return (-1);
		cnt++;
		s++;
	}
	return (cnt);
}

/**
 * handle_specifier - handles %c, %s, %%
 * @ap: va_list pointer
 * @sp: specifier char
 * Return: chars printed or -1 on error
 */
int handle_specifier(va_list *ap, char sp)
{
	if (sp == 'c')
	{
		char c = (char)va_arg(*ap, int);

		return (print_char(c));
	}
	if (sp == 's')
	{
		char *str = va_arg(*ap, char *);

		return (print_string(str));
	}
	if (sp == '%')
		return (print_char('%'));

	/* unknown specifier, just print it */
	if (print_char('%') == -1)
		return (-1);
	return (print_char(sp) == -1 ? -1 : 2);
}

/**
 * _printf - simplified printf
 * @format: format string
 * Return: number of printed chars, -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, total = 0, r;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			if (print_char(format[i]) == -1)
			{
				va_end(ap);
				return (-1);
			}
			total++;
			i++;
			continue;
		}

		i++;
		if (format[i] == '\0')
		{
			va_end(ap);
			return (-1);
		}

		r = handle_specifier(&ap, format[i]);
		if (r == -1)
		{
			va_end(ap);
			return (-1);
		}
		total += r;
		i++;
	}

	va_end(ap);
	return (total);
}
