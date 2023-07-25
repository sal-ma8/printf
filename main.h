#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


#define NOTUSED(y) (void)(y)
#define BUF_S 1024

/* FLAGS */
#define F_MIN 1
#define F_P 2
#define F_Z 4
#define F_H 8
#define F_S 16

/* SIZES */
#define S_LG 2
#define S_SHR 1


/******************************************/
/**
 * struct sct - up
 * @sct: The format.
 * @fs: The function associated.
 */
struct sct
{
	char sct;
	int (*fs)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct sct sct_c - up
 * @sct: vp1
 * @sct_c: vp2
 */
typedef struct sct sct_c;
int _printf(const char *format, ...);
int hdl_p(const char *fma, int *dex, va_list lst,
	char buff[], int flg, int wdth, int pre_sion, int siz);


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
int p_u_signed(va_list type, char buff[],
		int flg, int wdth, int pre_sion, int siz);
int p_oct_unsign(va_list type, char buff[],
		int flg, int wdth, int pre_sion, int siz);
int p_hexadi(va_list type, char buff[],
		int flg, int wdth, int pre_sion, int siz);
int p_up_hexa(va_list type, char buff[],
		int flg, int wdth, int pre_sion, int siz);
int p_hexa(va_list type, char m_to[], char buff[],
		int flg, char flg_ch, int wdth, int pre_sion, int siz);
int pt_n_pble(va_list type, char buff[],
		int flg, int width, int pre_sion, int siz);
int p_point(va_list type, char buff[],
		int flg, int wdth, int pre_sion, int siz);
int gt_flg(const char *frmt, int *n);
int gt_wdth(const char *frmt, int *li0, va_list li1);
int gt_prec(const char *frmt, int *li0, va_list li1);
int g_siz(const char *f, int *r);
int pri_res(va_list type, char buff[],
		int flg, int wdth, int pre_sion, int siz);
int p_rot_13(va_list type, char buff[],
		int flg, int wdth, int pre_sion, int siz);

/************** width handler ****************8*/
int hand_wr_char(char a, char buf[],
	int flg, int wd, int prc, int sz);
int wr_num(int is_ngv, int id, char buf[],
	int flg, int wd, int prec, int sz);
int wr_numb(int id, char buf[],
	int flg, int wd, int prec,
	int len, char pd, char ex_ch);
int wr_ptr(char buf[], int id, int len,
		int wd, int flg, char pd, char ex_ch, int pd_strt);
int wr_unsind(int is_ngv, int id,
	char buf[],
	int flg, int wd, int prec, int sz);

/****************** UTILS ******************/
int can_print(char);
int hex_cod(char, char[], int);
int is_dig(char);
long int conv_sz_num(long int nu, int sz);
long int conv_sz_unsg(unsigned long int nu, int sz);

/****************************/
void p_buff(char buff[], int *buf_in);
#endif /* MAIN_H */
