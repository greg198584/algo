/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:44:31 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/21 08:37:06 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ldi.h"
#include "init_variables.h"

static void	ft_ri_ldi(t_list *chmp, unsigned char *mem, int pos, int param)
{
	int	a;
	int	b;
	int	addr;
	int	value;

	ft_init_var_4(&a, &b, &addr, &value);
	if (FIRST(mem[pos]) == 3 && TWO(mem[pos]) == 1)
	{
		addr = ft_check_byte(mem, pos, param - (REG + REG));
		a = mem[chmp->pc + (addr % IDX_MOD)];
		b = chmp->reg[mem[pos + IND + 1] - 1];
		addr = a + b;
		value = mem[chmp->pc + (addr % IDX_MOD)];
		chmp->reg[mem[pos + param] - 1] = value;
	}
	else if (FIRST(mem[pos]) == 1 && TWO(mem[pos]) == 3)
	{
		a = chmp->reg[mem[pos + 1] - 1];
		addr = ft_check_byte(mem, pos, param - (REG + IND));
		b = mem[chmp->pc + (addr % IDX_MOD)];
		addr = a + b;
		value = mem[chmp->pc + (addr % IDX_MOD)];
		chmp->reg[mem[pos + param] - 1] = value;
	}
}

static void	ft_dir_egal(t_list *chmp, unsigned char *mem, int pos, int param)
{
	int	a;
	int	b;
	int	addr;
	int value;

	a = ft_check_byte(mem, pos, param - (DIR_2 + REG));
	b = ft_check_byte(mem, pos + DIR_2, param - (DIR_2 + REG));
	addr = a + b;
	value = mem[chmp->pc + ((addr % IDX_MOD) % MEM_SIZE)];
	chmp->reg[mem[pos + param] - 1] = value;
}

void		ft_id_ldi(t_list *chmp, unsigned char *mem, int pos, int param)
{
	int	a;
	int	b;
	int	addr;
	int	value;

	ft_init_var_4(&a, &b, &addr, &value);
	if (FIRST(mem[pos]) == 2 && TWO(mem[pos]) == 2)
		ft_dir_egal(chmp, mem, pos, param);
	else if (FIRST(mem[pos]) == 3 && TWO(mem[pos]) == 2)
	{
		addr = ft_check_byte(mem, pos, param - (DIR_2 + REG));
		a = ft_check_byte(mem, pos + IND, param - (REG + IND));
		b = mem[chmp->pc + ((addr % IDX_MOD) % MEM_SIZE)];
		addr = a + b;
		value = mem[chmp->pc + ((addr % IDX_MOD) % MEM_SIZE)];
		chmp->reg[mem[pos + param] - 1] = value;
	}
}

void		ft_reg_ind_dir(t_list *chmp, unsigned char *mem, int pos, int param)
{
	int	a;
	int	b;
	int	addr;
	int	value;

	ft_init_var_4(&a, &b, &addr, &value);
	if (FIRST(mem[pos]) == 3 || TWO(mem[pos]) == 3)
		ft_ri_ldi(chmp, mem, pos, param);
	else if (FIRST(mem[pos]) == 2 && TWO(mem[pos]) == 1)
	{
		a = ft_check_byte(mem, pos, param - (REG + REG));
		b = chmp->reg[mem[pos + 2] - 1];
		addr = a + b;
		value = mem[chmp->pc + ((addr % IDX_MOD) % MEM_SIZE)];
		chmp->reg[mem[pos + param] - 1] = value;
	}
	else if (FIRST(mem[pos]) == 1 && TWO(mem[pos]) == 2)
	{
		a = chmp->reg[mem[pos + 1] - 1];
		b = ft_check_byte(mem, pos + 1, 2);
		addr = a + b;
		value = mem[chmp->pc + ((addr % IDX_MOD) % MEM_SIZE)];
		chmp->reg[mem[pos + param] - 1] = value;
	}
}

void		ft_reg_ldi(t_list *chmp, unsigned char *mem, int pos)
{
	int	a;
	int	b;
	int	addr;
	int	value;

	a = chmp->reg[mem[pos] - 1];
	b = chmp->reg[mem[pos + 1] - 1];
	addr = a + b;
	value = mem[chmp->pc + ((addr % IDX_MOD) % MEM_SIZE)];
	chmp->reg[mem[pos + 2] - 1] = value;
}
