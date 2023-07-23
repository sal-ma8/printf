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
int p_u_signed(va_list type, char buff[], int flg, int wdth, int pre_sion, int siz)
{
	int h = BUFF_SIZE - 2;
        unsigned long int numb = va_arg(type, unsigned long int);

	numb = convert_size_unsgnd(numb, siz);
        if (numb == 0)
                buff[h--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (numb > 0)
        {
		buff[h--] = (numb % 10) + '0';
                numb /= 10;
	}
	h++;
	return (write_unsgnd(0, h, buff, flg, wdth, pre_sion, siz));
}
/**
 * p_oct_unsign - func1
 * @type: vp1
 * @buff: vp2
 * @flg:  vp3
 * @wdth: vp4
 * @pre_sion: vp5
 * @siz: vp6
 * Return: numm
 */

int p_oct_unsign(va_list type, char buff[],int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);
        unsigned long int init_num = num;

	UNUSED(width);
        num = convert_size_unsgnd(num, size);
        if (num == 0)
                buffer[i--] = '0';
        buffer[BUFF_SIZE - 1] = '\0';
        while (num > 0)
        {
		buffer[i--] = (num % 8) + '0';
                num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

int print_hexadecimal(va_list types, char buffer[],

        int flags, int width, int precision, int size)

{

        return (print_hexa(types, "0123456789abcdef", buffer,

                flags, 'x', width, precision, size));

}


/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/

/**

 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation

 * @types: Lista of arguments

 * @buffer: Buffer array to handle print

 * @flags:  Calculates active flags

 * @width: get width

 * @precision: Precision specification

 * @size: Size specifier

 * Return: Number of chars printed

 */

int print_hexa_upper(va_list types, char buffer[],

        int flags, int width, int precision, int size)

{

        return (print_hexa(types, "0123456789ABCDEF", buffer,

                flags, 'X', width, precision, size));

}


/************** PRINT HEXX NUM IN LOWER OR UPPER **************/

/**

 * print_hexa - Prints a hexadecimal number in lower or upper

 * @types: Lista of arguments

 * @map_to: Array of values to map the number to

 * @buffer: Buffer array to handle print

 * @flags:  Calculates active flags

 * @flag_ch: Calculates active flags

 * @width: get width

 * @precision: Precision specification

 * @size: Size specifier

 * @size: Size specification

 * Return: Number of chars printed

 */

int print_hexa(va_list types, char map_to[], char buffer[],

        int flags, char flag_ch, int width, int precision, int size)

{

        int i = BUFF_SIZE - 2;

        unsigned long int num = va_arg(types, unsigned long int);

        unsigned long int init_num = num;


        UNUSED(width);


        num = convert_size_unsgnd(num, size);


        if (num == 0)

                buffer[i--] = '0';


        buffer[BUFF_SIZE - 1] = '\0';


        while (num > 0)

        {

                buffer[i--] = map_to[num % 16];

                num /= 16;

        }


        if (flags & F_HASH && init_num != 0)

        {

                buffer[i--] = flag_ch;

                buffer[i--] = '0';

        }


        i++;


        return (write_unsgnd(0, i, buffer, flags, width, precision, size));

}

