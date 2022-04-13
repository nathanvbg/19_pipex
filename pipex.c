/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:44:00 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/13 15:22:47 by naverbru         ###   ########.fr       */
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

int	ft_process(char **av, char **env)
{
	char	*full_path;
	char	*path;
	char 	**arr;
	
	(void)av[0];
	full_path = ft_getpath(env);
	arr = ft_split(av[2], ' ');
	path = check_access(&full_path[5], arr[0]);
	printf("path = %s\n", path);
	//char* 	arr[] = {path, NULL};
	//printf("1 = %s\n2 = %s\n", arr[0], arr[1]);
	execve(path, arr, env);

	return (1);
}

int	main(int ac, char **av, char **env)
{
	int		fd_in;
	int		fd_out;
	
	if (ac == 1)
	{
		printf("No arguments");
		return (0);
	}
	fd_in = open(av[1], O_RDONLY);
	fd_out = open(av[4], O_WRONLY);
	dup2(fd_in, 0);
	close(fd_in);
	ft_process(av, env);
	return (0);
}