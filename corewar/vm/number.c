/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 09:00:19 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/06 10:34:47 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_loop_nbr(int a, int c, char *num)
{
	char	tmp;
	int		b;

	b = 0;
	while (a < c)
	{
		tmp = num[a];
		b = a + 1;
		while (b < c)
		{
			if (tmp == num[b] && tmp != '5')
				ERR_LOC("une de vos valeurs est utilise !");
			b++;
		}
		a++;
	}
}

void	ft_chang_nbr(t_option *opt, int c)
{
	int	a;
	int	d;
	int	b;

	a = 0;
	while (a < c)
	{
		if (opt->ft_n_number[a] == 5)
		{
			b = 0;
			d = 1;
			while (b < c)
			{
				if (opt->ft_n_number[b] == d && b != a)
				{
					b = 0;
					d++;
				}
				else
					b++;
			}
			opt->ft_n_number[a] = d;
		}
		a++;
	}
}
