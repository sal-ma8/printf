#include "main.h"
/**
* g_siz - func1
* @f: vp1
* @r: vp2
* Return: num
*/
int g_siz(const char *f, int *r)
{
	int crr = *r + 1;
	int siz = 0;

	if (f[crr] == 'l')
		siz = S_LG;
	else if (f[crr] == 'h')
		siz = S_SHR;
	if (siz == 0)
		*r = crr - 1;
	else
		*r = crr;
	return (siz);
}
