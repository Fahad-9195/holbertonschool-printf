#include "main.h"

/**
 * print_number_core - prints a non-negative number in base 10
 * @n: non-negative value (0..)
 * Return: number of printed chars
 */
static int print_number_core(unsigned long n)
{
	char buf[21]; /* enough for 64-bit, but we print int casted to long */
	int i = 0, count = 0;

	if (n == 0)
	{
		char c = '0';

		if (write(1, &c, 1) != 1)
			return (0);
		return (1);
	}

	while (n > 0)
	{
		buf[i++] = (char)('0' + (n % 10));
		n /= 10;
	}

	while (i--)
	{
		if (write(1, &buf[i], 1) != 1)
			return (count);
		count++;
	}
	return (count);
}

/**
 * print_int - prints a signed integer from va_list (%d/%i)
 * @ap: variadic arguments list
 *
 * Return: number of printed chars
 */
int print_int(va_list ap)
{
	long n = (long)va_arg(ap, int);
	int count = 0;
	char minus = '-';

	if (n < 0)
	{
		if (write(1, &minus, 1) != 1)
			return (0);
		count++;
		/* negate via unsigned to safely handle INT_MIN */
		count += print_number_core((unsigned long)(-n));
	}
	else
	{
		count += print_number_core((unsigned long)n);
	}
	return (count);
}
