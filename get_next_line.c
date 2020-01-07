/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:39:06 by cdana             #+#    #+#             */
/*   Updated: 2020/01/07 18:00:46 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
static int	ft_init(char **ctnt, char **line, int fd)
{
	if (line == 0 || ctnt == 0)
		return (-1);
	if (*line)
		*line = 0;
	if (!(*line = malloc(1)))
		return (-1);
	(*line)[0] = 0;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	if (*ctnt == 0)
	{
		if (!((*ctnt) = malloc(1)))
			return (-1);
		(*ctnt)[0] = 0;
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char		*ctnt[OPEN_MAX];
	int				ret;

	if (ft_init(ctnt + fd, line, fd) == -1)
		return (-1);
	if (ft_read(fd, ctnt) == -1)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	ret = ft_cpy_shift(ctnt + fd, line);
	if (ret == 0)
	{
		free(ctnt[fd]);
		ctnt[fd] = NULL;
	}
	printf("ret:%d ctnt$%s$\n", ret, ctnt[fd]);
	return (ret);
}
