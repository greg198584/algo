/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:14:58 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/30 08:47:39 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_lld(t_list *chmp, unsigned char *mem, int pos)
{
	int	param;
	int	addr;
	int	val;

	if (chmp->cycle == 0 && chmp->ret == 0)
	{
		chmp->cycle = 10;
		chmp->ret = 1;
		return (-1);
	}
	else
		chmp->ret = 0;
	param = ft_check_arg(mem[pos + 1], mem[pos]);
	if (FIRST(mem[pos + 1]) == 3)
	{
		addr = ft_check_byte(mem, pos + 1, 2);
		val = mem[(chmp->pc + addr) % MEM_SIZE];
	}
	else
		val = ft_check_byte(mem, pos, param);
	chmp->reg[mem[pos + param + 1] - 1] = val;
	chmp->carry = ft_carry(chmp->reg[mem[pos + param + 1] - 1]);
	return (param + 1);
}
