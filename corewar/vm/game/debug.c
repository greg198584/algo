/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <glafitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 07:05:53 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/31 14:28:48 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include <unistd.h>

int	ft_print_dump_debug(t_list *chmp, unsigned char *mem, int pos, t_vm *vm)
{
	if ((vm->debugx && vm->cycle_d <= 0) ||
		(vm->debugx && vm->cycle_total > vm->cycle_d))
		ft_print_debug(chmp, mem, pos, vm);
	return (0);
}

int	ft_print_debug(t_list *champ, unsigned char *mem, int pos, t_vm *vm)
{
	ft_d(champ, mem, pos, vm);
	usleep(40000);
	return (0);
}

int	ft_print_det(t_list *chmp, unsigned char *mem, int pos)
{
	int	param;
	int	i;
	int	pos_mem;

	chmp->val_tmp = 0;
	pos_mem = pos + 1;
	i = -1;
	ft_fprintf(1, "\nChampion executer: --> {%s} <-- Fork [%d]\n",
				chmp->chpm->prog_name, chmp->fork);
	ft_fprintf(1, "\tInstruction (%d)\n", mem[pos]);
	param = ft_check_arg(mem[pos + 1], mem[pos]);
	ft_fprintf(1, "\tnbr octets pour parametre (%d)\n\n", param);
	pos++;
	while (++i < param)
	{
		ft_fprintf(1, "[ Octet [%d] = {%x}]", i + 1, mem[pos++]);
		if (i < param - 1)
			ft_fprintf(1, " && ");
	}
	write(1, "\n", 1);
	chmp->val_tmp = ft_print_param1(chmp, mem, pos_mem);
	chmp->val_tmp += ft_print_param2(chmp, mem, pos_mem);
	ft_print_param3(chmp, mem, pos_mem);
	return (write(1, "\n", 1) - 1);
}
