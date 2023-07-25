#include "main.h"
/**
 * p_point - func1
 * @type: vp1
 * @buff: vp2
 * @flg:  vp3
 * @wdth: vp4
 * @pre_sion: vp5
 * @siz: vp6
 * Return: numm
 */
int p_point(va_list type, char buff[],
		int flg, int wdth, int pre_sion, int siz)
{
	char ext_ra = 0, pad = ' ';
	int dex = BUF_S - 2, lenth = 2, pad_one = 1;
	unsigned long nm_addr;
	char map[] = "0123456789abcdef";
	void *addr = va_arg(type, void *);

	NOTUSED(wdth);
	NOTUSED(siz);
	if (addr == NULL)
		return (write(1, "(nil)", 5));
	buff[BUF_S - 1] = '\0';
	NOTUSED(pre_sion);
	nm_addr = (unsigned long)addr;
	while (nm_addr > 0)
	{
		buff[dex--] = map[nm_addr % 16];
		nm_addr /= 16;
		lenth++;
	}
	if ((flg & F_Z) && !(flg & F_MIN))
		pad = '0';
	if (flg & F_P)
		ext_ra = '+', lenth++;
	else if (flg & F_S)
		ext_ra = ' ', lenth++;
	dex++;
	return (wr_ptr(buff, dex, lenth,
				wdth, flg, pad, ext_ra, pad_one));
}
/**
 * pt_n_pble - func2
 * @type: vp1
 * @buff: vp2
 * @flg:  vp3
 * @wdth: vp4
 * @pre_sion: vp5
 * @siz: vp6
 * Return: numm
 */
int pt_n_pble(va_list type, char buff[],
		int flg, int wdth, int pre_sion, int siz)
{
	int h = 0, opps = 0;
	char *sr = va_arg(type, char *);

	NOTUSED(flg);
	NOTUSED(wdth);
	NOTUSED(pre_sion);
	NOTUSED(siz);
	if (sr == NULL)
		return (write(1, "(null)", 6));
	while (sr[h] != '\0')
	{
		if (can_print(sr[h]))
			buff[h + opps] = sr[h];
		else
			opps += hex_cod(sr[h], buff, h + opps);
		h++;
	}
	buff[h + opps] = '\0';
	return (write(1, buff, h + opps));
}
/**
 * pri_res - func3
 * @type: vp1
 * @buff: vp2
 * @flg:  vp3
 * @wdth: vp4
 * @pre_sion: vp5
 * @siz: vp6
 * Return: numm
 */
int pri_res(va_list type, char buff[],
		int flg, int wdth, int pre_sion, int siz)
{
	char *ps;
	int h, cout = 0;

	NOTUSED(buff);
	NOTUSED(flg);
	NOTUSED(wdth);
	NOTUSED(siz);

	ps = va_arg(type, char *);
	if (ps == NULL)
	{
		NOTUSED(pre_sion);
		ps = ")Null(";
	}
	for (h = 0; ps[h]; h++)
		;
	for (h = h - 1; h >= 0; h--)
	{
		char m = ps[h];

		write(1, &m, 1);
		cout++;
	}
	return (cout);
}
/**
 * p_rot_13 - func4
 * @type: vp1
 * @buff: vp2
 * @flg:  vp3
 * @wdth: vp4
 * @pre_sion: vp5
 * @siz: vp6
 * Return: numm
 */
int p_rot_13(va_list type, char buff[],
		int flg, int wdth, int pre_sion, int siz)
{
	char s, *ps;
	unsigned int h, n;
	int cout = 0;
	char b[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char g[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	ps = va_arg(type, char *);
	NOTUSED(buff);
	NOTUSED(flg);
	NOTUSED(wdth);
	NOTUSED(pre_sion);
	NOTUSED(siz);

	if (ps == NULL)
		ps = "(AHYY)";
	for (h = 0; ps[h]; h++)
	{
		for (n = 0; g[n]; n++)
		{
			if (g[n] == ps[h])
			{
				s = b[n];
				write(1, &s, 1);
				cout++;
				break;
			}
		}
		if (!g[n])
		{
			s = ps[h];
			write(1, &s, 1);
			cout++;
		}
	}
	return (cout);
}
