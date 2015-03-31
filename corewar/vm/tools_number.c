/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 17:06:04 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/07 15:00:05 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ft_getnbr_p(const char *str)
{
	int	i;
	int	nbr;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			ERR_LOC("ceci n'est pas un chiffre [ 0 - 9]");
	}
	i = -1;
	nbr = 0;
	while (str[++i] && nbr >= 0)
		nbr = nbr * 10 + (str[i] - '0');
	return (nbr);
}
