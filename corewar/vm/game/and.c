/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:14:19 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/28 11:23:28 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "and.h"

int			ft_and(t_list *chmp, unsigned char *mem, int pos)
{
	int	nb_param;

	if (chmp->cycle == 0 && chmp->ret == 0)
	{
		chmp->cycle = 6;
		chmp->ret = 1;
		return (-1);
	}
	else
		chmp->ret = 0;
	nb_param = ft_check_arg(mem[pos + 1], mem[pos]);
	if (nb_param == 3)
		ft_reg(chmp, mem, pos + 2);
	else if (nb_param == 4 || nb_param == 5)
		ft_indirect(chmp, mem, pos + 1, nb_param);
	else if (nb_param == 7 || nb_param == 9 || nb_param == 6)
		ft_direct(chmp, mem, pos + 1, nb_param);
	chmp->carry = ft_carry(chmp->reg[mem[pos + nb_param + 1] - 1]);
	return (nb_param + 1);
}