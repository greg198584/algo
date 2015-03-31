/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 11:48:17 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/23 08:04:00 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

static	void	ft_second_chk_nbr(char **argv)
{
	int	i;
	int	option;

	option = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		if (argv[i + 2] != NULL && ft_strcmp_cr("-n", argv[i]) != 0
				&& ft_cor(argv[i + 2]) == 1)
			option++;
		else if (argv[i + 4] != NULL && ft_strcmp_cr("-n", argv[i]) != 0
					&& ft_cor(argv[i + 4]) == 1
					&& ft_strcmp_cr("-n", argv[i + 2]) == 0)
			option++;
		else
		{
			if (ft_strcmp_cr("-n", argv[i]) != 0)
				ERR_LOC("Utilisation de -n invalid");
		}
		i++;
	}
}

t_list			*ft_parser(int ar, char **av, unsigned char *mem, int *nb)
{
	t_option	opt;
	t_list		*root;

	if (ar == 1)
		USAGE("Il n'y a pas d'argument.");
	else
	{
		ft_init(&opt);
		ft_after_check(av);
		ft_check_cor(av, &opt);
		ft_second_chk_nbr(av);
		ft_check_debug(av, &opt);
		ft_check_debugx(av, &opt);
		ft_check_dump(av, &opt);
		ft_check_nbr(av, &opt);
	}
	root = ft_parse_vm(&opt, mem, nb);
	ft_freeparser(&opt);
	return (root);
}
