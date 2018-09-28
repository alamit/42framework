/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test42f_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 19:44:54 by alamit            #+#    #+#             */
/*   Updated: 2018/09/27 16:18:41 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test42f.h"

char	*test42f_new_str(char *str)
{
	char *res;
	
	res = malloc(sizeof(str));
	return (strcpy(res, str));
}

int		*test42f_new_intarr(int size, ...)
{
	va_list args;
	int		*res;
	int		i;

	res = malloc(size * sizeof(int));
	va_start(args, size);
	i = 0;
	while (i < size)
	{
		*(res + i) = va_arg(args, int);
		i++;
	}
	va_end(args);
	return (res);
}
