/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:20:43 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/31 11:41:38 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdlib.h>

static void	ft_check_n_number(int nb, t_option *opt)
{
	int		a;
	char	*number;
	int		c;
	int		b;

	a = 0;
	b = 0;
	number = ft_int_array(nb);
	if ((c = ft_strlen(number)) > 4)
		ERR_LOC("une de vos valeurs est utilise !");
	opt->ft_n_number = malloc(sizeof(int) * (c + 1));
	while (b < c)
	{
		opt->ft_n_number[b] = number[b] - '0';
		b++;
	}
	opt->ft_n_number[b] = -1;
	ft_chang_nbr(opt, c);
	ft_loop_nbr(a, c, number);
	free(number);
}

static void	ft_check_nbr_2(char *s1, char *s2, t_option *opt, char *st)
{
	int	nb;

	if (ft_strcmp_cr("-n", s1) != 0 && ft_cor(st) == 1)
	{
		nb = ft_atoi(s2);
		if (nb < 1 || nb > 4)
			ERR_LOC("le nombre apres -n doit etre compris entre 1 et 4.");
		if (opt->number_a_id == 0)
			opt->n_number = nb;
		else
			opt->n_number = opt->n_number * 10 + nb;
		opt->number_a_id = opt->number_a_id + 1;
	}
	else
		ERR_LOC("oublie d'un fichier [.cor] valide.");
}

void		ft_check_nbr(char **argv, t_option *opt)
{
	int	i;

	i = 0;
	while (argv[++i] != NULL)
	{
		if (ft_cor(argv[i]) == 1)
		{
			if (i - 2 > 0 && argv[i - 2] != NULL
					&& ft_strcmp_cr("-n", argv[i - 2]) != 0)
				ft_check_nbr_2(argv[i - 2], argv[i - 1], opt, argv[i]);
			else if (i - 4 > 0 && argv[i - 4] != NULL
					&& ft_strcmp_cr("-n", argv[i - 4]) != 0
					&& ft_cor(argv[i - 2]) != 1)
				ft_check_nbr_2(argv[i - 4], argv[i - 3], opt, argv[i]);
			else
			{
				if (opt->number_a_id == 0)
					opt->n_number = 5;
				else
					opt->n_number = opt->n_number * 10 + 5;
				opt->number_a_id = opt->number_a_id + 1;
			}
		}
	}
	ft_check_n_number(opt->n_number, opt);
}

void		ft_after_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		if ((ft_cor(argv[i])) == 1)
			i++;
		else if (argv[i + 1] != NULL && ft_strcmp_cr("-d", argv[i]) != 0)
			i += 2;
		else if (argv[i + 1] != NULL && ft_strcmp_cr("-x", argv[i]) != 0
				&& j++ == 0 && ft_getnbr_p(argv[i + 1]) >= 0)
			i += 2;
		else if (argv[i + 1] != NULL && ft_strcmp_cr("-n", argv[i]) != 0
				&& ft_getnbr_p(argv[i + 1]))
			i += 2;
		else if (argv[i + 1] != NULL && ft_strcmp_cr("-dump", argv[i]) != 0
				&& j++ == 0 && ft_getnbr_p(argv[i + 1]) >= 0)
			i += 2;
		else
			USAGE("caractere NULL apres option ou 0 ou -d ou -x incluse");
	}
}
