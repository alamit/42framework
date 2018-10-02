/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test42f_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 18:59:15 by alamit            #+#    #+#             */
/*   Updated: 2018/10/01 23:32:39 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test42f.h"

int		_test42f_stdout_cpy = -1;
char	*_test42f_io_tape = NULL;
int		test42f_io_start_record()
{
	if (_test42f_stdout_cpy > -1)
	{
		fprintf(stderr, "test42f_io_record cannot be called before \
				ending the previous record.");
		return (1);
	}
	_test42f_io_tape = malloc(BUFSIZ);
	fflush(stdout);
	_test42f_stdout_cpy = dup(1);
	freopen("NUL", "a", stdout);
	setbuf(stdout, _test42f_io_tape);
	return (0);
}

int		test42f_io_end_record(char **tape)
{
	if (_test42f_stdout_cpy == -1)
	{
		fprintf(stderr, "test42f_io_end_record cannot be called before \
				test42f_io_record.");
		return (1);
	}
	*tape = strdup(_test42f_io_tape);
	freopen("NUL", "a", stdout);
	dup2(_test42f_stdout_cpy, 1);
	fflush(stdout);
	setbuf(stdout, NULL);
	close(_test42f_stdout_cpy);
	_test42f_io_tape = NULL;
	return (0);
}
