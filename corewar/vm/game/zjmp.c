/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:15:25 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/30 12:03:59 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	ft_zjmp_pos_n(t_list *chmp, int addr)
{
	int	diff;
	int	pos;

	diff = 0;
	if (chmp->pc + addr < 0)
	{
		diff = (chmp->pc + (addr % IDX_MOD) % MEM_SIZE);
		pos = MEM_SIZE;
		chmp->pc = (pos + diff) % MEM_SIZE;
	}
	else
	{
		pos = chmp->pc;
		chmp->pc = ((pos + (addr % IDX_MOD)) % MEM_SIZE);
	}
	return (0);
}

int			ft_zjmp(t_list *chmp, unsigned char *mem, int pos)
{
	int	pos_mem;

	if (chmp->cycle == 0 && chmp->ret == 0)
	{
		chmp->cycle = 20;
		chmp->ret = 1;
		return (-1);
	}
	else
		chmp->ret = 0;
	if (chmp->carry == 1)
	{
		pos_mem = ft_check_byte(mem, pos, 2);
		if (pos_mem > 0)
			chmp->pc += pos_mem % MEM_SIZE;
		else if (pos_mem < 0)
			ft_zjmp_pos_n(chmp, pos_mem);
		return (-1);
	}
	return (ZJMP_SIZE);
}
