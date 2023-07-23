#include "main.h"

/**
 * gt_flg - counts all flags
 * @frmt: a format string to print arguments in
 * @n: parameter to take.
 * Return: flg:
 */
int gt_flg(const char *frmt, int *n)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int k, cur_n;
	int flg = 0;
	const char flg1[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flg2[] = {F_MIN, F_P, F_Z, F_H, F_S, 0};

	for (cur_n = *n + 1; frmt[cur_n] != '\0'; cur_n++)
	{
		for (k = 0; flg1[k] != '\0'; k++)
			if (frmt[cur_n] == flg1[k])
			{
				flg |= flg2[k];
				break;
			}

		if (flg1[k] == 0)
			break;
	}

	*n = cur_n - 1;

	return (flg);
}
