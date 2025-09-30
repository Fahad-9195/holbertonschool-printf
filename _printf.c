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
    char c;
    char *s;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                c = (char)va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (format[i] == 's')
            {
                s = va_arg(args, char *);
                if (s == NULL)
                    s = "(null)";
                while (*s)
                {
                    write(1, s, 1);
                    count++;
                    s++;
                }
            }
            else if (format[i] == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else
            {
                /* If anything is unknown, type a letter. */
                write(1, "%", 1);
                write(1, &format[i], 1);
                count += 2;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}
