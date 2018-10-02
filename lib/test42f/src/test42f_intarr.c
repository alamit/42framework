/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test42f_intarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:26:43 by alamit            #+#    #+#             */
/*   Updated: 2018/10/02 13:55:09 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test42f.h"

char	*test42f_intarr2str(size_t size, int *arr)
{
	char	*res;
	char	*rtn;
	size_t	i;

	res = malloc((2 * size + 1) * sizeof(char));
	if (res == NULL) 
		return NULL;
	rtn = res;
	res[0] = '[';
	++res;
	i = 0;
	while (i < size)
	{
		*res = arr[i] + '0';
		res++;
		if (i != size - 1)
		{
			*res = ',';
			res++;
		}
		++i;
	}
	*res = ']';
	*(res + 1) = '\0';
	return (rtn);
}

bool	test42f_intarr_eq(char *title, size_t size, int *arr, int *expected)
{
	int		res;
	char	*arr1;
	char	*arr2;

	arr1 = test42f_intarr2str(size, arr);
	arr2 = test42f_intarr2str(size, expected);

	res = test42f_str_eq(title, arr1, arr2);
	free(arr1);
	free(arr2);
	return (res);
}

bool	test42f_intarr_neq(char *title, size_t size, int *arr, int *expected)
{
	int		res;
	char	*arr1;
	char	*arr2;

	arr1 = test42f_intarr2str(size, arr);
	arr2 = test42f_intarr2str(size, expected);

	res = test42f_str_neq(title, arr1, arr2);
	free(arr1);
	free(arr2);
	return (res);
}
