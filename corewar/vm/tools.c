/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:29:23 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/14 15:30:19 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <fcntl.h>
#include <unistd.h>

char	ft_strcmp_cr(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		++i;
	return (s1[i] == s2[i] && s1[i] == '\0');
}

int		ft_strlen_arg(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int		ft_cor(char *str)
{
	return (ft_strcmp_cr(".cor", str + ft_strlen(str) - 4));
}

int		ft_read(int fd, void *buf, size_t count)
{
	int	len;

	if ((len = read(fd, buf, count)) == -1)
		ERR_LOC("Error : read failure");
	return (len);
}

int		ft_open(char const *pathname, int flags, mode_t mode)
{
	int	fd;

	if ((fd = open(pathname, flags, mode)) == -1)
	{
		ft_fprintf(1, "%s\n", pathname);
		ERR_LOC("non accessible");
	}
	return (fd);
}
