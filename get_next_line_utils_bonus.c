/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 12:05:05 by cdana             #+#    #+#             */
/*   Updated: 2019/12/31 12:05:08 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	slen(char *s, char p)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != p)
		i++;
	return (i);
}

int			ft_merge(char **dest, char *right)
{
	int		i;
	int		j;
	char	*out;

	if (!(out = malloc(slen(*dest, '\0') + slen(right, '\0') + 1)))
		return (-1);
	i = 0;
	while ((*dest)[i])
	{
		out[i] = (*dest)[i];
		i++;
	}
	j = 0;
	while (right[j])
	{
		out[i + j] = right[j];
		j++;
	}
	out[i + j] = 0;
	free(*dest);
	*dest = out;
	return (1);
}

static int	ft_line_counter(char *s)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}

int			ft_read(int fd, char **ctnt)
{
	int		ret;
	char	buff[BUFFER_SIZE + 1];

	ret = 0;
	while (ft_line_counter(ctnt[fd]) < 2 && (ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = 0;
		if (ft_merge(ctnt + fd, buff) == -1)
			return (-1);
	}
	if (ret < 0)
		return (-1);
	return (1);
}

int			ft_cpy_shift(char **ctnt, char **line)
{
	int		i;
	int		j;

	free(*line);
	if (!(*line = malloc(slen(*ctnt, '\n') + 1)))
		return (-1);
	i = 0;
	while ((*ctnt)[i] && (*ctnt)[i] != '\n')
	{
		(*line)[i] = (*ctnt)[i];
		i++;
	}
	(*line)[i] = 0;
	if ((*ctnt)[i] == '\n')
		i++;
	j = 0;
	while ((*ctnt)[i + j])
	{
		(*ctnt)[j] = (*ctnt)[i + j];
		j++;
	}
	(*ctnt)[j] = 0;
	return (1);
}