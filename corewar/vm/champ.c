/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 09:20:34 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/30 21:51:39 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>

static int	ft_header_or_not(int fd)
{
	int				nbr;
	int				i;
	unsigned char	car[4];

	i = 0;
	nbr = 0;
	ft_read(fd, car, 4);
	while (i < 4)
		nbr = (nbr << 8) + car[i++];
	return (nbr);
}

void		ft_add_before(int fd, t_list **lst, int i)
{
	t_list	*elem;

	elem = malloc(sizeof(*elem));
	elem->root = -(i + 1);
	elem->ret = 0;
	elem->cycle = 0;
	elem->live_for_dump = 0;
	elem->carry = 0;
	elem->live = 0;
	elem->fork_nb = 0;
	elem->reg[0] = elem->root;
	elem->chpm = malloc(sizeof(t_header));
	elem->chpm->magic = ft_header_or_not(fd);
	if (elem->chpm->magic != COREWAR_EXEC_MAGIC)
		ERR_LOC("ce n'est pas un fichier [ .cor ]");
	ft_read(fd, elem->chpm->prog_name, PROG_NAME_LENGTH);
	ft_lseek(fd, 8 + PROG_NAME_LENGTH, SEEK_SET);
	if ((elem->chpm->prog_size = ft_header_or_not(fd)) > (MEM_SIZE / 6))
		ERR_LOC("taille programme trop grande !");
	ft_lseek(fd, 12 + PROG_NAME_LENGTH, SEEK_SET);
	ft_read(fd, elem->chpm->comment, COMMENT_LENGTH);
	elem->next = (*lst);
	elem->prev = (*lst)->prev;
	(*lst)->prev->next = elem;
	(*lst)->prev = elem;
}

t_list		*ft_make_lst(void)
{
	t_list	*root;

	if ((root = malloc(sizeof(t_list))) != NULL)
	{
		root->root = 0;
		root->prev = root;
		root->next = root;
	}
	else
		return (NULL);
	return (root);
}
