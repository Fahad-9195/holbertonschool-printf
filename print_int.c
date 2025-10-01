#include "main.h"

/**
 * print_int - print a signed decimal integer from va_list
 * @ap: argument list (must provide an int)
 *
 * Return: number of printed characters, or -1 on error
 */
int print_int(va_list ap)
{
	long n, m;
	char buf[20];
	int idx = 0, written = 0;
	char sign = 0;

	n = (long)va_arg(ap, int);

	if (n < 0)
	{
		sign = '-';
		m = -n; /* long يمنع overflow عند INT_MIN */
	}
	else
	{
		m = n;
	}

	/* الحالة صفر */
	if (m == 0)
		buf[idx++] = '0';

	/* خزّن الأرقام معكوسة */
	while (m > 0)
	{
		buf[idx++] = (char)('0' + (m % 10));
		m /= 10;
	}

	/* اطبع الإشارة إن وجدت */
	if (sign)
	{
		if (write(1, &sign, 1) == -1)
			return (-1);
		written++;
	}

	/* اطبع الأرقام بالترتيب الصحيح */
	while (idx > 0)
	{
		idx--;
		if (write(1, &buf[idx], 1) == -1)
			return (-1);
		written++;
	}

	return (written);
}
