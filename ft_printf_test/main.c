/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 14:09:14 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/21 11:41:00 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_usage(void)
{
	ft_putendl("=================== USAGE ==================");
	ft_putendl("indiquer les options a tester");
	ft_putendl("{ TEST } chiffre int\t\t: d & i = 1");
	ft_putendl("{ TEST } unsigned int\t\t: D & u = 2");
	ft_putendl("{ TEST } adresse variable\t: p = 3");
	ft_putendl("{ TEST } chaine de caractere\t: s = 4");
	ft_putendl("{ TEST } caractere\t\t: c = 5");
	ft_putendl("{ TEST } les flags\t\t:  -> 6");
	ft_putendl("{ TEST } la precision\t\t:  -> 7");
	ft_putendl("{ TEST } Hexa mini\t\t: x = 8");
	ft_putendl("{ TEST } Hexa max\t\t: X = 9");
	ft_putendl("{ TEST } octal int\t\t: o = 10");
	ft_putendl("{ TEST } octal unsigned int\t: O = 11");
	ft_putendl("{ TEST } long int\t\t: U = 12");
	ft_putendl("{ TEST } unint caractere\t: C = 13");
	ft_putendl("{ TEST } largeur de champs");
	ft_putendl("----> hh | h | l | ll | j | z\t: --> 14");
	ft_putendl("{ TEST } option S\t\t: --> 15");
	ft_putendl("{ TEST } nombre de caractere lu\t: --> 16");
}

int		main(int argc, char **argv)
{
	int				value;
	unsigned int	count;
	int				i;
	int				fd;
	int				b;
	unsigned int	d;
	char			*str = "coucou tous le monde, ß∂åß¬¬øœ∑´…¬ƒ∆˚˚åß";
	char			c;
	char			*line;
	char			*filename = "test.c";

	if (argc < 2)
		ft_usage();
	ft_putendl("============================================");
	ft_printf("Indiquer votre option a tester : ");
	scanf("%d", &value);
	switch (value)
	{
		case 1:
		{
			ft_putstr("entrez une valeur a tester pour option d et i : ");
			scanf("%d", &b);
			ft_putstr("\nJusau'a : ");
			scanf("%d", &count);
			ft_option_d(b, count);
			break ;
		}
		case 2:
		{
			ft_putstr("entrez une valeur a tester pour option D et u : ");
			scanf("%d", &i);
			ft_putstr("\nJusau'a : ");
			scanf("%d", &b);
			ft_option_bigd(i, b);
			break ;
		}
		case 3:
		{
			ft_putendl("\n[Test de 4 adresses ]");
			ft_putendl("\n- char chaine");
			ft_putendl("\n- 2 int");
			ft_putendl("\n- char");
			ft_putendl("\n- unsigned int");
			ft_option_ptr();
			break ;
		}
		case 4:
		{
			ft_putendl("\nTest d'une chaine de caractere (str)");
			ft_putendl("Test de l'affichage d'un fichier\n");
			ft_option_str(str, filename);
			break ;
		}
		case 5:
		{
			ft_option_char();
			break ;
		}
		case 6:
		{
			ft_flag_options();
			break ;
		}
		case 7:
		{
			ft_precision();
			break ;
		}
		case 8:
		{
			ft_hexa_min();
			break ;
		}
		case 9:
		{
			ft_hexa_max();
			break ;
		}
		case 10:
		{
			ft_octal_int();
			break ;
		}
		case 11:
		{
			ft_octal_unint();
			break ;
		}
		case 12:
		{
			ft_long_int();
			break ;
		}
		case 13:
		{
			ft_option_charunint();
			break ;
		}
		case 14:
		{
			ft_option_champlarge();
			break ;
		}
		case 15:
		{
			ft_option_big_s();
			break ;
		}
		case 16:
		{
			ft_option_len();
			break ;
		}
		default :
		{
			ft_putendl("Vous n'avez pas donner une option valide");
			return (0);
		}

	}
	return (0);
}
