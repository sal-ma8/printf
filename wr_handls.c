#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Prints a string
 * @a: char type.
 * @buf: Buffer array to handle print
 * @flg: countactive flags.
 * @wd:  width.
 * @prc: precision
 * @sz: Size specification
 *
 * Return: Number of chars printed.
 */
int hand_wr_char(char a, char buf[],
	int flg, int wd, int prc, int sz)
{ /* char is stored at left and paddind at buffer's right */
	int j = 0;
	char pd = ' ';

	NOTUSED(prc);
	NOTUSED(sz);

	if (flg & F_Z)
		pd = '0';

	buf[j++] = a;
	buf[j] = '\0';

	if (wd > 1)
	{
		buf[BUF_S - 1] = '\0';
		for (j = 0; j < wd - 1; j++)
			buf[BUF_S - j - 2] = pd;

		if (flg & F_MIN)
			return (write(1, &buf[0], 1) +
					write(1, &buf[BUF_S - j - 1], wd - 1));
		else
			return (write(1, &buf[BUF_S - j - 1], wd - 1) +
					write(1, &buf[0], 1));
	}

	return (write(1, &buf[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * wr_num - print string of numb
 * @is_ngv: arguments list
 * @id: types of char.
 * @buf: array pf buffer to handle print
 * @flg:  counts flags
 * @wd: specify width.
 * @prec: specify precision
 * @sz: specify Size
 *
 * Return: chars printed.
 */
int wr_num(int is_ngv, int id, char buf[],
	int flg, int wd, int prec, int sz)
{
	int len = BUF_S - id - 1;
	char pd = ' ', ex_ch = 0;

	NOTUSED(sz);

	if ((flg & F_Z) && !(flg & F_MIN))
		pd = '0';
	if (is_ngv)
		ex_ch = '-';
	else if (flg & F_P)
		ex_ch = '+';
	else if (flg & F_S)
		ex_ch = ' ';

	return (wr_numb(id, buf, flg, wd, prec,
		len, pd, ex_ch));
}

/**
 * wr_numb - write number with a buffer
 * @id: the starting number of buffer index
 * @buf: Buffer
 * @flg: Flag
 * @wd: width
 * @prec: specify Precision
 * @len: length
 * @pd: Pad char
 * @ex_ch: Extra charcter
 *
 * Return: printed chars.
 */
int wr_numb(int id, char buf[],
	int flg, int wd, int prec,
	int len, char pd, char ex_ch)
{
	int j, pd_str = 1;

	if (prec == 0 && id == BUF_S - 2 && buf[id] == '0' && wd == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && id == BUF_S - 2 && buf[id] == '0')
		buf[id] = pd = ' '; /* wd is displayed with padding ' ' */
	if (prec > 0 && prec < len)
		pd = ' ';
	while (prec > len)
		buf[--id] = '0', len++;
	if (ex_ch != 0)
		len++;
	if (wd > len)
	{
		for (j = 1; j < wd - len + 1; j++)
			buf[j] = pd;
		buf[j] = '\0';
		if (flg & F_MIN && pd == ' ')/* Asign extra char to left of buffer */
		{
			if (ex_ch)
				buf[--id] = ex_ch;
			return (write(1, &buf[id], len) + write(1, &buf[1], j - 1));
		}
		else if (!(flg & F_MIN) && pd == ' ')/* extra char to left of buff */
		{
			if (ex_ch)
				buf[--id] = ex_ch;
			return (write(1, &buf[1], j - 1) + write(1, &buf[id], len));
		}
		else if (!(flg & F_MIN) && pd == '0')/* extra char to left of padd */
		{
			if (ex_ch)
				buf[--pd_str] = ex_ch;
			return (write(1, &buf[pd_str], j - pd_str) +
				write(1, &buf[id], len - (1 - pd_str)));
		}
	}
	if (ex_ch)
		buf[--id] = ex_ch;
	return (write(1, &buf[id], len));
}

/**
 * wr_unsind - write unsigned num
 * @is_ngv: is num negative?
 * @id: the starting number of buffer index
 * @buf: chars array
 * @flg: Flags
 * @wd: Width
 * @prec: Precision
 * @sz: Size
 *
 * Return: written chars num
 */
int wr_unsind(int is_ngv, int id,
	char buf[],
	int flg, int wd, int prec, int sz)
{
	/* The number is stored at the bufer's right and starts at position i */
	int len = BUF_S - id - 1, j = 0;
	char pd = ' ';

	NOTUSED(is_ngv);
	NOTUSED(sz);

	if (prec == 0 && id == BUF_S - 2 && buf[id] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (prec > 0 && prec < len)
		pd = ' ';

	while (prec > len)
	{
		buf[--id] = '0';
		len++;
	}

	if ((flg & F_Z) && !(flg & F_MIN))
		pd = '0';

	if (wd > len)
	{
		for (j = 0; j < wd - len; j++)
			buf[j] = pd;

		buf[j] = '\0';

		if (flg & F_MIN) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buf[id], len) + write(1, &buf[0], j));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buf[0], j) + write(1, &buf[id], len));
		}
	}

	return (write(1, &buf[id], len));
}

/**
 * wr_ptr - Write a memory address
 * @buf: Arrays of chars
 * @id: Index at which the number starts in the buffer
 * @len: Length of number
 * @wd: Wwidth specifier
 * @flg: Flags specifier
 * @pd: Char representing the padding
 * @ex_ch: Char representing extra char
 * @pd_strt: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int wr_ptr(char buf[], int id, int len,
	int wd, int flg, char pd, char ex_ch, int pd_strt)
{
	int j;

	if (wd > len)
	{
		for (j = 3; j < wd - len + 3; j++)
			buf[j] = pd;
		buf[j] = '\0';
		if (flg & F_MIN && pd == ' ')/* Asign extra char to left of buffer */
		{
			buf[--id] = 'x';
			buf[--id] = '0';
			if (ex_ch)
				buf[--id] = ex_ch;
			return (write(1, &buf[id], len) + write(1, &buf[3], j - 3));
		}
		else if (!(flg & F_MIN) && pd == ' ')/* extra char to left of buffer */
		{
			buf[--id] = 'x';
			buf[--id] = '0';
			if (ex_ch)
				buf[--id] = ex_ch;
			return (write(1, &buf[3], j - 3) + write(1, &buf[id], len));
		}
		else if (!(flg & F_MIN) && pd == '0')/* extra char to left of padd */
		{
			if (ex_ch)
				buf[--pd_strt] = ex_ch;
			buf[1] = '0';
			buf[2] = 'x';
			return (write(1, &buf[pd_strt], j - pd_strt) +
				write(1, &buf[id], len - (1 - pd_strt) - 2));
		}
	}
	buf[--id] = 'x';
	buf[--id] = '0';
	if (ex_ch)
		buf[--id] = ex_ch;
	return (write(1, &buf[id], BUF_S - id - 1));
}

