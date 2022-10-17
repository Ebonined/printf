#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int int_print(int b);

typedef struct play
{
	char *t;
	void (*func)(va_list);
} add_in;

void p_int(int b)
{
	int mul = 10;
    while (b > mul)
    {
        /* code */
    }
    
}

void p_char(int b)
{
	write(1, &b, 1);
}

void p_str(char *b)
{
	int i = 0;
	while (b[i])
	{
		write(1, &b, 1);
	}
}

void main()
{
	_printf("char is %c; int is %s", 'D', 20, 90);
	_printf("i", 90);
	_printf("s", "School");
}

int _printf(const char *format, ...)
{
	va_list valist;
	add_in task[] = {
		{"i", p_str, p_int},
		{"c", p_str, p_char},
		{"s", p_str, p_int}};
	int i, j, int_pass;
	char *str_pass;

	// "cis", 's', 3, "ball"

	va_start(valist, format);

	i = 0;
	while (format[i])
	{
		j = 0;
		while (task[j].t)
		{
			if (format[i] == '%' && format[i + 1])
			{
				if (format[i + 1] == *task[j].t)
				{
					task[j].func(valist);
				}
			}
			else if (format[i] == '%' && format[i + 1] == '%')
			{
				/* code */
			}
			
			j++;
		}
		i++;
	}

	va_end(valist);
}
