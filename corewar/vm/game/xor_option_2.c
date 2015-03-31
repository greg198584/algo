/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor_option_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 07:49:17 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/21 22:02:04 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "or.h"
#include "init_variables.h"

static void	ft_id_eg_xor(t_list *chmp, unsigned char *mem, int pos, int param)
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
		chmp->reg[mem[pos + param] - 1] = value1 ^ value2;
	}
	else if (FIRST(mem[pos]) == 3 && TWO(mem[pos]) == 3)
	{
		addr_1 = ft_check_byte(mem, pos, 2);
		value1 = mem[(chmp->pc + (addr_1 % IDX_MOD)) % MEM_SIZE];
		addr_2 = ft_check_byte(mem, pos + 2, 2);
		value2 = mem[(chmp->pc + (addr_2 % IDX_MOD)) % MEM_SIZE];
		chmp->reg[mem[pos + param] - 1] = value1 ^ value2;
	}
}

void		ft_ind_dir_xor(t_list *chmp, unsigned char *mem, int pos, int param)
{
	int	val_ind;
	int	val_direct;
	int	addr;

	ft_init_var_3(&val_ind, &val_direct, &addr);
	if ((FIRST(mem[pos]) == 2 && TWO(mem[pos]) == 2) || (FIRST(mem[pos]) == 3 &&
		TWO(mem[pos]) == 3))
		ft_id_eg_xor(chmp, mem, pos, param);
	else if (FIRST(mem[pos]) == 2 && TWO(mem[pos]) == 3)
	{
		val_direct = ft_check_byte(mem, pos + 2, 2);
		addr = ft_check_byte(mem, pos + 5, 1);
		val_ind = mem[(chmp->pc + (addr % IDX_MOD)) % MEM_SIZE];
		chmp->reg[mem[pos + param] - 1] = val_direct ^ val_ind;
	}
	else if (TWO(mem[pos]) == 2 && FIRST(mem[pos]) == 3)
	{
		addr = ft_check_byte(mem, pos, 2);
		val_direct = ft_check_byte(mem, pos + 4, 2);
		val_ind = mem[(chmp->pc + (addr % IDX_MOD)) % MEM_SIZE];
		chmp->reg[mem[pos + param] - 1] = val_direct ^ val_ind;
	}
}
