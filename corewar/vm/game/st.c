/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:15:10 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/30 13:40:26 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	ft_fill_n(t_list *chmp, unsigned char *mem, int addr, int value)
{
	int	diff;
	int	pos;

	diff = 0;
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
		mem[((pos + (addr % IDX_MOD)) % MEM_SIZE)] = OCT_1(value);
		mem[((pos + (addr % IDX_MOD) + 1) % MEM_SIZE)] = OCT_2(value);
		mem[((pos + (addr % IDX_MOD) + 2) % MEM_SIZE)] = OCT_3(value);
		mem[((pos + (addr % IDX_MOD) + 3) % MEM_SIZE)] = OCT_4(value);
	}
	return (0);
}

static int	ft_fill(t_list *chmp, unsigned char *mem, int addr, int value)
{
	int	pos;

	pos = chmp->pc;
	mem[((pos + (addr % IDX_MOD)) % MEM_SIZE)] = OCT_1(value);
	mem[((pos + (addr % IDX_MOD) + 1) % MEM_SIZE)] = OCT_2(value);
	mem[((pos + (addr % IDX_MOD) + 2) % MEM_SIZE)] = OCT_3(value);
	mem[((pos + (addr % IDX_MOD) + 3) % MEM_SIZE)] = OCT_4(value);
	return (0);
}

static void	ft_st_reg(t_list *chmp, unsigned char *mem, int pos, int param)
{
	int	value;

	value = chmp->reg[mem[pos + 2] - 1];
	chmp->reg[mem[pos + param] - 1] = value;
}

static int	ft_init_cycle(t_list *chmp)
{
	chmp->cycle = 5;
	return (1);
}

int			ft_st(t_list *chmp, unsigned char *mem, int pos)
{
	int	nb_param;
	int	value;
	int	addr;

	if (chmp->cycle == 0 && chmp->ret == 0)
		return (-(chmp->ret = ft_init_cycle(chmp)));
	else
		chmp->ret = 0;
	nb_param = ft_check_arg(mem[pos + 1], mem[pos]);
	if (nb_param == 3)
	{
		value = chmp->reg[mem[pos + 2] - 1];
		addr = ft_check_byte(mem, pos + 2, nb_param - 1);
		if (addr > 0)
			ft_fill(chmp, mem, addr, value);
		else if (addr < 0)
			ft_fill_n(chmp, mem, addr, value);
	}
	else
		ft_st_reg(chmp, mem, pos, nb_param);
	return (nb_param + 1);
}
