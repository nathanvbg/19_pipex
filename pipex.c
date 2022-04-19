/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:44:00 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/19 13:06:00 by naverbru         ###   ########.fr       */
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
	int fd_out;

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

int	child_process(t_file x, char **av, int i, int n, int ac)
{
	if (i == 2)
		first_process(x.fd[0], x.fd[1], av[1]);
	else if (i + 1 == n)
		last_process(x.fd_in, av[ac - 1]);
	else
		middle_process(x.fd_in, x.fd[1]);
	close(x.fd[0]);
	return (1);
}

int	parent_process(t_file x, int *i)
{
	close (x.fd[1]);
	//x.fd_in = x.fd[0];
	*i = *i + 1;
	return (1);
}

int	forking(int n, char **av, char **env, int ac)
{
	t_file x;
	int	i;
	
	i = 2;
	x.fd_in = 0;
	while (i < n)
	{
		pipe(x.fd);
		x.pid = fork();
		if (x.pid == -1)
			return (-1);
		if (x.pid == 0)
		{
			child_process(x, av, i, n, ac);
			ft_process(av[i], env);
		}
		else
		{
			wait(NULL);
			parent_process(x, &i);
			//close(x.fd[1]);
			x.fd_in = x.fd[0];
			//i++;
		}
	}
	return (1);
}

int	main(int ac, char **av, char **env)
{
	char **here;

	if (ft_strncmp("here_doc", av[1], 8) == 0)
		here = here_doc("limiter");
	else
		forking(ac - 1, av, env, ac);
	return (0);
}