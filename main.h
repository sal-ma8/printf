#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>












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
int prec(const char *fo, int *li0, va_list li1);


#endif /* MAIN_H */
