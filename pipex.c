/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:44:00 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/19 15:15:59 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char *str)
{
	if (str != NULL)
		free(str);
	str = NULL;
}

int	forking(int n, char **av, char **env)
{
	t_file	x;
	int		i;

	i = 2;
	x.fd_in = 0;
	while (i < n)
	{
		if (pipe(x.fd) == -1)
			return (-1);
		x.pid = fork();
		if (x.pid < 0)
			return (-1);
		if (x.pid == 0)
		{
			if (!child_process(x, av, i, n))
				return (-1);
			if (!ft_exec(av[i], env))
				return (-1);
		}
		else
			if (!parent_process(x, &i, &x.fd_in))
				return (-1);
	}
	return (1);
}

int	main(int ac, char **av, char **env)
{
	char	**here;

	if (ft_strncmp("here_doc", av[1], 8) == 0)
		here = here_doc("limiter");
	else
		forking(ac - 1, av, env);
	return (0);
}
