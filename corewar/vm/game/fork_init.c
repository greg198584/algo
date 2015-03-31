/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 19:55:25 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/31 13:08:39 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork.h"
#include <stdlib.h>
#include <unistd.h>

t_list	*ft_copy_int_tab(int reg[REG_NUMBER], t_list *new)
{
	int	i;

	i = 0;
	while (i != REG_NUMBER)
	{
		new->reg[i] = reg[i];
		i++;
	}
	return (new);
}

void	ft_append_to_champ(t_list **chmp, int pos)
{
	t_list		*new_proc;

	(*chmp)->fork_nb += 1;
	if ((new_proc = malloc(sizeof(*new_proc))) == NULL)
		ERR_LOC("Erreur: allocation memoire");
	new_proc->pc = pos % MEM_SIZE;
	new_proc->root = (*chmp)->root;
	new_proc->init_pos = new_proc->pc;
	new_proc = ft_copy_int_tab((*chmp)->reg, new_proc);
	new_proc->root = (*chmp)->root;
	new_proc->winner = 1;
	new_proc->live = 1;
	new_proc->live_for_dump = (*chmp)->live_for_dump;
	new_proc->cycle = 0;
	new_proc->fork = (*chmp)->fork_nb;
	new_proc->carry = (*chmp)->carry;
	new_proc->chpm = (*chmp)->chpm;
	while ((*chmp) != g_head_sv && (*chmp)->root != 0)
		(*chmp) = (*chmp)->next;
	new_proc->next = (*chmp)->next;
	new_proc->prev = (*chmp);
	(*chmp)->next = new_proc;
}
