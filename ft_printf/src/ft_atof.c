/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:55:22 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/19 16:20:41 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_epur_str(char *s)
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

double	ft_atof(char *s)
{
	double	a;
	int		e;
	int		c;
	int		sign;

	e = 0;
	a = 0.0;
	sign = ((s = ft_epur_str(s)) && s[0] == '-' && s++ ? -1 : 1);
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
char	*ft_ftoa(double number,int ndigit,char *buf)
{  
	long	int_part;
	double	float_part;
	int		i;
	char	str_int[32];
	char	str_float[32];

	ft_memset(str_int,0,32);
	ft_memset(str_float,0,32);
	int_part = (long)number;
	float_part = number - int_part;
	ft_itoa(int_part, str_int, 10);
	if(ndigit > 0)
	{  
		float_part = ft_abs(ft_pow(10,ndigit)*float_part);
		ft_itoa((long)float_part,str_float,10);
	}
	i = strlen(str_int);
	str_int[i] = '.';
	strcat(str_int,str_float);
	strcpy(buf,str_int);
	return buf;
} 
