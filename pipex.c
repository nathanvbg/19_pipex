/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:44:00 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/13 16:59:50 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_access(char *full_path, char *cmd)
{
	char	*path;
	size_t		i;

	i = 0;
	while (i < ft_strlen(full_path))
	{
		path = ft_strjoin_pipex(&full_path[i], "/");
		i += ft_strlen(path);
		path = ft_strjoin_pipex(path, cmd);
		if (access(path, 0) == 0)
			return (path);
	}
	return (NULL);
}

char	*ft_getpath(char **env)
{
	int	i;
	char *path;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			path = ft_strdup(env[i]);
		i++;
	}
	return (path);
}

int	ft_process(char **av, char **env, int n)
{
	char	*full_path;
	char	*path;
	char 	**arr;
	
	full_path = ft_getpath(env);
	arr = ft_split(av[n], ' ');
	path = check_access(&full_path[5], arr[0]);
	//printf("path = %s\n", path);
	//char* 	arr[] = {path, NULL};
	//printf("1 = %s\n2 = %s\n", arr[0], arr[1]);
	execve(path, arr, env);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	int fd[2];
	int pid1;
	int pid2;
	
	printf("\n\n");
	ac = 4;
	if (pipe(fd) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 < 0)
		return (-1);
	if (pid1 == 0)
	{
		fd[0] = open(av[1], O_RDONLY);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_process(av, env, 2);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (-1);
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		int	fd_out = open(av[4], O_WRONLY);
		//printf("fd_out = %d\nav[4] = %s\n", fd_out, av[4]);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		ft_process(av, env, 3);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}




		//char buf[100];
		//int ret = read(fd[0], &buf, 100);
		//buf[ret] = '\0';
		//printf("buf = |%s|\n", buf);