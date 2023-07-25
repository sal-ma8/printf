#include "main.h"
/**
 * p_hexadi - func3
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
