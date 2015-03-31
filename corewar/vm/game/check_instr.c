/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 13:05:26 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/31 11:10:59 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

t_instr g_tab_instr[] =
{
	{&ft_live, 0x01},
	{&ft_ld, 0x02},
	{&ft_st, 0x03},
	{&ft_add, 0x04},
	{&ft_sub, 0x05},
	{&ft_and, 0x06},
	{&ft_or, 0x07},
	{&ft_xor, 0x08},
	{&ft_zjmp, 0x09},
	{&ft_ldi, 0x0a},
	{&ft_sti, 0x0b},
	{&ft_fork, 0x0c},
	{&ft_lld, 0x0d},
	{&ft_lldi, 0x0e},
	{&ft_lfork, 0x0f},
	{&ft_aff, 0x10},
	{NULL, -1}
};

int	ft_check_instr(t_list *chmp, int pos, unsigned char *mem, int debug)
{
	int	i;

	i = -1;
	while (g_tab_instr[++i].instr != -1)
	{
		if (g_tab_instr[i].instr == mem[pos])
		{
			if (debug)
				ft_print_det(chmp, mem, pos);
			return (g_tab_instr[i].func_ptr(chmp, mem, pos));
		}
	}
	return (-1);
}

int	ft_check_flag(t_list *chmp, int flag)
{
	if (flag == 16)
		chmp->pc = ((chmp->pc + 1) % MEM_SIZE);
	return (0);
}
