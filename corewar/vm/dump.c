/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 15:18:11 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/30 16:14:38 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ft_check_dump(char **argv, t_option *opt)
{
	int			i;
	int			dump;
	static int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		if (ft_strcmp_cr("-dump", argv[i]) != 0 && argv[i + 1] != NULL)
		{
			dump = ft_atoi(argv[i + 1]);
			if (dump <= 0)
				dump = 0;
			opt->dump = dump;
			j = 2;
		}
		else if (j == 0)
			opt->dump = -1;
		i++;
	}
	return (0);
}

int	ft_check_debug(char **argv, t_option *opt)
{
	int			i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (ft_strcmp_cr("-d", argv[i]) != 0 && argv[i + 1] != NULL)
			opt->debug = 1;
		i++;
	}
	return (0);
}

int	ft_check_debugx(char **argv, t_option *opt)
{
	int			i;
	int			cycle;
	static	int	j;

	cycle = 0;
	i = 0;
	while (argv[i] != NULL)
	{
		if (ft_strcmp_cr("-x", argv[i]) != 0 && argv[i + 1] != NULL)
		{
			opt->debugx = 1;
			cycle = ft_atoi(argv[i + 1]);
			if (cycle <= 0)
				cycle = 0;
			opt->cycle_d = cycle;
			j = 2;
		}
		else if (j == 0)
			opt->cycle_d = -1;
		i++;
	}
	return (0);
}
