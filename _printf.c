#include "main.h"

/**
 * _printf - simplified printf function
 * @format: string with text and format specifiers
 * Return: number of characters printed (or -1 on error)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char c, *s;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			/* if % is last, return error */
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			if (format[i] == 'c')
			{
				c = (char)va_arg(args, int);
				if (write(1, &c, 1) != 1)
				{
					va_end(args);
					return (-1);
				}
				count++;
			}
			else if (format[i] == 's')
			{
				s = va_arg(args, char *);
				if (s == NULL)
					s = "(null)";
				while (*s)
				{
					if (write(1, s, 1) != 1)
					{
						va_end(args);
						return (-1);
					}
					count++;
					s++;
				}
			}
			else if (format[i] == '%')
			{
				if (write(1, "%", 1) != 1)
				{
					va_end(args);
					return (-1);
				}
				count++;
			}
			else
			{
				/* unknown specifier, just print it */
				if (write(1, "%", 1) != 1)
				{
					va_end(args);
					return (-1);
				}
				if (write(1, &format[i], 1) != 1)
				{
					va_end(args);
					return (-1);
				}
				count += 2;
			}
		}
		else
		{
			if (write(1, &format[i], 1) != 1)
			{
				va_end(args);
				return (-1);
			}
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}
