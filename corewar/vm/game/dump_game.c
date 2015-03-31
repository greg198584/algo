/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 11:25:31 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/30 13:54:44 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>

static void	ft_champ_live(t_list *chmp)
{
	ft_fprintf(1, "\tJoueur [%s] {%d} est en vie\n", chmp->chpm->prog_name,
				chmp->root);
	chmp->live_for_dump = 0;
}

static void	ft_status(t_list *chmp, t_vm *vm)
{
	ft_putstr("[");
	ft_putstr(C_GREEN);
	ft_fprintf(1, "%s - fork [%d]", chmp->chpm->prog_name, chmp->fork);
	ft_putstr(C_NONE);
	ft_putstr("]\n");
	ft_putstr("--> cycle [");
	ft_putstr(C_GREEN);
	ft_fprintf(1, "%d", vm->cycle);
	ft_putstr(C_NONE);
	ft_putstr("] # cycle total [");
	ft_putstr(C_GREEN);
	ft_fprintf(1, "%d", vm->cycle_total);
	ft_putstr(C_NONE);
	ft_putstr("] # cycle_to_die [");
	ft_putstr(C_GREEN);
	ft_fprintf(1, "%d", vm->cycle_to_die);
	ft_putstr(C_NONE);
	ft_putstr("] # live [");
	ft_putstr(C_GREEN);
	ft_fprintf(1, "%d", vm->live);
	ft_putstr(C_NONE);
	ft_putstr("]");
	if (chmp->live_for_dump)
		ft_champ_live(chmp);
}

static void	ft_print_addr(int i)
{
	ft_putstr("\n");
	ft_putstr(C_BROWN);
	ft_display_hexa(i, "0123456789abcdef", 16, 8);
	ft_putstr("\033[m"" : ""\033[0m");
}

void		ft_print_bit(int i, unsigned char *mem, int pos, char *c)
{
	if (i == pos)
		ft_putstr(C_HL_RED);
	else
		ft_putstr(c);
	ft_display_hexa(mem[i], "0123456789abcdef", 16, 1);
	ft_putstr(" ");
	ft_putstr(C_NONE);
}

void		ft_d(t_list *chmp, unsigned char *mem, int pos, t_vm *vm)
{
	t_dump	p;

	ft_init_param(&p);
	system("clear");
	ft_putstr(C_BROWN);
	ft_display_hexa(p.i, "0123456789abcdef", 16, 8);
	ft_putstr("\033[m"" : ""\033[0m");
	while (p.i < MEM_SIZE)
	{
		if (p.i % 64 == 0 && p.i != 0)
			ft_print_addr(p.i);
		if (mem[p.i] == '0' && (ft_isalpha(mem[p.i + 1]) || (mem[p.i + 1] > 0
			&& mem[p.i + 1] <= 9)))
			ft_print_bit(p.i, mem, pos, C_NONE);
		ft_print_cor(mem, pos, vm, &p);
		++p.i;
	}
	ft_putstr("\n");
	ft_status(chmp, vm);
}
