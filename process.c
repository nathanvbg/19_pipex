/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:24:29 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/19 13:36:36 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_process(int fd_0, int fd_1, char *infile)
{
	fd_0 = open(infile, O_RDONLY);
	dup2(fd_0, STDIN_FILENO);
	dup2(fd_1, STDOUT_FILENO);
	close(fd_1);
	return (1);
}

int	last_process(int fd_in, char *outfile)
{
	int	fd_out;

	fd_out = open(outfile, O_WRONLY | O_TRUNC);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	return (1);
}

int	middle_process(int fd_in, int fd_1)
{
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_1, STDOUT_FILENO);
	return (1);
}

int	child_process(t_file x, char **av, int i, int n)
{
	if (i == 2)
		first_process(x.fd[0], x.fd[1], av[1]);
	else if (i + 1 == n)
		last_process(x.fd_in, av[n]);
	else
		middle_process(x.fd_in, x.fd[1]);
	close(x.fd[0]);
	return (1);
}

int	parent_process(t_file x, int *i, int *fd_in)
{
	wait(NULL);
	close (x.fd[1]);
	*fd_in = x.fd[0];
	*i = *i + 1;
	return (1);
}
