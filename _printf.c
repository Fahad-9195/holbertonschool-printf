#include "main.h"

/**
 * _printf - a simple version of printf
 * @format: the string with text and format specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int count = 0;
    char c;

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
                char *str = va_arg(args, char *);
                int j = 0;

                if (str == NULL)
                    str = "(null)";
                while (str[j] != '\0')
                {
                    write(1, &str[j], 1);
                    count++;
                    j++;
                }
            }
            else if (format[i] == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else
            {
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
