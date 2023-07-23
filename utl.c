#include "main.h"

/**
 * can_print - show if a char can be printed
 * @a: char to aval .
 *
 * Return: 1 when c is printable, 0 otherwise
 */
int can_print(char a)
{
	if (a >= 32 && a < 127)
		return (1);

	return (0);
}

/**
 * hex_cod - attach ascci code in hexa code to the buffer
 * @buf: char array.
 * @j: start index.
 * @asci_cd: the ascii code.
 * Return:  3
 */
int hex_cod(char asci_cd, char buf[], int j)
{
	char mp_t[] = "0123456789ABCDEF";

	if (asci_cd < 0)
		asci_cd *= -1;

	buf[j++] = '\\';
	buf[j++] = 'x';

	buf[j++] = mp_t[asci_cd / 16];
	buf[j] = mp_t[asci_cd % 16];

	return (3);
}

/**
 * is_dig - Verifies if a char is a digit
 * @a: Char to be evaluated
 *
 * Return: 1 if a is a digit, 0 otherwise
 */
int is_dig(char a)
{
	if (a >= '0' && a <= '9')
		return (1);

	return (0);
}

/**
 * conv_sz_num - deliver a number of a specific size
 * @nu: number to deliver.
 * @sz: A number that indicates the type to be delivered.
 *
 * Return: deliver value of the number
 */
long int conv_sz_num(long int nu, int sz)
{
	if (sz == S_LG)
		return (nu);
	else if (sz == S_SHR)
		return ((short)nu);

	return ((int)nu);
}

/**
 * conv_sz_unsg - deliver a number of a specific size
 * @nu: number to deliver
 * @sz: A number that indicates the type to be delivered
 *
 * Return: deliver value of the number
 */
long int conv_sz_unsg(unsigned long int nu, int sz)
{
	if (sz == S_LG)
		return (nu);
	else if (sz == S_SHR)
		return ((unsigned short)nu);

	return ((unsigned int)nu);
}
