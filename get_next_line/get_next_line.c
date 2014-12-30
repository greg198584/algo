/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:35:51 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/30 22:27:46 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <unistd.h>

int		get_next_line(int const fd, char **line)
{
	static char	*buff;
	char		read_buf[BUFF_SIZE + 1];
	char		*tmp;
	int			r;

	while (!ft_strchr(buff, '\n') && line)
	{
		if ((r = read(fd, read_buf, BUFF_SIZE)) < 1)
			break ;
		read_buf[r] = 0;
		buff = (!buff) ? ft_strdup(read_buf) : ft_strjoin(buff, read_buf);
	}
	if ((tmp = ft_strchr(buff, '\n')) != NULL && line)
	{
		*line = buff;
		buff = tmp + 1;
		*tmp = '\0';
		return (1);
	}
	else if (line)
		*line = buff;
	return ((!line) ? -1 : r);
}
