#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * pr_char - Print data type char
 * @ty: the List of args type
 * @buff: Buffer of array to print
 * @flg:  Calculates sum of all flags
 * @w: Width specification
 * @prec: Precision specifier
 * @s: the Size specifier
 * Return: the Number of all chars to be print
 */
int pr_char(va_list ty, char buff[],
	int flg, int w, int prec, int s)
{
	char h = va_arg(ty, int);

	return (hand_wr_char(h, buff, flg, w, prec, s));
}
/************************* PRINT A STRING *************************/
/**
  * pr_string - Prints a type of string
 * @ty: the List of args type
 * @buff: Buffer of array to print
 * @flg:  Calculates sum of all flags
 * @w: Width specification
 * @prec: Precision specifier
 * @s: the Size specifier
 * Return: the Number of all strins to be print
 */
int pr_string(va_list ty, char buff[],
	int flg, int w, int prec, int s)
{
	int l = 0, j;
	char *s = va_arg(ty, char *);

	NOTUSED(buff);
	NOTUSED(flg);
	NOTUSED(w);
	NOTUSED(prec);
	NOTUSED(s);
	if (s == NULL)
	{
		s = "(null)";
		if (prec >= 6)
			s = "      ";
	}

	while (s[l] != '\0')
		l++;

	if (prec >= 0 && prec < l)
		l = prec;

	if (w > l)
	{
		if (flg & F_MIN)
		{
			write(1, &s[0], l);
			for (j = w - l; j > 0; j--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (j = w - l; j > 0; j--)
				write(1, " ", 1);
			write(1, &s[0], l);
			return (w);
		}
	}

	return (write(1, s, l));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * pr_percent - Print data type percent sign
 * @ty: the List of args
 * @buff: Buffer of array to print
 * @flg:  Calculates sum of all flags
 * @w: Width specification
 * @prec: Precision specifier
 * @s: the Size specifier
 * Return: the Number of all chars to be print
 */
int pr_percent(va_list ty, char buff[],
	int flg, int w, int prec, int s)
{
	NOTUSED(ty);
	NOTUSED(buff);
	NOTUSED(flg);
	NOTUSED(w);
	NOTUSED(prec);
	NOTUSED(s);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * pr_int - Print data type integer
 * @ty: the List of args
 * @buff: Buffer of array to print
 * @flg:  Calculates sum of all flags
 * @w: Width specification
 * @prec: Precision specifier
 * @s: the Size specifier
 * Return: the Number of all integers to be print
 */
int pr_int(va_list ty, char buff[],
	int flg, int w, int prec, int s)
{
	int j = BUF_S - 2;
	int negat = 0;
	long int m = va_arg(ty, long int);
	unsigned long int no;

	m = conv_sz_num(n, s);

	if (m == 0)
		buff[j--] = '0';

	buff[BUF_S - 1] = '\0';
	no = (unsigned long int)n;

	if (m < 0)
	{
		no = (unsigned long int)((-1) * m);
		negat = 1;
	}

	while (no > 0)
	{
		buff[j--] = (no % 10) + '0';
		no /= 10;
	}

	j++;

	return (wr_num(negat, j, buff, flg, w, prec, s));
}

/************************* PRINT BINARY *************************/
/**
 * pr_binarynum - Print numbers in binary
 * @ty: the List of args
 * @buff: Buffer of array to print
 * @flg:  Calculates sum of all flags
 * @w: Width specification
 * @prec: Precision specifier
 * @s: the Size specifier
 * Return: the number entered in binary
 */
int pr_binarynum(va_list ty, char buff[],
	int flg, int w, int prec, int s) /*buffer, flags, width, precisions, size*/
{
	unsigned int j, k, l, su;
	unsigned int b[32];
	int c;

	NOTUSED(buff);
	NOTUSED(flg);
	NOTUSED(w);
	NOTUSED(prec);
	NOTUSED(s);

	j = va_arg(ty, unsigned int);
	k = 2147483648; /* (2 ^ 31) */
	b[0] = j / k;
	for (l = 1; l < 32; l++)
	{
		m /= 2;
		b[l] = (j / m) % 2;
	}
	for (l = 0, su = 0, c = 0; l < 32; l++)
	{
		su += b[l];
		if (su || l == 31)
		{
			char x = '0' + b[l];

			write(1, &x, 1);
			c++;
		}
	}
	return (c);
}
