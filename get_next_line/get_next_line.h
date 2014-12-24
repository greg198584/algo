/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:35:56 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/12 10:04:04 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# define BUFF_SIZE 1

typedef struct	s_param
{
	int				fd;
	char			*buff;
	struct	s_param	*next;
}					t_param;

int	get_next_line(int const fd, char **line);

#endif
