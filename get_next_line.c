/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:39:06 by cdana             #+#    #+#             */
/*   Updated: 2019/12/26 12:43:04 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	static char		*ctnt[1024];
	char			buff[BUFFER_SIZE + 1];
	int				ret;

	if (fd < 0 || fd > 1024 || line == 0)
		return (-1);
	if (ctnt[fd] == 0 && (ctnt[fd] = malloc(1)) > 0)
		ctnt[fd][0] = 0;
	while (ctnt[fd][slen(ctnt[fd], '\n')] != '\n' &&
			(ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = 0;
		if (merge(ctnt + fd, buff) == -1)
			return (-1);
	}
	if (cpynshift(ctnt[fd], line) == -1)
		return (-1);
	if (ctnt[fd][0] == 0 && (ret = read(fd, buff, 1)) == 1)
	{
		ctnt[fd][0] = buff[0];
		ctnt[fd][1] = 0;
	}
	if (ctnt[fd][0] == 0 && ret == 0)
		free(ctnt[fd]);
	return (ret > 0);
}
