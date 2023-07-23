#include "main.h"
/**
* get_size - func1
* @format: vp1
* @i: vp2
* Return: num
*/
int g_siz(const char *format, int *r)
{
	int crr = *r + 1;
	int siz = 0;

	if (format[crr] == 'l')
		siz = S_LONG;
	else if (format[crr] == 'h')
		siz = S_SHORT;
	if (siz == 0)
		*r = crr - 1;
	else
		*r = crr;
	return (siz);
}
