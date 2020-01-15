/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:13:37 by cdana             #+#    #+#             */
/*   Updated: 2020/01/15 18:16:22 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
