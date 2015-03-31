/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 09:56:02 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/31 15:13:25 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>

static void	ft_last_winner(t_vm *vm)
{
	t_list	*tmp;
	int		nb_winner;

	nb_winner = 0;
	tmp = g_head_sv->next;
	while (tmp != g_head_sv)
	{
		if (tmp->root == vm->last_live_chmp)
		{
			vm->last_live_chmp = 0;
			ft_fprintf(1, "Last live: Le joueur %d (%s) a gagne !\n",
						tmp->root, tmp->chpm->prog_name);
			nb_winner++;
		}
		tmp = tmp->next;
	}
	if (!nb_winner)
		ft_fprintf(1, "Aucune gagnant\n");
}

int			ft_winner(t_vm *vm)
{
	t_list	*tmp;
	int		tmp_nb;
	int		nb_winner;

	nb_winner = 0;
	tmp_nb = 0;
	tmp = g_head_sv->next;
	while (tmp != g_head_sv)
	{
		if (tmp->winner == 1 && tmp->root != tmp_nb)
		{
			tmp_nb = tmp->root;
			ft_fprintf(1, "Le joueur %d (%s) a gagne !\n",
						tmp->root, tmp->chpm->prog_name);
			nb_winner++;
		}
		tmp = tmp->next;
	}
	if (nb_winner == 0)
		ft_last_winner(vm);
	return (-1);
}

int			ft_check_game(t_vm *vm)
{
	t_list	*tmp;
	int		nb_live;

	nb_live = 0;
	tmp = g_head_sv->next;
	if (vm->nb_chmp < 2)
		return ((tmp->winner = 3));
	while (tmp != g_head_sv)
	{
		if (tmp->live > 0)
		{
			nb_live++;
			tmp->live = 0;
			tmp->winner = 1;
		}
		else if (tmp->winner != -1)
			tmp->winner = -1;
		tmp = tmp->next;
	}
	return (nb_live);
}

void		ft_init_vm(t_vm *vm, int nb, t_list *chmp)
{
	t_list	*tmp;
	int		i;

	i = 0;
	g_head_sv = chmp;
	tmp = chmp->next;
	vm->last_live_chmp = 0;
	vm->debugx = chmp->debugx;
	vm->debug = chmp->debug;
	vm->cycle_d = chmp->cycle_d;
	vm->cycle = 0;
	vm->live = 0;
	vm->cycle_total = 0;
	vm->nb_tour = chmp->nb_tour;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->nb_chmp = nb;
	while (tmp != chmp)
	{
		vm->tab[i] = tmp->init_pos;
		vm->size[i] = tmp->chpm->prog_size;
		tmp = tmp->next;
		i++;
	}
}
