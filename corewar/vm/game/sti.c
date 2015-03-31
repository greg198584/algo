/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:15:14 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/31 11:01:26 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sti.h"

void	ft_fill_sti_n(t_list *chmp, unsigned char *mem, int addr, int value)
{
	int	diff;
	int	pos;

	diff = 0;
	pos = 0;
	if (chmp->pc + addr < 0)
	{
		diff = (chmp->pc + (addr % IDX_MOD) % MEM_SIZE);
		pos = MEM_SIZE;
		mem[(pos + diff)] = OCT_1(value);
		mem[(pos + diff) + 1] = OCT_2(value);
		mem[(pos + diff) + 2] = OCT_3(value);
		mem[(pos + diff) + 3] = OCT_4(value);
	}
	else
	{
		pos = chmp->pc;
		mem[(pos + (addr % IDX_MOD) % MEM_SIZE)] = OCT_1(value);
		mem[((pos + (addr % IDX_MOD) + 1) % MEM_SIZE)] = OCT_2(value);
		mem[((pos + (addr % IDX_MOD) + 2) % MEM_SIZE)] = OCT_3(value);
		mem[((pos + (addr % IDX_MOD) + 3) % MEM_SIZE)] = OCT_4(value);
	}
}

void	ft_fill_sti(t_list *chmp, unsigned char *mem, int addr, int value)
{
	int	pos;

	pos = chmp->pc;
	mem[((pos + (addr % IDX_MOD)) % MEM_SIZE)] = OCT_1(value);
	mem[((pos + (addr % IDX_MOD) + 1) % MEM_SIZE)] = OCT_2(value);
	mem[((pos + (addr % IDX_MOD) + 2) % MEM_SIZE)] = OCT_3(value);
	mem[((pos + (addr % IDX_MOD) + 3) % MEM_SIZE)] = OCT_4(value);
}

int		ft_sti(t_list *chmp, unsigned char *mem, int pos)
{
	int	nb_param;

	if (chmp->cycle == 0 && chmp->ret == 0)
	{
		chmp->cycle = 25;
		chmp->ret = 1;
		return (-1);
	}
	else
		chmp->ret = 0;
	nb_param = ft_check_arg(mem[pos + 1], mem[pos]);
	if (nb_param == 3)
		ft_reg_sti(chmp, mem, pos + 2);
	else if (nb_param == 5)
		ft_id_sti(chmp, mem, pos + 1);
	else if (nb_param == 4)
		ft_id_reg_sti(chmp, mem, pos + 1, nb_param);
	return (nb_param + 1);
}
