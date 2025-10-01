#include "main.h"

/**
 * _printf - simplified printf: supports %c, %s, %%, %d, %i
 * @format: format string
 *
 * Return: number of printed characters, or -1 on error
 *
 * Rules for this project:
 * - format == NULL => -1 (no output)
 * - Trailing '%' (like "%") => -1 (no output)
 * - Unknown specifier => print '%' then that character (like printf)
 * - %s with NULL => "(null)"
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(ap, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			if (write(1, &format[i], 1) == -1)
			{
				va_end(ap);
				return (-1);
			}
			count++;
			i++;
			continue;
		}

		/* وجدنا '%' */
		i++;
		/* Trailing '%' => خطأ حسب مصحّح المشروع */
		if (format[i] == '\0')
		{
			va_end(ap);
			return (-1);
		}

		if (format[i] == 'c')
		{
			char c = (char)va_arg(ap, int);

			if (write(1, &c, 1) == -1)
			{
				va_end(ap);
				return (-1);
			}
			count++;
		}
		else if (format[i] == 's')
		{
			char *s = va_arg(ap, char *);
			int j = 0;

			if (!s)
				s = "(null)";
			while (s[j] != '\0')
			{
				if (write(1, &s[j], 1) == -1)
				{
					va_end(ap);
					return (-1);
				}
				count++;
				j++;
			}
		}
		else if (format[i] == '%')
		{
			if (write(1, "%", 1) == -1)
			{
				va_end(ap);
				return (-1);
			}
			count++;
		}
		else if (format[i] == 'd' || format[i] == 'i')
		{
			int printed = print_int(ap);

			if (printed < 0)
			{
				va_end(ap);
				return (-1);
			}
			count += printed;
		}
		else
		{
			/* Unknown specifier: اطبع '%' ثم الرمز */
			if (write(1, "%", 1) == -1 || write(1, &format[i], 1) == -1)
			{
				va_end(ap);
				return (-1);
			}
			count += 2;
		}
		i++;
	}

	va_end(ap);
	return (count);
}
