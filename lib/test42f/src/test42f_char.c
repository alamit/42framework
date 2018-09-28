/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test42f_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:38:49 by alamit            #+#    #+#             */
/*   Updated: 2018/09/28 05:25:40 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test42f.h"

bool	test42f_char_eq(char *title, char c, char expected)
{
	return test42f_int_eq(title, c, expected);
}
bool	test42f_char_neq(char *title, char c, char expected)
{
	return test42f_int_neq(title, c, expected);
}
bool	test42f_char_lteq(char *title, char c, char expected)
{
	return test42f_int_lteq(title, c, expected);
}
bool	test42f_char_gteq(char *title, char c, char expected)
{
	return test42f_int_gteq(title, c, expected);
}
bool	test42f_char_lt(char *title, char c, char expected)
{
	return test42f_int_lt(title, c, expected);
}
bool	test42f_char_gt(char *title, char c, char expected)
{
	return test42f_int_gt(title, c, expected);
}
