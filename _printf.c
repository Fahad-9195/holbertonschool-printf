#include "main.h"
#include <unistd.h>

static int write_char(char c)
{
	return (write(1, &c, 1) == 1 ? 1 : -1);
}

static int write_str(const char *s)
{
	int k = 0;

	while (s && s[k])
	{
		if (write(1, &s[k], 1) == -1)
			return (-1);
		k++;
	}
	return (k);
}

static int print_unknown(char spec)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (write_char(spec));
}

static int handle_spec(va_list ap, char spec)
{
	if (spec == 'c')
		return (write_char((char)va_arg(ap, int)));
	if (spec == 's')
	{
		char *s = va_arg(ap, char *);

		if (!s)
			s = "(null)";
		return (write_str(s));
	}
	if (spec == '%')
		return (write_char('%'));
	if (spec == 'd' || spec == 'i')
		return (print_int(ap));
	return (print_unknown(spec));
}

int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, total = 0, n = 0;

	if (!format)
		return (-1);

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			if (write_char(format[i]) == -1)
			{
				total = -1;
				break;
			}
			total++;
			i++;
			continue;
		}
		i++;
		if (!format[i]) /* trailing '%' */
		{
			total = -1;
			break;
		}
		n = handle_spec(ap, format[i]);
		if (n < 0)
		{
			total = -1;
			break;
		}
		total += n;
		i++;
	}
	va_end(ap);
	return (total);
}
