#include "main.h"

int _printf(const char *format, ...)
{
	int i = 0;
	va_list print;
	va_start(print, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			*format++;
			/* Handles conversion specifier such as %c,%s,%% */
			if (*format == 'c') /* Handles %c */
			{
				char c = (char)va_arg(print, int);
				_putchar(c);
				i++;
			}
			if (*format == 's') /* Handles %s */
			{
				char *s = va_arg(print, char *);
				while(*s != '\0')
				{
					_putchar(*s);
					s++;
					i++;
				}
			}
			if (*format == '%') /* Handles %% */
			{
				_putchar('%');
				i++;
			}
		}
		else
		{
			_putchar(*format);
			i++;
		}
		*format++;
	}
	va_end(print);
	return(i);
}

