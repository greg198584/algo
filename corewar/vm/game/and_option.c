/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 17:31:28 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/21 09:54:07 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "and.h"

void		ft_direct(t_list *chmp, unsigned char *mem, int pos, int param)
{
	int	val_direct;
	int	val_reg;

	val_direct = 0;
	val_reg = 0;
	if ((FIRST(mem[pos]) == 2 && TWO(mem[pos]) == 2) || FIRST(mem[pos]) == 3
		|| TWO(mem[pos]) == 3)
		ft_ind_dir(chmp, mem, pos, param);
	else if (TWO(mem[pos]) == 1 && FIRST(mem[pos]) == 2)
	{
		val_direct = ft_check_byte(mem, pos, param - 2);
		val_reg = chmp->reg[mem[pos + DIR_4 + 1] - 1];
		chmp->reg[mem[pos + param] - 1] = val_direct & val_reg;
	}
	else if (FIRST(mem[pos]) == 1 && TWO(mem[pos]) == 2)
	{
		val_reg = chmp->reg[mem[pos + 1] - 1];
		val_direct = ft_check_byte(mem, pos + REG, param - (REG + REG));
		chmp->reg[mem[pos + param] - 1] = val_reg & val_direct;
	}
}

void		ft_indirect(t_list *chmp, unsigned char *mem, int pos, int param)
{
	int	val_ind;
	int	val_reg;
	int	addr;

	val_ind = 0;
	val_reg = 0;
	addr = 0;
	if ((FIRST(mem[pos]) == 3 && TWO(mem[pos]) == 3) || FIRST(mem[pos]) == 2
		|| TWO(mem[pos]) == 2)
		ft_ind_dir(chmp, mem, pos, param);
	else if (TWO(mem[pos]) == 1)
	{
		addr = ft_check_byte(mem, pos, param - 2);
		val_ind = mem[(chmp->pc + (addr % IDX_MOD)) % MEM_SIZE];
		val_reg = chmp->reg[mem[pos + IND + 1] - 1];
		chmp->reg[mem[pos + param] - 1] = val_reg & val_ind;
	}
	else if (FIRST(mem[pos]) == 1)
	{
		val_reg = chmp->reg[mem[pos + 1] - 1];
		addr = ft_check_byte(mem, pos + REG + 1, param - (REG + IND));
		val_ind = mem[(chmp->pc + (addr % IDX_MOD)) % MEM_SIZE];
		chmp->reg[mem[pos + param] - 1] = val_reg & val_ind;
	}
}

void		ft_reg(t_list *chmp, unsigned char *mem, int pos)
{
	int	a;
	int	b;

	a = chmp->reg[mem[pos++] - 1];
	b = chmp->reg[mem[pos++] - 1];
	chmp->reg[mem[pos] - 1] = a & b;
}
