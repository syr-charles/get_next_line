/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 12:03:38 by cdana             #+#    #+#             */
/*   Updated: 2019/12/31 12:04:31 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	if (*ctnt == 0)
	{
		if (!((*ctnt) = malloc(1)))
			return (-1);
		(*ctnt)[0] = 0;
	}
	if (fd < 0 || fd > OPEN_MAX)
		return (-1);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char		*ctnt[OPEN_MAX];

	if (ft_init(ctnt + fd, line, fd) == -1)
		return (-1);
	if (ft_read(fd, ctnt) == -1)
		return (-1);
	if (ctnt[fd][0] == 0)
	{
		free(ctnt[fd]);
		ctnt[fd] = 0;
		return (0);
	}
	if (ft_cpy_shift(ctnt + fd, line) == -1)
		return (-1);
	return (1);
}
