/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:39:06 by cdana             #+#    #+#             */
/*   Updated: 2019/12/31 11:16:26 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_init(char **ctnt, char **line)
{
	if (line == 0 || ctnt == 0)
		return (-1);
	if (*(line) != 0)
	{
		*line = 0;
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

	if (fd < 0 || fd > OPEN_MAX || ft_init(ctnt + fd, line) == -1)
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
