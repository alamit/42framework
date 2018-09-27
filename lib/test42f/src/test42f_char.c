/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test42f_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:38:49 by alamit            #+#    #+#             */
/*   Updated: 2018/09/26 18:11:53 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test42f.h"

int		test42f_char_eq(char *title, char c, char expected)
{
	return test42f_int_eq(title, c, expected);
}
int		test42f_char_neq(char *title, char c, char expected)
{
	return test42f_int_neq(title, c, expected);
}
int		test42f_char_lteq(char *title, char c, char expected)
{
	return test42f_int_lteq(title, c, expected);
}
int		test42f_char_gteq(char *title, char c, char expected)
{
	return test42f_int_gteq(title, c, expected);
}
int		test42f_char_lt(char *title, char c, char expected)
{
	return test42f_int_lt(title, c, expected);
}
int		test42f_char_gt(char *title, char c, char expected)
{
	return test42f_int_gt(title, c, expected);
}
