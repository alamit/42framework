/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test42f_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:29:49 by alamit            #+#    #+#             */
/*   Updated: 2018/09/28 05:28:40 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test42f.h"

bool	test42f_int_eq(char *title, int nb, int expected)
{
	char	*trace;
	int		res;

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
				"%s\tTRACE: %s\"%i\"%s was expected to be %s\"%i\"\n",
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

bool	test42f_int_neq(char *title, int nb, int expected)
{
	char	*trace;
	int		res;

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
				"%s\tTRACE: %s\"%i\"%s was expected not to be %s\"%i\"\n",
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

bool	test42f_int_lteq(char *title, int nb, int expected)
{
	char	*trace;
	int		res;

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
				"%s\tTRACE: %s\"%i\"%s was expected to be less than or equal to %s\"%i\"\n",
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

bool	test42f_int_gteq(char *title, int nb, int expected)
{
	char	*trace;
	int		res;

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
				"%s\tTRACE: %s\"%i\"%s was expected to be greater than or equal to %s\"%i\"\n",
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

bool	test42f_int_lt(char *title, int nb, int expected)
{
	char	*trace;
	int		res;

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
				"%s\tTRACE: %s\"%i\"%s was expected to be strictly less than %s\"%i\"\n",
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

bool	test42f_int_gt(char *title, int nb, int expected)
{
	char	*trace;
	int		res;

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
				"%s\tTRACE: %s\"%i\"%s was expected to be strictly greater than %s\"%i\"\n",
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
