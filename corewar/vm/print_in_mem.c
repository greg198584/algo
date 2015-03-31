/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 14:42:37 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/30 13:52:45 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_display_hexa(int nbr, const char *base, const int size, int zero)
{
	if (nbr < size)
	{
		while (zero-- > 0)
			ft_putchar('0');
		ft_putchar(base[nbr]);
	}
	else
	{
		ft_display_hexa(nbr / size, base, size, --zero);
		ft_putchar(base[(nbr) % size]);
	}
}

void	ft_lseek(const int fd, off_t offset, int whence)
{
	if (lseek(fd, offset, whence) == -1)
		ERR_LOC("problem avec lseek!\n");
}

int		ft_print_mem(unsigned char *mem, int i, t_list *root)
{
	ft_putstr(C_BROWN);
	ft_display_hexa(i, "0123456789abcdef", 16, 8);
	ft_putstr("\033[m"" : ""\033[0m");
	while (i < MEM_SIZE)
	{
		if (i % 32 == 0 && i != 0)
		{
			ft_putstr("\n");
			ft_putstr(C_BROWN);
			ft_display_hexa(i, "0123456789abcdef", 16, 8);
			ft_putstr("\033[m"" : ""\033[0m");
		}
		if (mem[i] == '0' && (ft_isalpha(mem[i + 1]) || (mem[i + 1] > 0
			&& mem[i + 1] <= 9)))
			ft_putstr(C_GREEN);
		ft_putstr(C_CYAN);
		ft_display_hexa(mem[i], "0123456789abcdef", 16, 1);
		ft_putstr(" ");
		ft_putstr(C_NONE);
		++i;
	}
	ft_putstr("\n");
	return (ft_result(root));
}

void	ft_code_in_mem(unsigned char *mem, char *cor, int pos)
{
	char	buff[8];
	int		fd;
	int		i;
	int		j;

	j = pos;
	if ((fd = open(cor, O_RDONLY, 0)) == -1)
		ERR_LOC(ft_strjoin("ouverture impossible du fichier --> ", cor));
	ft_lseek(fd, 16 + PROG_NAME_LENGTH + COMMENT_LENGTH, SEEK_SET);
	while (read(fd, buff, 8))
	{
		i = 0;
		while (i < 8)
			mem[j++] = buff[i++];
	}
	j = -1;
	if (close(fd) == -1)
		ERR_LOC(ft_strjoin("fermeture du fichier --> ", cor));
}
