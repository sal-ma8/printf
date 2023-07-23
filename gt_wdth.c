#include "main.h"

/**
 * gt_wdth - counts the width to print
 * @frmt: a format string to print arguments in.
 * @li0: a list of all arguments to be printed.
 * @li1: a list for arguments.
 *
 * Return: wd.
 */
int gt_wdth(const char *frmt, int *li0, va_list li1)
{
	int cur_n;
	int wd = 0;

	for (cur_n = *li0 + 1; frmt[cur_n] != '\0'; cur_n++)
	{
		if (is_digit(frmt[cur_n]))
		{
			wd *= 10;
			wd += frmt[cur_n] - '0';
		}
		else if (frmt[cur_n] == '*')
		{
			cur_n++;
			wd = va_arg(li1, int);
			break;
		}
		else
			break;
	}

	*li0 = cur_n - 1;

	return (wd);
}
