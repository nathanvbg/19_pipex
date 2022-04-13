/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:41:42 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/13 16:04:22 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

//utils.c
int		ft_process(char **av, char **env, int n);
char	*ft_strjoin_pipex(char *s1, char *s2);

//pipex.c
