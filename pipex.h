/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:41:42 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/19 12:40:21 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct t_file{
	int fd[2];
	int fd_in;
	int fd_out;
	int pid;
}			t_file;

//utils.c
int		ft_process(char *av, char **env);
char	*ft_strjoin_pipex(char *s1, char *s2);
void	ft_putstr(char *str);
char	*ft_exit(char *msg);

char	**here_doc(char *limiter);

//pipex.c
