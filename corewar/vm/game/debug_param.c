/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <glafitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 12:13:16 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/23 09:42:41 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include <stdlib.h>

static int	ft_error_param(int opt, unsigned char *mem, int pos)
{
	if (opt == 1)
		ft_fprintf(1, "E: Parametre non conforme --> numero de retour = [%d]\n",
					FIRST(mem[pos]));
	else if (opt == 2)
		ft_fprintf(1, "E: Parametre non conforme --> numero de retour = [%d]\n",
					TWO(mem[pos]));
	else if (opt == 3)
		ft_fprintf(1, "E: Parametre non conforme --> numero de retour = [%d]\n",
					LAST(mem[pos]));
	return (0);
}

int			ft_print_param1(t_list *chmp, unsigned char *mem, int pos)
{
	int	value;

	value = 0;
	ft_fprintf(1, "\n{{ 1er Parametre }}\n");
	if (FIRST(mem[pos]) == 1)
	{
		ft_fprintf(1, "REG = [%d]\n", chmp->reg[mem[pos + 1] - 1]);
		return (1);
	}
	else if (FIRST(mem[pos]) == 2)
	{
		value = ft_check_byte(mem, pos + 1, 2);
		ft_fprintf(1, "DIRECT 2octet en cas = [%d]\n", value);
		value = ft_check_byte(mem, pos + 1, 4);
		ft_fprintf(1, "DIRECT 4octet en cas = [%d]\n", value);
		return (4);
	}
	else if (FIRST(mem[pos]) == 3)
	{
		value = ft_check_byte(mem, pos, 2);
		ft_fprintf(1, "INDIRECT 2octet en cas = [%d]\n", value);
		return (2);
	}
	else
		return (ft_error_param(1, mem, pos));
}

int			ft_print_param2(t_list *chmp, unsigned char *mem, int pos)
{
	int	value;

	value = 0;
	ft_fprintf(1, "\n{{ 2ieme Parametre }}\n");
	if (TWO(mem[pos]) == 1)
	{
		ft_fprintf(1, "REG = [%d]\n", chmp->reg[mem[pos + chmp->val_tmp] - 1]);
		return (1);
	}
	else if (TWO(mem[pos]) == 2)
	{
		value = ft_check_byte(mem, pos + chmp->val_tmp, 2);
		ft_fprintf(1, "DIRECT 2octet en cas = [%d]\n", value);
		value = ft_check_byte(mem, pos + chmp->val_tmp, 4);
		ft_fprintf(1, "DIRECT 4octet en cas = [%d]\n", value);
		return (4);
	}
	else if (TWO(mem[pos]) == 3)
	{
		value = ft_check_byte(mem, pos + chmp->val_tmp, 2);
		ft_fprintf(1, "INDIRECT 2octet en cas = [%d]\n", value);
		return (2);
	}
	else
		return (ft_error_param(2, mem, pos));
}

int			ft_print_param3(t_list *chmp, unsigned char *mem, int pos)
{
	int	value;

	value = 0;
	ft_fprintf(1, "\n{{ 3ieme Parametre }}\n");
	if (LAST(mem[pos]) == 1)
	{
		ft_fprintf(1, "REG = [%d]\n", chmp->reg[mem[pos + chmp->val_tmp] - 1]);
		return (1);
	}
	else if (LAST(mem[pos]) == 2)
	{
		value = ft_check_byte(mem, pos + (chmp->val_tmp - 2), 3);
		ft_fprintf(1, "DIRECT 2octet en cas = [%d]\n", value);
		value = ft_check_byte(mem, pos + chmp->val_tmp - 2, 4);
		ft_fprintf(1, "DIRECT 4octet en cas = [%d]\n", value);
		return (4);
	}
	else if (LAST(mem[pos]) == 3)
	{
		value = ft_check_byte(mem, pos + chmp->val_tmp - 2, 2);
		ft_fprintf(1, "INDIRECT 2octet en cas = [%d]\n", value);
		return (2);
	}
	else
		return (ft_error_param(3, mem, pos));
}
