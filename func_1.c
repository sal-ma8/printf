#include "main.h"
/**
 * p_u_sign - func1
 * @type: vp1
 * @buff: vp2
 * @flg:  vp3
 * @wdth: vp4
 * @pre_sion: vp5
 * @siz: vp6
 * Return: numm
 */
int p_u_signed(va_list type, char buff[], int flg,
		int wdth, int pre_sion, int siz)
{
	int h = BUF_S - 2;
	unsigned long int numb = va_arg(type, unsigned long int);

	numb = conv_sz_unsg(numb, siz);
	if (numb == 0)
		buff[h--] = '0';
	buff[BUF_S - 1] = '\0';
	while (numb > 0)
	{
		buff[h--] = (numb % 10) + '0';
		numb /= 10;
	}
	h++;
	return (wr_unsind(0, h, buff, flg, wdth, pre_sion, siz));
}
/**
 * p_oct_unsign - func2
 * @type: vp1
 * @buff: vp2
 * @flg:  vp3
 * @wdth: vp4
 * @pre_sion: vp5
 * @siz: vp6
 * Return: numm
 */
int p_oct_unsign(va_list type, char buff[], int flg,
		int wdth, int pre_sion, int siz)
{
	int t = BUF_S - 2;
	unsigned long int numb = va_arg(type, unsigned long int);
	unsigned long int strt_nm = numb;

	NOTUSED(wdth);
	numb = conv_sz_unsg(numb, siz);
	if (numb == 0)
		buff[t--] = '0';
	buff[BUF_S - 1] = '\0';
	while (numb > 0)
	{
		buff[t--] = (numb % 8) + '0';
		numb /= 8;
	}
	if (flg & F_H && strt_nm != 0)
		buff[t--] = '0';
	t++;
	return (wr_unsind(0, t, buff, flg, wdth, pre_sion, siz));
}
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
int p_hexadi(va_list type, char buff[],
		int flg, int wdth, int pre_sion, int siz)
{
	return (p_hexa(type, "0123456789abcdef",
				buff, flg, 'x', wdth, pre_sion, siz));
}
/*
 * p_up_hexa - func3
 * @type: vp1
 * @buff: vp2
 * @flg: vp3
 * @wdth: vp4
 * @pre_sion: vp5
 * @siz: vp6
 * Return: numm
 */
int p_up_hexa(va_list type, char buff[], int flg,
		int wdth, int pre_sion, int siz)
{
	return (p_hexa(type, "0123456789ABCDEF",
				buff, flg, 'X', wdth, pre_sion, siz));
}
/**
 * print_hexa - func4
 * @type: vp1
 * @buff: vp2
 * @flg:  vp3
 * @wdth: vp4
 * @pre_sion: vp5
 * @siz: vp6
 * @m_to: vp7
 * @flg_ch: vp8
 * Return: numm
 */
int p_hexa(va_list type, char m_to[], char buff[],
		int flg, char flg_ch, int wdth, int pre_sion, int siz)
{
	int s = BUF_S - 2;
	unsigned long int numb = va_arg(type, unsigned long int);
	unsigned long int strt_nm = numb;

	NOTUSED(wdth);
	numb = conv_sz_unsg(numb, siz);
	if (numb == 0)
		buff[s--] = '0';
	buff[BUF_S - 1] = '\0';
	while (numb > 0)
	{
		buff[s--] = m_to[numb % 16];
		numb /= 16;
	}
	if (flg & F_H && strt_nm != 0)
	{
		buff[s--] = flg_ch;
		buff[s--] = '0';
	}
	s++;
	return (wr_unsind(0, s, buff, flg, wdth, pre_sion, siz));
}
