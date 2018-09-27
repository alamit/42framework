/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test42f.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:19:40 by alamit            #+#    #+#             */
/*   Updated: 2018/09/26 20:24:34 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include <stdarg.h>
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define TRUE 1
#define FALSE 0
#define INIT_STR_LEN 4096

int		test42f_str_eq(char *title, char *str, char *expected);
int		test42f_str_neq(char *title, char *str, char *expected);
int		test42f_str_lteq(char *title, char *str, char *expected);
int		test42f_str_gteq(char *title, char *str, char *expected);
int		test42f_str_lt(char *title, char *str, char *expected);
int		test42f_str_gt(char *title, char *str, char *expected);

int		test42f_int_eq(char *title, int nbr, int expected);
int		test42f_int_neq(char *title, int nbr, int expected);
int		test42f_int_lteq(char *title, int nbr, int expected);
int		test42f_int_gteq(char *title, int nbr, int expected);
int		test42f_int_lt(char *title, int nbr, int expected);
int		test42f_int_gt(char *title, int nbr, int expected);

int		test42f_char_eq(char *title, char c, char expected);
int		test42f_char_neq(char *title, char c, char expected);
int		test42f_char_lteq(char *title, char c, char expected);
int		test42f_char_gteq(char *title, char c, char expected);
int		test42f_char_lt(char *title, char c, char expected);
int		test42f_char_gt(char *title, char c, char expected);

/* New type functions returns dynamically allocated variables, they 
 * should be freed.*/
int		test42f_bool_eq(char *title, int boolean, int expected);
int		test42f_bool_neq(char *title, int boolean, int expected);

char	*test42f_new_str(char *str);
int		*test42f_new_intarr(int size, ...);

double	test42f_runtime(clock_t start, clock_t end);
