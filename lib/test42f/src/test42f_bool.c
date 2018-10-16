/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test42f_bool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:28:43 by alamit            #+#    #+#             */
/*   Updated: 2018/09/28 05:25:06 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test42f.h"

bool	test42f_bool_eq(char *title, int boolean, int expected)
{
	char	*trace;
	int		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (!boolean == !expected)
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
				boolean,
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

bool	test42f_bool_neq(char *title, int boolean, int expected)
{
	char	*trace;
	int		res;

	trace = malloc(INIT_STR_LEN * sizeof(char));

	if (!boolean != !expected)
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
				boolean,
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