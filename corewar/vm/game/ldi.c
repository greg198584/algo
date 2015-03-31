/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:14:44 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/28 11:23:57 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ldi.h"

int	ft_ldi(t_list *chmp, unsigned char *mem, int pos)
{
	int	nb_param;

	if (chmp->cycle == 0 && chmp->ret == 0)
	{
		chmp->cycle = 25;
		chmp->ret = 1;
		return (-1);
	}
	else
		chmp->ret = 0;
	nb_param = ft_check_arg(mem[pos + 1], mem[pos]);
	if (nb_param == 3)
		ft_reg_ldi(chmp, mem, pos + 2);
	else if (nb_param == 4)
		ft_reg_ind_dir(chmp, mem, pos + 1, nb_param);
	else if (nb_param == 5)
		ft_id_ldi(chmp, mem, pos + 1, nb_param);
	return (nb_param + 1);
}
