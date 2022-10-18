#ifndef _MAIN_H_
#define _MAIN_H_

int _printf(const char *format, ...);

/**
 * struct play - play struct for selecting function
 *
 * @t: character format
 * @func0: function member
 * @func1: function 1 for handling other char printing
 */
typedef struct play
{
	char *t;
	void (*func0)(va_list);
	void (*func1)(char);
} add_in;

#endif /* _MAIN_H_ */