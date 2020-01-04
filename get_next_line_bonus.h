/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 12:41:32 by cdana             #+#    #+#             */
/*   Updated: 2020/01/04 13:52:29 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
int		ft_merge(char **dest, char *buff);
int		ft_cpy_shift(char **ctnt, char **line);
int		ft_read(int fd, char **ctnt);
#endif
