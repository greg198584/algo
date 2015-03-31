/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:14:23 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/31 13:20:26 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork.h"

static int	ft_fork_pos_n(t_list *chmp, int addr)
{
	int	diff;
	int	pos;

	diff = 0;
	if (chmp->pc + addr < 0)
	{
		diff = (chmp->pc + addr);
		pos = MEM_SIZE;
		return (pos + diff);
	}
	else
		return ((chmp->pc + addr));
	return (0);
}

static int	ft_init_cycle(t_list *chmp, int cycle)
{
	chmp->cycle = cycle;
	return (1);
}

int			ft_fork(t_list *chmp, unsigned char *mem, int pos)
{
	int	pos_mem;

	if (chmp->cycle == 0 && chmp->ret == 0)
		return (-(chmp->ret = ft_init_cycle(chmp, 800)));
	else
		chmp->ret = 0;
	pos_mem = ft_check_byte(mem, pos, 2);
	if (pos_mem > 0)
		pos_mem = chmp->pc + (pos_mem % IDX_MOD);
	else if (pos_mem < 0)
		pos_mem = ft_fork_pos_n(chmp, (pos_mem % IDX_MOD));
	ft_append_to_champ(&chmp, pos_mem);
	return (FORK_SIZE);
}

int			ft_lfork(t_list *chmp, unsigned char *mem, int pos)
{
	int	pos_mem;

	if (chmp->cycle == 0 && chmp->ret == 0)
		return (-(chmp->ret = ft_init_cycle(chmp, 1000)));
	else
		chmp->ret = 0;
	pos_mem = ft_check_byte(mem, pos, 2);
	if (pos_mem < 0)
		pos_mem = ft_fork_pos_n(chmp, pos_mem);
	else
		pos_mem = (chmp->pc + pos_mem);
	ft_append_to_champ(&chmp, pos_mem);
	return (LFORK_SIZE);
}
