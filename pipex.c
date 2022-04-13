/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:44:00 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/13 17:46:31 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_process(char **av, char **env, int *fd)
{
	fd[0] = open(av[1], O_RDONLY);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);	
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	ft_process(av, env, 2);
	return (1);
}

int	second_process(char **av, char **env, int *fd)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	int	fd_out = open(av[4], O_WRONLY);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	ft_process(av, env, 3);
	return (1);
}

int	forking(char **av, char **env)
{
	int fd[2];
	int pid1;
	int pid2;

	if (pipe(fd) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 < 0)
		return (-1);
	if (pid1 == 0)
		if (first_process(av, env, fd) != 1)
			return(-1);	
	pid2 = fork();
	if (pid2 < 0)
		return (-1);
	if (pid2 == 0)
		if (second_process(av, env, fd) != 1)
			return (-1);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	forking(av, env);
	ac = 4;

	return (0);
}