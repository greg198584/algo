/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:14:53 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/31 10:35:39 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	ft_init_cycle(t_list *chmp)
{
	chmp->cycle = 10;
	return (1);
}

static void	ft_find_live(t_list *chmp, int val)
{
	t_list	*tmp;

	tmp = chmp;
	tmp->winner = 0;
	if (tmp->root == val)
	{
		tmp->live = 1;
		tmp->last_live = 1;
		tmp->live_for_dump = 1;
	}
	else
	{
		tmp->live = 0;
		tmp->last_live = 0;
		tmp->live_for_dump = 0;
	}
}

int			ft_live(t_list *chmp, unsigned char *mem, int pos)
{
	int	val;

	if (chmp->cycle == 0 && chmp->ret == 0)
		return (-(chmp->ret = ft_init_cycle(chmp)));
	else
		chmp->ret = 0;
	val = ft_check_byte(mem, pos + 2, 2);
	ft_find_live(chmp, val);
	return (LIVE_SIZE);
}
