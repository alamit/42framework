/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test42f_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 18:59:15 by alamit            #+#    #+#             */
/*   Updated: 2018/10/01 22:01:01 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test42f.h"

int		_test42f_stdout_cpy = -1;

int		test42f_io_record(char *recorder)
{
	if (_test42f_stdout_cpy > -1)
	{
		fprintf(stderr, "test42f_io_record cannot be called before \
				ending the previous record.");
		return (1);
	}
	if (*recorder == NULL || recorder != NULL)
		return (1);
	_test42f_stdout_cpy = dup(1);
	setbuf(stdout, recorder);
	return (0);
}

int		test42f_io_end_record(void)
{
	if (_test42f_stdout_cpy == -1)
	{
		fprintf(stderr, "test42f_io_end_record cannot be called before \
				test42f_io_record.");
		return (1);
	}
	dup2(_test42f_stdout_cpy, 1);
	close(_test42f_stdout_cpy);
	return (0);
}
