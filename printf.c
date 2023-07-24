#include "main.h"

void p_buff(char buff[], int *buf_in);
/**
 * _printf - fun1
 * @format: pv1
 * @ ...: pv1
 * Return: num
 */
int _printf(const char *format, ...)
{
	int h, prnt = 0, prnt_cha = 0, flg,
	    wdth, pre_sion, siz, buf_in = 0;
	va_list lst;
	char buff[BUF_S];

	if (format == NULL)
		return (-1);
	va_start(lst, format);
	for (h = 0; format && format[h] != '\0'; h++)
	{
		if (format[h] != '%')
		{
			buff[buf_in++] = format[h];
			if (buf_in == BUF_S)
				p_buff(buff, &buf_in);
			prnt_cha++;
		}
		else
		{
			p_buff(buff, &buf_in);
			flg = gt_flg(format, &h);
			wdth = gt_wdth(format, &h, lst);
			pre_sion = gt_prec(format, &h, lst);
			siz = G_siz(format, &h);
			++h;
			prnt = hdl_pt(format, &h, lst, buff, flg, wdth, pre_sion, siz);
			if (prnt == -1)
				return (-1);
			prnt_cha += prnt;
		}
	}
	p_buff(buff, &buf_in);
	va_end(lst);
	return (prnt_cha);
}
/**
 * p_buff - func2
 * @buff: vp1
 * @buf_in: vp2
 */
void p_buff(char buff[], int *buf_in)
{
	if (*buf_in > 0)
		write(1, &buff[0], *buf_in);
	*buf_in = 0;
}
