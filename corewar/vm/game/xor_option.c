/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 07:39:05 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/21 19:00:55 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xor.h"
#include "init_variables.h"

void		ft_dir_xor(t_list *chmp, unsigned char *mem, int pos, int param)
{
	int	val_direct;
	int	val_reg;

	val_direct = 0;
	val_reg = 0;
	if ((FIRST(mem[pos]) == 2 && TWO(mem[pos]) == 2) || FIRST(mem[pos]) == 3
		|| TWO(mem[pos]) == 3)
		ft_ind_dir_xor(chmp, mem, pos, param);
	else if (TWO(mem[pos]) == 1 && FIRST(mem[pos]) == 2)
	{
		val_direct = ft_check_byte(mem, pos, param - 2);
		val_reg = chmp->reg[mem[pos + DIR_4 + 1] - 1];
		chmp->reg[mem[pos + param] - 1] = val_direct ^ val_reg;
	}
	else if (FIRST(mem[pos]) == 1 && TWO(mem[pos]) == 2)
	{
		val_reg = chmp->reg[mem[pos + 1] - 1];
		val_direct = ft_check_byte(mem, pos + REG, param - (REG + REG));
		chmp->reg[mem[pos + param] - 1] = val_reg ^ val_direct;
	}
}

void		ft_indir_xor(t_list *chmp, unsigned char *mem, int pos, int param)
{
	int	val_ind;
	int	val_reg;
	int	addr;

	ft_init_var_3(&val_ind, &val_reg, &addr);
	if ((FIRST(mem[pos]) == 3 && TWO(mem[pos]) == 3) || FIRST(mem[pos]) == 2
		|| TWO(mem[pos]) == 2)
		ft_ind_dir_xor(chmp, mem, pos, param);
	else if (TWO(mem[pos]) == 1)
	{
		addr = ft_check_byte(mem, pos, param - 2);
		val_ind = mem[((chmp->pc + (addr % IDX_MOD)) % MEM_SIZE)];
		val_reg = chmp->reg[mem[pos + IND + 1] - 1];
		chmp->reg[mem[pos + param] - 1] = val_reg ^ val_ind;
	}
	else if (FIRST(mem[pos]) == 1)
	{
		val_reg = chmp->reg[mem[pos + 1] - 1];
		addr = ft_check_byte(mem, pos + REG + 1, param - (REG + IND));
		val_ind = mem[((chmp->pc + (addr % IDX_MOD)) % MEM_SIZE)];
		chmp->reg[mem[pos + param] - 1] = val_reg ^ val_ind;
	}
}

void		ft_reg_xor(t_list *chmp, unsigned char *mem, int pos)
{
	int	a;
	int	b;

	a = chmp->reg[mem[pos++] - 1];
	b = chmp->reg[mem[pos++] - 1];
	chmp->reg[mem[pos] - 1] = a ^ b;
}
