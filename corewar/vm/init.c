/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 10:45:12 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/28 16:11:18 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdlib.h>

void			ft_init(t_option *opt)
{
	opt->n_number = 0;
	opt->option = 0;
	opt->number_for_n = 0;
	opt->addr_a_id = 0;
	opt->number_a_id = 0;
	opt->debug = 0;
	opt->debugx = 0;
	opt->cycle_d = 0;
}

unsigned char	*ft_init_mem(void)
{
	int				i;
	unsigned char	*mem;

	i = -1;
	mem = malloc(MEM_SIZE);
	while (++i < MEM_SIZE)
		mem[i] = 0;
	return (mem);
}

char			*ft_int_array(int nbr)
{
	int		i;
	int		count;
	int		tmp;
	char	*arr;

	count = 1;
	tmp = nbr;
	while (tmp > 9)
	{
		tmp /= 10;
		++count;
	}
	arr = malloc(sizeof(char) * (count + 1));
	i = count;
	while (nbr > 9)
	{
		arr[--i] = nbr % 10 + '0';
		nbr /= 10;
	}
	arr[--i] = nbr + '0';
	arr[count] = '\0';
	return (arr);
}
