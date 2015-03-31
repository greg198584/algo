/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <glafitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 08:26:46 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/31 13:19:26 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>

static void	ft_last_live(t_list *chmp, t_vm *vm)
{
	if (chmp->live > 0)
		vm->last_live_chmp = chmp->root;
	else
		vm->last_live_chmp = 0;
}

int			ft_instr(t_list *champ, unsigned char *mem, t_vm *vm)
{
	int			pos;
	int			i;
	int			tmp;
	static int	flag;

	pos = champ->pc % MEM_SIZE;
	i = -1;
	ft_print_dump_debug(champ, mem, pos, vm);
	if ((ft_cycle(champ)) == -1)
		return (0);
	while (g_opt_tab[++i].code != 0x00)
	{
		if (g_opt_tab[i].code == mem[pos])
		{
			if ((tmp = ft_check_instr(champ, pos, mem, vm->debug)) == -1)
				break ;
			pos += tmp + 1;
			champ->pc = (pos % MEM_SIZE);
			i = -1;
			flag = -1;
		}
		flag++;
	}
	flag = ft_check_flag(champ, flag);
	return (champ->live);
}

int			ft_game(unsigned char *mem, t_list *root, int nb)
{
	t_list	*champ;
	t_vm	vm;

	ft_init_vm(&vm, nb, root);
	while (1)
	{
		champ = g_head_sv->next;
		while (champ != g_head_sv)
		{
			if (champ->winner != -1 && champ->root != 0)
			{
				vm.live += ft_instr(champ, mem, &vm);
				ft_last_live(champ, &vm);
			}
			champ = champ->next;
		}
		if ((ft_verif_cycle(&vm)) == -1)
			return (0);
		if (vm.cycle_total >= vm.nb_tour && vm.nb_tour > 0)
			return (ft_print_mem(mem, 0, root));
		vm.cycle_total++;
		vm.cycle++;
	}
	return (0);
}
