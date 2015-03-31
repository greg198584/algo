/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:54:39 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/30 13:54:58 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_init_param(t_dump *param)
{
	param->j = 0;
	param->cor = 0;
	param->end = 0;
	param->i = 0;
}

void	ft_print_cor(unsigned char *mem, int pos, t_vm *vm, t_dump *p)
{
	if (p->i == vm->tab[p->j])
	{
		p->end = 0;
		p->cor++;
		p->j++;
	}
	if (p->cor == 1 && p->end == 0)
		p->color = C_CYAN;
	else if (p->cor == 2 && p->end == 0)
		p->color = C_GREEN;
	else if (p->cor == 3 && p->end == 0)
		p->color = C_BLINK;
	else if (p->cor == 4 && p->end == 0)
		p->color = C_MAGENTA;
	if (p->i == (vm->tab[p->j - 1] + vm->size[p->j - 1]))
		p->end = 1;
	if (p->end)
		p->color = C_GRAY;
	ft_print_bit(p->i, mem, pos, p->color);
}
