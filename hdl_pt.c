#include "main.h"
/**
 * hdl_p - func1
 * @fma: vp1
 * @lst: vp2
 * @dex: vp3
 * @buff: vp4
 * @flg: vp5
 * @wdth: vp6
 * @pre_sion: vp7
 * @siz: vp8
 * Return: numm
 */
int hdl_p(const char *fma, int *dex, va_list lst,
		char buff[], int flg, int wdth, int pre_sion, int siz)
{
	int h, un_know_l = 0, print_cha = -1;

	fmt_t f_type[]= {
		{'c', pr_char}, {'s', pr_string}, {'%', pr_percent},
                {'i', pr_int}, {'d', pr_int}, {'b', pr_binarynum},
		{'u', p_u_signed}, {'o', p_oct_unsign}, {'x', p_hexadi},
                {'X', p_up_hexa}, {'p', print_pointer}, {'S', print_non_printable},
                {'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
        };
	for (h = 0; f_type[h].fmt != '\0'; h++)
		if (fma[*dex] == f_type[h].fma)
			return (f_type[h].fn(lst, buff, flg, wdth, pre_sion, siz));
	if (f_type[h].fma == '\0')
	{
		if (fma[*dex] == '\0')
			return (-1);
	       un_know_l += write(1, "%%", 1);
		if (fma[*dex - 1] == ' ')
			un_know_l += write(1, " ", 1);
		else if (wdth)
		{
			--(*ind);
			while (fma[*dex] != ' ' && fma[*dex] != '%')
				--(*dex);
			if (fma[*dex] == ' ')
				--(*dex);
			return (1);
		}
		un_know_l += write(1, &fma[*dex], 1);
		return (un_know_l);
	}
	return (print_cha);
}	
