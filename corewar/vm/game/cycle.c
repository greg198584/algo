/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:01:47 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/31 15:01:34 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h>

int	ft_manage(t_vm *vm)
{
	static int	ret;
	int			val;

	val = 0;
	if (vm->cycle_to_die <= 0)
		return (ft_winner(vm));
	val = ft_check_game(vm);
	if (vm->live >= NBR_LIVE)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->live = 0;
		ret = 0;
	}
	else
		ret++;
	if ((val == 1 || val == 0) && vm->nb_chmp > 1)
		return (ft_winner(vm));
	if (ret >= MAX_CHECKS)
	{
		ret = 0;
		vm->cycle_to_die -= CYCLE_DELTA;
	}
	return (0);
}

int	ft_verif_cycle(t_vm *vm)
{
	if (vm->cycle >= CYCLE_TO_DIE)
	{
		vm->cycle = 0;
		if ((ft_manage(vm)) == -1)
			return (-1);
	}
	return (0);
}

int	ft_cycle(t_list *champ)
{
	if (champ->cycle > 0 && champ->ret != 0)
		champ->cycle--;
	else if (champ->cycle <= 0)
	{
		champ->cycle = 0;
		return (0);
	}
	return (-1);
}
