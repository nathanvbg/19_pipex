/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:44:00 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/13 12:28:22 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_access(char *full_path, char *cmd)
{
	char	*path;
	int		i;

	i = 0;
	while (i < ft_strlen(full_path))
	{
		path = ft_strjoin(&full_path[i], "/");
		i += ft_strlen(path);
		path = ft_strjoin(path, cmd);
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
	//printf("%s\n", path);
	return (path);
}

int	ft_process(char **av, char **env)
{
	char	*full_path;
	char	*path;
	
	(void)av[0];
	full_path = ft_getpath(env);
	path = check_access(&full_path[5], av[2]);
	printf("path = %s\n", path);
	if (access("/bin/cd", 0) == 0)
		printf("ok\n");
	return (1);
}

int	main(int ac, char **av, char **env)
{
	int		fd;

	int		i;
	
	if (ac == 1)
	{
		printf("No arguments");
		return (0);
	}
	i = 0;
	fd = open(av[1], O_RDONLY);
	ft_process(av, env);
	return (0);
}





	//char 	buf[1000];
	//int		ret;
	//char* 	arr[] = {"pwd", NULL};

	/*ret = read(fd, &buf, 1000);
	buf[ret] = '\0';
	path = ft_getpath()
	close(fd);*/
	//execve("/bin/pwd", arr, env);