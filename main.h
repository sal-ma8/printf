#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


#define NOTUSED(y) (void)(y) /*UNUSED*/
#define BUF_S 1024 /*BUFF_SIZE*/

/* FLAGS */
#define F_MIN 1 /*F_MINUS*/
#define F_P 2 /*F_PLUS*/
#define F_Z 4 /*F_ZERO*/
#define F_H 8 /*F_HASH*/
#define F_S 16 /*F_SPACE*/

/* SIZES */
#define S_LG 2 /*S_LONG*/
#define S_SHR 1 /*S_SHORT*/








/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int pr_char(va_list ty, char buff[],
	int flg, int w, int prec, int s);
int pr_string(va_list ty, char buff[],
	int flg, int w, int prec, int s);
int pr_percent(va_list ty, char buff[],
	int flg, int w, int prec, int s);

/* Functions to print numbers */
int pr_int(va_list ty, char buff[],
	int flg, int w, int prec, int s);
int pr_binarynum(va_list ty, char buff[],
	int flg, int w, int prec, int s);




/* Funciotns to handle other specifiers */
int gt_flg(const char *frmt, int *n);
int gt_wdth(const char *frmt, int *li0, va_list li1);
int gt_prec(const char *frmt, int *li0, va_list li1);


/************** width handler ****************8*/
int hand_wr_char(char a, char buf[],
	int flg, int wd, int prc, int sz);
	/*int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)*/

int wr_num(int is_ngv, int id, char buf[],
	int flg, int wd, int prec, int sz);
/*int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);*/

int wr_numb(int id, char buf[],
	int flg, int wd, int prec,
	int len, char pd, char ex_ch);
/*int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);*/

int wr_ptr(char buf[], int id, int len,
	int wd, int flg, char pd, char ex_ch, int pd_strt)
/*int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);*/

int wr_unsind(int is_ngv, int id,
	char buf[],
	int flg, int wd, int prec, int sz)
/*int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);*/








/****************** UTILS ******************/
int can_print(char); /*is_printable*/
int hex_cod(char, char[], int); /*append_hexa_code*/
int is_dig(char); /*is_digit*/

long int conv_sz_num(long int nu, int sz); /*convert_size_number*/
long int conv_sz_unsg(unsigned long int nu, int sz); /*convert_size_unsgnd*/

#endif /* MAIN_H */
