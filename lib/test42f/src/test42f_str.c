/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test42f_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:25:32 by alamit            #+#    #+#             */
/*   Updated: 2018/10/02 14:01:12 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test42f.h"

bool	test42f_str_eq(char *title, char *str, char *expected)
{
	char	*trace;
	int		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (!strcmp(str, expected))
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
				"%s\tTRACE: %s\"%s\"%s was expected to be %s\"%s\"\n",
				KCYN,
				KRED,
				str,
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

bool	test42f_str_neq(char *title, char *str, char *expected)
{
	char	*trace;
	int		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (strcmp(str, expected))
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
				"%s\tTRACE: %s\"%s\"%s was expected not to be %s\"%s\"\n",
				KCYN,
				KRED,
				str,
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

bool	test42f_str_lteq(char *title, char *str, char *expected)
{
	char	*trace;
	int		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (strcmp(str, expected) <= 0)
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
				"%s\tTRACE: %s\"%s\"%s was expected to be less than or equal to (lexicographically) %s\"%s\"\n",
				KCYN,
				KRED,
				str,
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

bool	test42f_str_gteq(char *title, char *str, char *expected)
{
	char	*trace;
	int		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (strcmp(str, expected) >= 0)
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
				"%s\tTRACE: %s\"%s\"%s was expected to be greater than or equal (lexicographically) %s\"%s\"\n",
				KCYN,
				KRED,
				str,
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

bool	test42f_str_lt(char *title, char *str, char *expected)
{
	char	*trace;
	int		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (strcmp(str, expected) < 0)
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
				"%s\tTRACE: %s\"%s\"%s was expected to be strictly less than (lexicographically) %s\"%s\"\n",
				KCYN,
				KRED,
				str,
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

bool	test42f_str_gt(char *title, char *str, char *expected)
{
	char	*trace;
	int		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (strcmp(str, expected) > 0)
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
				"%s\tTRACE: %s\"%s\"%s was expected to be strictly greater than (lexicographically) %s\"%s\"\n",
				KCYN,
				KRED,
				str,
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
