/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 16:49:48 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/21 12:39:39 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sti.h"
#include "init_variables.h"

static int	ft_sti_ind(t_list *chmp, unsigned char *mem, int pos, int param)
{
	int	value;
	int	addr;

	addr = ft_check_byte(mem, pos, param);
	value = mem[chmp->pc + addr];
	return (value);
}

void		ft_id_reg_sti(t_list *chmp, unsigned char *mem, int pos, int param)
{
	int	a;
	int	b;
	int addr;

	ft_init_var_3(&a, &b, &addr);
	if (TWO(mem[pos]) == 1)
	{
		a = chmp->reg[mem[pos + 2] - 1];
		b = ft_check_byte(mem, pos + 2, 2);
	}
	else if (LAST(mem[pos]) == 1)
	{
		if (TWO(mem[pos]) == 2)
			a = ft_check_byte(mem, pos + 1, 2);
		else if (TWO(mem[pos]) == 3)
			a = ft_sti_ind(chmp, mem, pos + 1, 2);
		b = chmp->reg[mem[pos + param] - 1];
	}
	addr = a + b;
	if (addr > 0)
		ft_fill_sti(chmp, mem, addr, chmp->reg[mem[pos + 1]]);
	else if (addr < 0)
		ft_fill_sti_n(chmp, mem, addr, chmp->reg[mem[pos + 1]]);
}

void		ft_id_sti(t_list *chmp, unsigned char *mem, int pos)
{
	int	a;
	int	b;
	int	addr;

	ft_init_var_3(&a, &b, &addr);
	if (TWO(mem[pos]) == 2)
		a = ft_check_byte(mem, pos + 1, 2);
	else if (TWO(mem[pos]) == 3)
		a = ft_sti_ind(chmp, mem, pos + 1, 2);
	b = ft_check_byte(mem, pos + 3, 2);
	addr = a + b;
	if (addr > 0)
		ft_fill_sti(chmp, mem, addr, chmp->reg[mem[pos + 1] - 1]);
	else if (addr < 0)
		ft_fill_sti_n(chmp, mem, addr, chmp->reg[mem[pos + 1] - 1]);
}

void		ft_reg_sti(t_list *chmp, unsigned char *mem, int pos)
{
	int	a;
	int	b;
	int	addr;

	a = chmp->reg[mem[pos + 1] - 1];
	b = chmp->reg[mem[pos + 2] - 1];
	addr = a + b;
	if (addr > 0)
		ft_fill_sti(chmp, mem, addr, chmp->reg[mem[pos] - 1]);
	else if (addr < 0)
		ft_fill_sti_n(chmp, mem, addr, chmp->reg[mem[pos] - 1]);
}
