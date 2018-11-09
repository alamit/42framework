/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test42f_runtime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 19:23:25 by alamit            #+#    #+#             */
/*   Updated: 2018/11/09 10:50:24 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test42f.h"

double test42f_runtime(void (*f)(void))
{
	clock_t start;
	clock_t end;

	start = clock();
	f();
	end = clock();
	return ((double)(end - start) / CLOCKS_PER_SEC);
}
