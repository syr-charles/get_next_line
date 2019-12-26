/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:46:18 by cdana             #+#    #+#             */
/*   Updated: 2019/11/30 15:50:29 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		slen(char *s, char p)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != p)
		i++;
	return (i);
}

int		merge(char **dest, char *right)
{
	int		i;
	int		j;
	char	*out;

	if (!(out = malloc(slen(*dest, 0) + slen(right, 0) + 1)))
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

int		cpynshift(char *ctnt, char **line)
{
	int		i;
	int		j;

	if (!(*line = malloc(slen(ctnt, '\n') + 1)))
		return (-1);
	i = 0;
	while (i < slen(ctnt, '\n'))
	{
		(*line)[i] = ctnt[i];
		i++;
	}
	(*line)[i] = 0;
	if (ctnt[i] == '\n')
		i++;
	j = 0;
	while (ctnt[i + j])
	{
		ctnt[j] = ctnt[i + j];
		j++;
	}
	ctnt[j] = 0;
	return (1);
}
