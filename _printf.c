#include "main.h"

/**
 * print_char - prints one char
 * @c: character
 * Return: 1 on success, -1 on error
 */
int print_char(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

/**
 * print_string - prints a string (NULL -> "(null)")
 * @s: string
 * Return: chars printed, -1 on error
 */
int print_string(const char *s)
{
	int n = 0;

	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		if (write(1, s, 1) != 1)
			return (-1);
		n++;
		s++;
	}
	return (n);
}

/**
 * handle_specifier - handles %c, %s, %%
 * @ap: va_list pointer
 * @sp: specifier
 * Return: chars printed, -1 on error
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
	if (print_char(sp) == -1)
		return (-1);
	return (2);
}

/**
 * process_percent - processes a % sequence starting at format[*i]
 * @format: format string
 * @i: index (will be advanced)
 * @ap: va_list pointer
 * Return: chars printed, or -1 on error
 */
static int process_percent(const char *format, int *i, va_list *ap)
{
	int r;

	(*i)++;
	if (format[*i] == '\0')
		return (-1);
	r = handle_specifier(ap, format[*i]);
	if (r == -1)
		return (-1);
	(*i)++;
	return (r);
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
		r = process_percent(format, &i, &ap);
		if (r == -1)
		{
			va_end(ap);
			return (-1);
		}
		total += r;
	}
	va_end(ap);
	return (total);
}
