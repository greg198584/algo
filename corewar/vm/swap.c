/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 10:27:28 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/19 16:50:09 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_swap_initchar(int max, int min, t_option *opt)
{
	int		tmp;
	char	*cor;

	tmp = opt->ft_n_number[max];
	opt->ft_n_number[max] = opt->ft_n_number[min];
	opt->ft_n_number[min] = tmp;
	cor = opt->ft_cor[max];
	opt->ft_cor[max] = opt->ft_cor[min];
	opt->ft_cor[min] = cor;
}
