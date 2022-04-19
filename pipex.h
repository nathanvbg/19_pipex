/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:41:42 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/19 15:52:53 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct t_file{
	int	fd[2];
	int	fd_in;
	int	fd_out;
	int	pid;
}			t_file;

//utils.c
int		ft_process(char *av, char **env);
char	*ft_strjoin_pipex(char *s1, char *s2);
void	ft_putstr(char *str);
char	*ft_exit(char *msg);
char	**here_doc(char *limiter);

//process.c
int		first_process(int fd_0, int fd_1, char *infile);
int		last_process(int fd_in, char *outfile);
int		middle_process(int fd_in, int fd_1);
int		child_process(t_file x, char **av, int i, int n);
int		parent_process(t_file x, int *i, int *fd_in);

//pipex.c
int		forking(int n, char **av, char **env);
void	ft_free(char *str);

//exec.c
int		ft_exec(char *av, char **env);
char	*ft_getpath(char **env);
char	*check_access(char *full_path, char *cmd);

#endif