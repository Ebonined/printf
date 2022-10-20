#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int int_print(int b, int buf);

/**
 * p_int - print integer values
 * @b: va_list type sent to function
 *
 * Return: int
 */
int p_int(va_list b)
{
	int buf = 0;
	int output = va_arg(b, int);

	buf = int_print(output, buf);

	return (buf);
}

/**
 * p_char - print character values
 * @b: va_list type sent to function
 *
 * Return: int
 */
int p_char(va_list b)
{
	int output = va_arg(b, int);

	write(1, &output, 1);

	return (1);
}

/**
 * p_mod - print mod `%` character values
 * @b: char type sent to function
 *
 * Return: int
 */
int p_mod(char b)
{
	write(1, &b, 1);

	return (1);
}

/**
 * p_str - print string values
 * @b: va_list type sent to function
 *
 * Return: int
 */
int p_str(va_list b)
{
	int i = 0;
	char *output = va_arg(b, char *);

	while (*(output + i))
	{
		write(1, &output[i], 1);
		i++;
	}

	return (i);
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
	int count = 0;
	int buf = 0;
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
					{
						buf = task[j].func1('%');
						count++;
					}
					else
					{
						buf = task[j].func0(valist);
						count += buf;
					}
					i++;
					break;
				}
			}
			else
			{
				write(1, &format[i], 1);
				count++;
				break;
			}

			j++;
		}
		i++;
	}
	va_end(valist);

	return (count);
}
