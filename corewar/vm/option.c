/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 14:19:40 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/30 16:13:40 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdlib.h>

void	ft_puterror(char *error)
{
	ft_fprintf(2, "%s\n", error);
	exit(EXIT_FAILURE);
}

void	ft_usage(char *file, int line, char *err)
{
	char	*usage;

	usage = "[ -dump nb ] [-n nb] <champion.cor> <...> <...> <...>";
	ft_fprintf(1, "Usage: ./corewar %s\n", usage);
	ft_fprintf(1, "\t-dump nbr_cycles - mettre sans -d ou -dx\n");
	ft_fprintf(1, "\t-d debug texte info champions et instructions\n");
	ft_fprintf(1, "\t-x debug affichage dump temp reel + couleur champions\n");
	ft_fprintf(1, "\t-n number\n");
	ft_fprintf(1, "4 champions possible.\n");
	ft_fprintf(1, "--------------------------------------------------------\n");
	ft_fprintf(1, "cause erreur : %s\n", err);
	ft_fprintf(1, "%s", file);
	ft_fprintf(1, " at line: ");
	ft_fprintf(1, "%d", line);
	ft_puterror("\nfermeture Corewar.");
}

int		ft_good_path(char *name)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (name[++i] != '\0')
	{
		if (name[i] == '/')
			count++;
	}
	return (count);
}

void	ft_err_loc(char *file, int line, char *msg)
{
	ft_fprintf(2, "cause erreur: %s\n", msg);
	ft_fprintf(2, "%s", file);
	ft_fprintf(2, " at line: ");
	ft_fprintf(2, "%d", line);
	ft_puterror("\nfermerture Corewar.");
}
