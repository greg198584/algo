/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:14:09 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/28 11:23:13 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	ft_init_cycle(t_list *chmp)
{
	if (chmp->cycle == 0 && chmp->ret == 0)
	{
		chmp->cycle = 10;
		chmp->ret = 1;
		return (-1);
	}
	else
		chmp->ret = 0;
	return (0);
}

int			ft_add(t_list *chmp, unsigned char *mem, int pos)
{
	int	nb_param;
	int	a;
	int	b;
	int	c;

	if ((ft_init_cycle(chmp)) == -1)
		return (-1);
	nb_param = ft_check_arg(mem[pos + 1], mem[pos]);
	a = chmp->reg[mem[pos + 2] - 1];
	b = chmp->reg[mem[pos + 3] - 1];
	c = a + b;
	chmp->reg[mem[pos + 4] - 1] = c;
	chmp->carry = ft_carry(chmp->reg[mem[pos + 4] - 1]);
	return (nb_param + 1);
}
