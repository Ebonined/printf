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

void p_int(va_list b)
{
	int output = va_arg(b, int);
	int_print(output);
}


void p_char(va_list b)
{
	int output = va_arg(b, int);
	putchar(output);
}

void p_str(va_list b)
{
	char *output = va_arg(b, char *);
	printf("%s", output);
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
		{"i", p_int},
		{"c", p_char},
		{"s", p_str}};
	int i, j;

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

int int_print(int b)
{
	int ten = 10;
	int pr = b / ten;
	int out, temp, to, times;
	int tenin = 10;

	times = 0;
	if (b < 10)
	{
		out = (b + '0');
		times++;
		write(1, &out, 1);
		return (0);
	}
	temp = 10;
	while (temp)
	{
		temp = temp * 10;
		if (b == temp)
			break;
		if (b / temp < 1)
		{
			temp = temp / 10;
			break;
		}
	}
	if (temp < b)
	{
		while (pr > ten)
		{
			pr = pr / ten;
			tenin = tenin * 10;
		}
		out = (pr + '0');
		to = b - (pr * tenin);
		write(1, &out, 1);
	}
	else if (temp == b)
	{
		for (i = 0; i < times; i++)
		{
			/* code */
		}
		
		out = (pr + '0');
		to = b - (pr * tenin);
		write(1, &out, 1);
	}

	int_print(to);
}
