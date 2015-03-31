/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:46:18 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/24 09:32:05 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ft_result(t_list *root)
{
	t_list	*lst;
	int		i;

	i = -1;
	lst = root->next;
	while (lst != root)
	{
		ft_fprintf(1, "-------------------- RESULTAT ----------------------\n");
		ft_fprintf(1, "root\t\t--> [%d]\n", lst->root);
		ft_fprintf(1, "fork\t\t--> [%d]\n", lst->fork);
		ft_fprintf(1, "init_pos\t--> [%d]\n", lst->init_pos);
		ft_fprintf(1, "pc\t\t--> [%d]\n", lst->pc);
		ft_fprintf(1, "carry\t\t--> [%d]\n", lst->carry);
		ft_fprintf(1, "cycle\t\t-->  [%d]\n", lst->cycle);
		ft_fprintf(1, "live\t\t--> [%d]\n", lst->live);
		ft_fprintf(1, "fork\t\t--> [%d]\n", lst->fork_nb);
		ft_fprintf(1, "prog_name\t--> [%s]\n", lst->chpm->prog_name);
		ft_fprintf(1, "prog_size\t--> [%d]\n", lst->chpm->prog_size);
		ft_fprintf(1, "comment\t\t--> [%s]\n", lst->chpm->comment);
		while (++i < REG_NUMBER)
			ft_fprintf(1, "REG [%d] -->\t[%d]\n", i + 1, lst->reg[i]);
		i = -1;
		lst = lst->next;
	}
	return (0);
}
