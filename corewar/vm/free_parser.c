/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:20:49 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/19 16:44:16 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "stdlib.h"

void	ft_freeparser(t_option *opt)
{
	free(opt->ft_n_number);
	free(opt->ft_cor);
}
