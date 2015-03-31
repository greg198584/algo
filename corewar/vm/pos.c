/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 10:40:31 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/23 10:54:27 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_place_champ(t_option *opt, t_list *root, unsigned char *mem)
{
	int		i;
	t_list	*champion;

	i = -1;
	champion = root->next;
	while (++i < opt->num_cor)
	{
		ft_code_in_mem(mem, opt->ft_cor[i], MEM_SIZE * i /
							opt->num_cor);
		champion->init_pos = MEM_SIZE * i / opt->num_cor;
		champion->pc = MEM_SIZE * i / opt->num_cor;
		champion = champion->next;
	}
}
