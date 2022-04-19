/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:37:32 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/19 14:51:16 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_access(char *full_path, char *cmd)
{
	char	*path;
	size_t	i;

	i = 0;
	while (i < ft_strlen(full_path))
	{
		path = ft_strjoin_pipex(&full_path[i], "/");
		if (!path)
			return (ft_exit("error"));
		i += ft_strlen(path);
		path = ft_strjoin_pipex(path, cmd);
		if (!path)
			return (ft_exit("error"));
		if (access(path, 0) == 0)
			return (path);
	}
	return (ft_exit("no path"));
}

char	*ft_getpath(char **env)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			path = ft_strdup(env[i]);
			if (!path)
				return (ft_exit("Allocation error"));
			return (path);
		}
		i++;
	}
	return (ft_exit("error, no full_path"));
}

int	ft_exec(char *av, char **env)
{
	char	*full_path;
	char	*path;
	char	**arr;

	full_path = NULL;
	arr = NULL;
	full_path = ft_getpath(env);
	if (!full_path)
		return (-1);
	arr = ft_split(av, ' ');
	if (!arr)
		return (-1);//ft_exit(full_path));
	path = check_access(&full_path[5], arr[0]);
	//ft_free(full_path, arr);
	if (!path)
	{
		return (-1);
	}
	printf("\n000\n");
	execve(path, arr, env);
	printf("\n111\n");
	return (1);
}
