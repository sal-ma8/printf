#include "main.h"

/**
 * gt_prec - Calculates precision to print
 * @frmt: Format string to print the argu in it
 * @li0: the List of all the args to print.
 * @li1: list of args.
 *
 * Return: prs.
 */
int gt_prec(const char *frmt, int *li0, va_list li1)
{
	int cr_li = *li0 + 1;
	int prs = -1;

	if (frmt[cr_li] != '.')
		return (prs);

	prs = 0;

	for (cr_li += 1; frmt[cr_li] != '\0'; cr_li++)
	{
		if (is_dig(frmt[cr_li]))
		{
			prs *= 10;
			prs += frmt[cr_li] - '0';
		}
		else if (frmt[cr_li] == '*')
		{
			curr_i++;
			prs = va_arg(li1, int);
			break;
		}
		else
			break;
	}

	*li0 = cr_li - 1;

	return (prs);
}
