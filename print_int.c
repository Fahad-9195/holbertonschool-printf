#include "main.h"
#include <unistd.h>

int print_int(va_list ap)
{
	long n = va_arg(ap, int);
	char buf[12];
	int i = 0, count = 0;

	if (n == 0)
		return (write(1, "0", 1) == 1 ? 1 : -1);

	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		n = -n;
	}

	while (n > 0)
	{
		buf[i++] = (char)('0' + (n % 10));
		n /= 10;
	}

	while (i--)
	{
		if (write(1, &buf[i], 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}
