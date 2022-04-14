/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:30:01 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/14 17:43:44 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**here_doc(char *limiter)
{
	char	**tab = 0;
	int		i;
	int 	ret;
	char	buf[100];

	i = 0;
	while (i < 100)
	{
		ret = read(0, &buf, 10);
		buf[ret] = '\0';
		printf("buf = %s", buf);
		if (ft_strncmp(limiter, buf, ft_strlen(limiter)) == 0)
		{
			printf("termine");
			break ;
		}
		i++;
	}
	return (tab);	
}