/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test42f_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 02:58:13 by alamit            #+#    #+#             */
/*   Updated: 2018/09/28 05:29:20 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test42f.h"

bool	test42f_ptr_eq(char *title, void *ptr, void *expected)
{
	char	*trace;
	int		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (ptr == expected)
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
				"%s\tTRACE: %s\"%p\"%s was expected to be %s\"%p\"\n",
				KCYN,
				KRED,
				ptr,
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

bool	test42f_ptr_neq(char *title, void *ptr, void *expected)
{
	char	*trace;
	int		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (ptr != expected)
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
				"%s\tTRACE: %s\"%p\"%s was expected not to be %s\"%p\"\n",
				KCYN,
				KRED,
				ptr,
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
