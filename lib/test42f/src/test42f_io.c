/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test42f_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 18:59:15 by alamit            #+#    #+#             */
/*   Updated: 2018/11/08 17:51:13 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test42f.h"

static int		stdout_bkp = -1;
static int		pipefd[2];

int				test42f_io_start_record()
{
	if (stdout_bkp > -1)
	{
		fprintf(stderr,
			"test42f_io_record can't be used before ending previous record.\n");
		return (1);
	}
	stdout_bkp = dup(fileno(stdout));
	pipe(pipefd);
	dup2(pipefd[1], fileno(stdout));
	return (0);
}

int				test42f_io_end_record(char *buf, size_t bufsize)
{
	if (stdout_bkp == -1)
	{
		fprintf(stderr,
			"test42f_io_end_record cannot be used before test42f_io_record.\n");
		return (1);
	}
	fflush(stdout);
	write(pipefd[1], "", 1);
	close(pipefd[1]);
	dup2(stdout_bkp, fileno(stdout));
	read(pipefd[0], buf, bufsize);
	stdout_bkp = -1;
	return (0);
}
