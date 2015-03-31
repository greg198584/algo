/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_option_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:10:04 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/23 11:13:15 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "or.h"
#include "init_variables.h"

static void	ft_ind_dir_eg(t_list *chmp, unsigned char *mem, int pos, int param)
{
	int	value1;
	int	value2;
	int	addr_1;
	int	addr_2;

	ft_init_var_4(&value1, &value2, &addr_1, &addr_2);
	if (FIRST(mem[pos]) == 2 && TWO(mem[pos]) == 2)
	{
		value1 = ft_check_byte(mem, pos + 2, 2);
		value2 = ft_check_byte(mem, pos + 6, 2);
		chmp->reg[mem[pos + param] - 1] = value1 | value2;
	}
	else if (FIRST(mem[pos]) == 3 && TWO(mem[pos]) == 3)
	{
		addr_1 = ft_check_byte(mem, pos, param - (IND + REG));
		value1 = mem[(chmp->pc + (addr_1 % IDX_MOD)) % MEM_SIZE];
		addr_2 = ft_check_byte(mem, pos, param - (IND + REG));
		value2 = mem[(chmp->pc + (addr_2 % IDX_MOD)) % MEM_SIZE];
		chmp->reg[mem[pos + param] - 1] = value1 | value2;
	}
}

void		ft_ind_dir_or(t_list *chmp, unsigned char *mem, int pos, int param)
{
	int	val_ind;
	int	val_direct;
	int	addr;

	val_ind = 0;
	val_direct = 0;
	addr = 0;
	if ((FIRST(mem[pos]) == 2 && TWO(mem[pos]) == 2) || (FIRST(mem[pos]) == 3 &&
		TWO(mem[pos]) == 3))
		ft_ind_dir_eg(chmp, mem, pos, param);
	else if (FIRST(mem[pos]) == 2 && TWO(mem[pos]) == 3)
	{
		val_direct = ft_check_byte(mem, pos + 2, 2);
		addr = ft_check_byte(mem, pos + 5, 1);
		val_ind = mem[(chmp->pc + (addr % IDX_MOD)) % MEM_SIZE];
		chmp->reg[mem[pos + param] - 1] = val_direct | val_ind;
	}
	else if (TWO(mem[pos]) == 2 && FIRST(mem[pos]) == 3)
	{
		addr = ft_check_byte(mem, pos, 2);
		val_direct = ft_check_byte(mem, pos + 4, 2);
		val_ind = mem[(chmp->pc + (addr % IDX_MOD)) % MEM_SIZE];
		chmp->reg[mem[pos + param] - 1] = val_direct | val_ind;
	}
}
