/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:41:42 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/12 18:34:10 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//utils.c
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strdup(char *str);
int		ft_process(char **av, char **env);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

//pipex.c
