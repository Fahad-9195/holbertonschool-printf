#include "main.h"

/**
 * _printf - a simple version of printf (subset: c, s, %, d, i)
 * @format: the string with text and format specifiers
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;

			if (format[i] == 'c')
			{
				char c = (char)va_arg(args, int);

				if (write(1, &c, 1) != 1)
				{
					va_end(args);
					return (-1);
				}
				count++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				int j = 0;

				if (!str)
					str = "(null)";
				while (str[j] != '\0')
				{
					if (write(1, &str[j], 1) != 1)
					{
						va_end(args);
						return (-1);
					}
					count++;
					j++;
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
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int printed = print_int(args);

				if (printed < 0)
				{
					va_end(args);
					return (-1);
				}
				count += printed;
			}
			else
			{
				/* Unknown specifier: print it verbatim as "%x" */
				if (write(1, "%", 1) != 1 ||
				    write(1, &format[i], 1) != 1)
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
