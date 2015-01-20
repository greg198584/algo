/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:55:22 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/20 10:59:50 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	char	*ft_epur_str(char *s)
{
	int		i;
	char	*ret;

	if (!s || ft_strlen(s) == 0)
		return (s);
	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s) + 1));
	s = ft_strrep(s, "\t", " ", 0);
	while (*s)
	{
		if (i > 0 && ret[i - 1] == ' ')
		{
			if (*s && *s != ' ' && *s != '\t' && (ret[i] = *s))
				i++;
		}
		else if ((ret[i] = *s))
			i++;
		s++;
	}
	ret[i] = 0;
	ret[i - 1] = (ret[i - 1] == ' ' ? 0 : ret[i - 1]);
	ret = (ret[0] == ' ' ? ret + 1 : ret);
	return (ret);
}

double			ft_atof(char *s)
{
	double	a;
	int		e;
	int		c;
	int		sign;

	e = 0;
	a = 0.0;
	s = ft_epur_str(s);
	sign = (s && s[0] == '-' && s++ ? -1 : 1);
	while ((c = *s++) != '\0' && ft_isdigit(c))
		a = a * 10.0 + (c - '0');
	if (c == '.')
		while ((c = *s++) != '\0' && ft_isdigit(c))
		{
			a = a * 10.0 + (c - '0');
			e = e - 1;
		}
	while (e > 0)
	{
		a *= 10.0;
		e--;
	}
	while (e++ < 0)
		a *= 0.1;
	return (a * sign);
}
