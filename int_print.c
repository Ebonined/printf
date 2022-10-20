#include <unistd.h>


int handle(int remcp, int i, int j, int i2, int buf);

/**
 * int_print - converts integer and print
 *
 * @b: integer to convert
 * Return: int
 */
int int_print(int b, int buf)
{
	int ten = 10;
	int pr = b / ten;
	int out, i, rem, j, remcp, i2;
	int tenin = 10;

	if (b < 0)
	{
		out = '-';
		write(1, &out, 1);
		buf += 1;
		b = -1 * b;
		pr = b / ten;
	}
	if (b < 10)
	{
		out = (b + '0');
		write(1, &out, 1);
		buf += 1;

		return (buf);
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
	buf += 1;
	rem = b - (pr * tenin);
	remcp = rem;
	j = 0;
	i2 = 0;

	buf = handle(remcp, i, j, i2, buf);
	buf = int_print(rem, buf);
	return (buf);
}

/**
 * handle - handles zeros
 *
 * @remcp: remainder value
 * @i: current format index#
 * @j: current index of formated value
 * @i2: secondary index
 *
 * Return: int
 *
 */
int handle(int remcp, int i, int j, int i2, int buf)
{
	if (remcp < 10 && remcp > 0 && i == 1)
	{
		j = 1;
	}
	else if (remcp == 0)
	{
		while (i--)
		{
			buf = int_print(0, buf);
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
			buf = int_print(0, buf);
		}
	}

	return (buf);
}
