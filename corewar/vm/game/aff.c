/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:14:12 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/31 11:16:43 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <unistd.h>

int	ft_aff(t_list *chmp, unsigned char *mem, int pos)
{
	int	nb_param;
	int	val;

	if (chmp->cycle == 0 && chmp->ret == 0)
	{
		chmp->cycle = 2;
		chmp->ret = 1;
		return (-1);
	}
	else
		chmp->ret = 0;
	nb_param = ft_check_arg(mem[pos + 1], mem[pos]);
	val = chmp->reg[mem[pos + 2] - 1];
	if (ft_isalpha(val))
		ft_putchar(val);
	return (nb_param + 1);
}
