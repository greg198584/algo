/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 09:11:06 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/30 12:44:42 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <fcntl.h>

t_list	*ft_parse_vm(t_option *opt, unsigned char *mem, int *nb)
{
	char	**ft_cor;
	int		i;
	int		fd;
	t_list	*champ;

	champ = ft_make_lst();
	i = -1;
	ft_cor = opt->ft_cor;
	while (++i < ft_strlen_arg(ft_cor))
	{
		fd = ft_open(ft_cor[i], O_RDONLY, 0);
		ft_add_before(fd, &champ, i);
	}
	ft_place_champ(opt, champ, mem);
	champ->debug = opt->debug;
	champ->debugx = opt->debugx;
	champ->cycle_d = opt->cycle_d;
	champ->nb_tour = opt->dump;
	champ->root = opt->num_cor;
	champ->winner = 0;
	*nb = i;
	return (champ);
}
