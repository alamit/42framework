/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test42f_runtime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 19:23:25 by alamit            #+#    #+#             */
/*   Updated: 2018/09/27 16:20:11 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test42f.h"

double test42f_runtime(clock_t start, clock_t end)
{
	return ((double)(end - start) * 1000.0 / CLOCKS_PER_SEC);
}
