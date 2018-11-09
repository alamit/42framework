/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test42f_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:13:48 by alamit            #+#    #+#             */
/*   Updated: 2018/11/09 10:47:55 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test42f.h"

bool	test42f_double_eq(char *title, double nb, double expected)
{
	char	*trace;
	double		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (nb == expected)
	{
		printf("%sSUCCESS: ", KGRN);
		free(trace);
		trace = "";
		res = TRUE;
	}
	else
	{
		printf("%sFAILED:  ", KRED);
		sprintf(trace,
				"%s\tTRACE: %s\"%f\"%s was expected to be %s\"%f\"\n",
				KCYN,
				KRED,
				nb,
				KNRM,
				KGRN,
				expected);
		res = FALSE;
	}
	printf("%s%s \n", KNRM, title);
	printf("%s", trace);
	if (!res)
		free(trace);
	return (res);
}

bool	test42f_double_neq(char *title, double nb, double expected)
{
	char	*trace;
	double		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (nb != expected)
	{
		printf("%sSUCCESS: ", KGRN);
		free(trace);
		trace = "";
		res = TRUE;
	}
	else
	{
		printf("%sFAILED:  ", KRED);
		sprintf(trace,
				"%s\tTRACE: %s\"%f\"%s was expected not to be %s\"%f\"\n",
				KCYN,
				KRED,
				nb,
				KNRM,
				KGRN,
				expected);
		res = FALSE;
	}
	printf("%s%s \n", KNRM, title);
	printf("%s", trace);
	if (!res)
		free(trace);
	return (res);
}

bool	test42f_double_lteq(char *title, double nb, double expected)
{
	char	*trace;
	double		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (nb <= expected)
	{
		printf("%sSUCCESS: ", KGRN);
		free(trace);
		trace = "";
		res = TRUE;
	}
	else
	{
		printf("%sFAILED:  ", KRED);
		sprintf(trace,
				"%s\tTRACE: %s\"%f\"%s was expected to be less than or equal to %s\"%f\"\n",
				KCYN,
				KRED,
				nb,
				KNRM,
				KGRN,
				expected);
		res = FALSE;
	}
	printf("%s%s \n", KNRM, title);
	printf("%s", trace);
	if (!res)
		free(trace);
	return (res);
}

bool	test42f_double_gteq(char *title, double nb, double expected)
{
	char	*trace;
	double		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (nb >= expected)
	{
		printf("%sSUCCESS: ", KGRN);
		free(trace);
		trace = "";
		res = TRUE;
	}
	else
	{
		printf("%sFAILED:  ", KRED);
		sprintf(trace,
				"%s\tTRACE: %s\"%f\"%s was expected to be greater than or equal to %s\"%f\"\n",
				KCYN,
				KRED,
				nb,
				KNRM,
				KGRN,
				expected);
		res = FALSE;
	}
	printf("%s%s \n", KNRM, title);
	printf("%s", trace);
	if (!res)
		free(trace);
	return (res);
}

bool	test42f_double_lt(char *title, double nb, double expected)
{
	char	*trace;
	double		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (nb < expected)
	{
		printf("%sSUCCESS: ", KGRN);
		free(trace);
		trace = "";
		res = TRUE;
	}
	else
	{
		printf("%sFAILED:  ", KRED);
		sprintf(trace,
				"%s\tTRACE: %s\"%f\"%s was expected to be strictly less than %s\"%f\"\n",
				KCYN,
				KRED,
				nb,
				KNRM,
				KGRN,
				expected);
		res = FALSE;
	}
	printf("%s%s \n", KNRM, title);
	printf("%s", trace);
	if (!res)
		free(trace);
	return (res);
}

bool	test42f_double_gt(char *title, double nb, double expected)
{
	char	*trace;
	double		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (nb > expected)
	{
		printf("%sSUCCESS: ", KGRN);
		free(trace);
		trace = "";
		res = TRUE;
	}
	else
	{
		printf("%sFAILED:  ", KRED);
		sprintf(trace,
				"%s\tTRACE: %s\"%f\"%s was expected to be strictly greater than %s\"%f\"\n",
				KCYN,
				KRED,
				nb,
				KNRM,
				KGRN,
				expected);
		res = FALSE;
	}
	printf("%s%s \n", KNRM, title);
	printf("%s", trace);
	if (!res)
		free(trace);
	return (res);
}
