/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 12:12:15 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/30 13:50:53 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdlib.h>

int			main(int argc, char **argv)
{
	unsigned char	*vm_mem;
	t_list			*root;
	int				nb;

	vm_mem = ft_init_mem();
	root = ft_parser(argc, argv, vm_mem, &nb);
	ft_game(vm_mem, root, nb);
	free(vm_mem);
	return (0);
}
