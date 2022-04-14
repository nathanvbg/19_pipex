/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:44:00 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/14 15:03:26 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
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

int	last_process(char **av, char **env, int *fd)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	int	fd_out = open(av[4], O_WRONLY | O_TRUNC);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	ft_process(av, env, 3);
	return (1);
}

int middle_process(char **av, char **env, int *fd)
{

}
*/
int	forking(int n, char **av, char **env)
{
	int fd[2];
	int pid;
	int fd_in;
	int	i;

	i = 2;
	fd_in = 0;
	while (i < n)
	{
		if (av[0] == NULL && env[0] == NULL)
			return (0);
		pipe(fd);
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			printf("hello\n");
			dup2(fd_in, STDIN_FILENO);
			if (i + 1 != n)
				dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			ft_process(av[i], env);
			//execlp(av[i], av[i] , NULL);
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("non\n");
			wait(NULL);
			close(fd[1]);
			fd_in = fd[0];
			i++;
		}
	}
	return (1);
}
/*
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
*/
int	main(int ac, char **av, char **env)
{
	forking(ac - 1, av, env);
	ac = 4;

	return (0);
}

/*


		if (i = 0)
		{
			if (pid == 0)
				first_process(av, env, fd);
		}
		if (i = n - 1)
		{
			if (pid == 0)
				last_process(av, env, fd);
		}
		else 
		{
			if (pid == 0)
		}
		*/