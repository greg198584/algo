/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:39:40 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/19 17:06:58 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

static int			ft_ftoi(float n)
{
	return ((int)(n));
}

static unsigned int	ft_nbrlen(int nbr)
{
	int		ret;

	ret = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		ret = 1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		ret++;
	}
	return (ret);
}
static char			*ft_ftoa_cut(float n, char *s)
{
	int	index;
	int	i;

	if (ft_strlen(s) - ft_nbrlen(ft_ftoi(n)) > 6)
		s[ft_strlen(s) - 1] = '\0';
	while (n > ft_atof(s))
		s[ft_strlen(s) - 1] += 1;
	while (n < ft_atof(s))
		s[ft_strlen(s) - 1] -= 1;
	index = 0;
	while (s[index] && s[index] != '.')
		index++;
	i = 0;
	while (s[i + index])
		i++;
	while (i++ <= 6)
		ft_strjoin(s, ft_char_to_str('0'));
	ft_putendl(s);
	return (s);

}

static char			*ft_ftoa_next(float n, char *s)
{
	int		f;
	int		p;
	char	*str;
	char	*tmp;

	ft_strjoin(s, ft_char_to_str('.'));
	p = ft_ftoi((n - ft_ftoi(n)) * MAX_FTOA);
	if (p == 0)
		return (ft_ftoa_cut(n, s));
	f = ft_nbrlen(p);
	while (f++ < 7)
		ft_strjoin(s, ft_char_to_str('0'));
	str = ft_itoa(p);
	tmp = ft_strjoin(s, str);
	ft_strdel(&s);
	s = ft_strdup(tmp);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (ft_ftoa_cut(n, s));
}

char				*ft_ftoa(float n)
{
	char	*s;

	if (n == 0)
		return (ft_strdup("0"));
	if		 (n < 1)
		return (ft_ftoa_next(n, ft_strdup("0")));
	s = ft_itoa(ft_ftoi(n));
	if (s == NULL)
		return (NULL);
	return (ft_ftoa_next(n, s));
}
