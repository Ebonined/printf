#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>


int _printf(const char *format, ...)
{
int count = 0;
va_list prints;
va_start (prints, format);

for(int i = 0; format[i] != '/0';)
{ 
	if (format[i} != '%')
        {  
           _putchar(format[i])
           i++;
           count ++;
	}
	else if (format[i] == '%')
	{ switch (format[i + 1])
	case 'c':
	_putchar(va_arg(prints, int);
	break;
	case 's':
	-putchar(va_arg(prints, char*);
	break;
	case '%':
	_putchar('%');
	break;
	default;
	break;
        i++;
	count++;
	}
}
return (count);
