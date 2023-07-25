#include "main.h"
/**
 * hdl_p - func1
 * @sct: vp1
 * @lst: vp2
 * @dex: vp3
 * @buff: vp4
 * @flg: vp5
 * @wdth: vp6
 * @pre_sion: vp7
 * @siz: vp8
 * Return: numm
 */
int hdl_p(const char *sct, int *dex, va_list lst,
		char buff[], int flg, int wdth, int pre_sion, int siz)
{
	int h, un_know_l = 0, print_cha = -1;

	sct_c f_type[] = {
		{'c', pr_char}, {'s', pr_string}, {'%', pr_percent},
		{'i', pr_int}, {'d', pr_int}, {'b', pr_binarynum},
		{'u', p_u_signed}, {'o', p_oct_unsign}, {'x', p_hexadi},
		{'X', p_up_hexa}, {'p', p_point}, {'S', pt_n_pble},
		{'r', pri_res}, {'R', p_rot_13}, {'\0', NULL}
	};
	for (h = 0; f_type[h].sct != '\0'; h++)
		if (sct[*dex] == f_type[h].sct)
			return (f_type[h].fs(lst, buff, flg, wdth, pre_sion, siz));
	if (f_type[h].sct == '\0')
	{
		if (sct[*dex] == '\0')
			return (-1);
	       un_know_l += write(1, "%%", 1);
		if (sct[*dex - 1] == ' ')
			un_know_l += write(1, " ", 1);
		else if (wdth)
		{
			--(*dex);
			while (sct[*dex] != ' ' && sct[*dex] != '%')
				--(*dex);
			if (sct[*dex] == ' ')
				--(*dex);
			return (1);
		}
		un_know_l += write(1, &sct[*dex], 1);
		return (un_know_l);
	}
	return (print_cha);
}
