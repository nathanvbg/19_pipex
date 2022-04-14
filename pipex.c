/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:44:00 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/14 17:32:37 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	forking(int n, char **av, char **env, int ac)
{
	int fd[2];
	int pid;
	int fd_in;
	int	i;

	i = 2;
	fd_in = 0;
	while (i < n)
	{
		pipe(fd);
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			if (i == 2)
			{
				fd[0] = open(av[1], O_RDONLY);
				dup2(fd[0], STDIN_FILENO);	
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
			}	
			else if (i + 1 == n)
			{
				dup2(fd_in, STDIN_FILENO);
				int	fd_out = open(av[ac - 1], O_WRONLY | O_TRUNC);
				dup2(fd_out, STDOUT_FILENO);
			}
			else
			{
				dup2(fd_in, STDIN_FILENO);
				dup2(fd[1], STDOUT_FILENO);
			}
			close(fd[0]);
			ft_process(av[i], env);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
			close(fd[1]);
			fd_in = fd[0];
			i++;
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