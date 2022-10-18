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
	write(1, &output, 1);
}

void p_mod(va_list b)
{
	int output = va_arg(b, int);
	write(1, &output, 1);
}

void p_str(va_list b)
{
	int i = 0;
	char *output = va_arg(b, char *);
	while (*(output + i))
	{
		write(1, &output[i], 1);
		i++;
	}
}

void main()
{
	_printf("char is %c; string is %s; and int is %i; just %%", 'D', "STRING", -10022);
}

int _printf(const char *format, ...)
{
	va_list valist;
	char nl = '\n';
	add_in task[] = {
		{"i", p_int},
		{"d", p_int},
		{"c", p_char},
		{"s", p_str},
		{"%", p_mod}};
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
					if (*task[j].t == '%')
						write(1, &(*task[j].t), 1);
					else
						task[j].func(valist);
					i++;
					break;
				}
			}
			else
			{
				write(1, &format[i], 1);
				break;
			}

			j++;
		}
		i++;
	}
	write(1, &nl, 1);
	va_end(valist);
}

int int_print(int b)
{
	int ten = 10;
	int pr = b / ten;
	int out, i, rem, j, remcp, i2;
	int tenin = 10;
	if (b < 0)
	{
		out = '-';
		write(1, &out, 1);
		b = -1 * b;
		pr = b / ten;
	}
	if (b < 10)
	{
		out = (b + '0');
		write(1, &out, 1);

		return (0);
	}
	i = 1;
	while (pr >= ten)
	{
		pr = pr / ten;
		tenin = tenin * 10;
		i++;
	}
	out = (pr + '0');
	write(1, &out, 1);
	rem = b - (pr * tenin);
	remcp = rem;
	if (remcp < 10 && remcp > 0 && i == 1)
	{
		j = 1;
	}
	else if (remcp == 0)
	{
		while (i--)
		{
			int_print(0);
		}
		return (0);
	}
	else
	{
		j = 1;
		while (remcp > 10)
		{
			remcp = remcp / 10;
			j++;
		}
		for (i2 = 0; i2 < (i - j); i2++)
		{
			int_print(0);
		}
	}
	int_print(rem);
}
