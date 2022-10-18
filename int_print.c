#include <unistd.h>


int handle(int remcp, int i, int j, int i2);

/**
 * int_print - converts integer and print
 *
 * @b: integer to convert
 * Return: int
 */
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
	j = 0;
	i2 = 0;

	handle(remcp, i, j, i2);
	int_print(rem);
	return (0);
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
int handle(int remcp, int i, int j, int i2)
{
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

	return (0);
}
