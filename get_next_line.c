/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:12:14 by cdana             #+#    #+#             */
/*   Updated: 2020/01/15 18:12:19 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	static char		*ctnt[OPEN_MAX];
	int				ret;

	if (fd < 0 || !line || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
	if (ctnt[fd] == NULL)
	{
		if (!(ctnt[fd] = malloc(1)))
			return (-1);
		ctnt[fd][0] = '\0';
	}
	if (ft_read(fd, ctnt) == -1)
		return (-1);
	if ((ret = ft_cpy_shift(ctnt + fd, line)) == 0)
	{
		free(ctnt[fd]);
		ctnt[fd] = NULL;
	}
	return (ret);
}
