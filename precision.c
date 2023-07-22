#include "main.h"

/**
 * prec - Calculates precision to print
 * @fo: Format string to print the argu in it
 * @li0: the List of all the args to print.
 * @li1: list of args.
 *
 * Return: prs.
 */
int prec(const char *fo, int *li0, va_list li1)
{
	int cr_li = *li0 + 1;
	int prs = -1;

	if (format[cr_li] != '.')
		return (prs);

	prs = 0;

	for (cr_li += 1; fo[cr_li] != '\0'; cr_li++)
	{
		if (is_digit(fo[cr_li]))
		{
			prs *= 10;
			prs += fo[cr_li] - '0';
		}
		else if (fo[cr_li] == '*')
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
