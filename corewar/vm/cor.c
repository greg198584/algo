/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 17:45:23 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/21 12:56:19 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdlib.h>

static int	ft_count_cor(char **av)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (av[a] != NULL)
	{
		if ((ft_cor(av[a])) == 1)
			b++;
		a++;
	}
	if (b < 1 || b > 4)
		ERR_LOC("besoin entre 1 et 4 [ .cor ] valide");
	return (b);
}

int			ft_check_cor(char **av, t_option *opt)
{
	int	a;
	int	b;
	int	d;
	int	e;

	a = 0;
	b = 0;
	d = 0;
	e = ft_count_cor(av);
	opt->ft_cor = malloc(sizeof(char*) * (e + 1));
	while (av[a] != NULL)
	{
		if ((ft_cor(av[a])) == 1)
		{
			opt->ft_cor[d++] = av[a];
			b++;
		}
		a++;
	}
	opt->ft_cor[d] = NULL;
	opt->num_cor = b;
	if (opt->num_cor < 1 || opt->num_cor > 4)
		ERR_LOC("besoin entre 1 et 4 [ .cor ] valid");
	return (0);
}
