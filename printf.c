#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int int_print(int b);

/**
 * p_int - print integer values
 *
 * @b: va_list type sent to function
 */
void p_int(va_list b)
{
	int output = va_arg(b, int);

	int_print(output);
}

/**
 * p_char - print character values
 *
 * @b: va_list type sent to function
 */
void p_char(va_list b)
{
	int output = va_arg(b, int);

	write(1, &output, 1);
}

/**
 * p_mod - print mod `%` character values
 *
 * @b: char type sent to function
 */
void p_mod(char b)
{
	write(1, &b, 1);
}

/**
 * p_str - print string values
 *
 * @b: va_list type sent to function
 */
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

/**
 * _printf - funtion for print formating
 * @format: string containing actual strings and format printing arguments
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	va_list valist;
	char nl = '\n';
	char count = 0;
	add_in task[] = {
		{"i", p_int, p_mod},
		{"d", p_int, p_mod},
		{"c", p_char, p_mod},
		{"s", p_str, p_mod},
		{"%", p_char, p_mod}};
	int i, j;

	if (format == NULL)
		return (-1);

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
						task[j].func1('%');
					else
						task[j].func0(valist);
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
		count++;
		i++;
	}
	write(1, &nl, 1);
	va_end(valist);

	return (count);
}
